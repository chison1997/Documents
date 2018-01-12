#include "def.h"

int numThread = 0;
CRITICAL_SECTION CriticalSection;
vector<in_addr> blockList;

bool exitFlag = 0;

DWORD WINAPI ClientThread(LPVOID lpParam);

DWORD WINAPI ControlThread(LPVOID lpParam);


int main(int argc, char** argv)
{
	
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);
	blockList.reserve(16);
	vector<in_addr>::iterator it;
	
	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(80);

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	
	
	if (! InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
		return 0;
	
	
	CreateThread(0, 0, ControlThread, NULL, 0, 0);

	listen(listener, 64);
	
	while(exitFlag == 0)
	{	
		//printf("Num thread: %d\n", numThread);	
		if (numThread < 64)
		
		{
		CLIENT* c = new CLIENT;
		int addrLen = sizeof(SOCKADDR);

		SOCKET Client = accept(listener, (SOCKADDR*) &(c->addr), &addrLen);
		
		vector<in_addr>::iterator it ;
		it = std::find(blockList.begin(), blockList.end(), c->addr.sin_addr);
			
		if (it != blockList.end())
		{
			closesocket(Client);
			continue;
		}
		
		c->clientSocket = Client;
		
	//	printf("Client Connected:%d\n",Client);
		
		//printf("Create thread\n");
		numThread++;
		CreateThread(0, 0, ClientThread, c, 0, 0);
		
		}
	}
	
	closesocket(listener);

	WSACleanup();
	DeleteCriticalSection(&CriticalSection);
    
	return 0;
}


DWORD WINAPI ClientThread(LPVOID lpParam)
{
	CLIENT* c = ((CLIENT*) lpParam);
	writeLog(c);
	
	fd_set set;
	timeval timeout;
	FD_ZERO(&set);
	FD_SET(c->clientSocket, &set);
	timeout.tv_sec = 2000;
	timeout.tv_usec = 0;
	int res =  select(c->clientSocket + 1, &set, NULL, NULL, &timeout);
	
	//int res = recvTimeout(c->clientSocket, 1500);

	if (res != 0 && res != SOCKET_ERROR)
	{
	
		char* buf = new char[BUF_SIZE];
		res = recv(c->clientSocket, buf, BUF_SIZE, 0);
		
		if (res != 0 && res != SOCKET_ERROR)
		{	
			REQUEST* rq = parseRequest(buf);
			if (rq == NULL)
				goto close;

			switch(rq->m)
			{
				case (GET):
					get(rq, c);
					break;
				case (POST):
					post(rq, buf, res, c);
					break;
				case (PUT):
					put(rq, buf, res, c);
					break;
				case (HEAD):
					head(rq, c);
					break;
				case (OPTIONS):
					options(rq, c);
					break;
				}
				
		close:
			free(rq);
			delete buf;
		}
	}
	
	
	
	closesocket(c->clientSocket);
	delete c;
	numThread--;
}

DWORD WINAPI ControlThread(LPVOID lpParam)
{
	char buf[128], cmd[16], arg1[32], arg2[32];
	
	in_addr a;
	FILE* f = fopen("block.txt", "r");
	if (f != NULL)
	{
		int n;
		fscanf(f, "%d", &n);
		for(int i = 0; i < n; i++)
		{
			fscanf(f, "%s", buf);
			a.s_addr = inet_addr(buf);
			blockList.push_back(a);
		}
	}
	fclose(f);
	
	showMenu();
	
	while(exitFlag == 0)
	{
		printf(">>");
		gets(buf);
		sscanf(buf, "%s %s %s", cmd, arg1, arg2);
	
		if (strcmp(cmd, "ShowNumThread") == 0)
		{
			int s = atoi(arg1) * 1000;
			int f = atoi(arg2);
			if (f == 0)
				f = 5;
			for(int i = 0; i < s; i += 1000/f)
			{
				printf("%d\n", numThread);
				delay(1000/f);
			}
		}
		else if (strcmp(cmd, "ShowBlockList") == 0)
		{
			if (blockList.size() == 0)
				printf("Null\n");
			else
			{
				for(vector<in_addr>::iterator it = blockList.begin(); it != blockList.end(); it++)
				{
				
					printf("%s\n", inet_ntoa(*it));
				}
			}
		}
		else if (strcmp(cmd, "Block") == 0)
		{
			if (strlen(arg1) == 0)
				continue;
			
			a.s_addr = inet_addr(arg1);
			blockList.push_back(a);
			
			f = fopen("block.txt", "w");
			fprintf(f, "%d\n", blockList.size());
			for(vector<in_addr>::iterator it = blockList.begin(); it != blockList.end(); it++)
				{
				
					fprintf(f, "%s\n", inet_ntoa(*it));
				}
			fclose(f);
		
		}
		else if (strcmp(cmd, "UnBlock") == 0)
		{
			if (strlen(arg1) == 0)
			{
				printf("Clear\n");
				blockList.clear();
			}
			else
			{
				a.s_addr = inet_addr(arg1);
			
				vector<in_addr>::iterator it = find(blockList.begin(), blockList.end(), a);
				if (it != blockList.end())
				{
					blockList.erase(it);
				}
			}
			
			f = fopen("block.txt", "w");
			fprintf(f, "%d\n", blockList.size());
			for(vector<in_addr>::iterator it = blockList.begin(); it != blockList.end(); it++)
				{
				
					fprintf(f, "%s\n", inet_ntoa(*it));
				}
			fclose(f);
			
		}
		else if(strcmp(cmd, "ShowMenu") == 0)
		{
			showMenu();
		}
		else if(strcmp(cmd, "Exit") == 0)
		{
			exitFlag = 1;
			break;
		}
		else
		{
			system(buf);
			if (strcmp(cmd, "cls") == 0)
				showMenu();
			
		}
	}
	
}
