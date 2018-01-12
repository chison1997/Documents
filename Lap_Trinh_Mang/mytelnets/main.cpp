//mytelnets
//@author VCS

#include <stdio.h>
#include <winsock2.h>
#include <ctype.h>

#define INFO_NODE_SIZE 256

struct node{
	int size;
	char* info[INFO_NODE_SIZE];
	node* next;
};

node* userPass[36] = {NULL};
CRITICAL_SECTION CriticalSection;

DWORD WINAPI ClientThread(LPVOID lpParams);

void readFileUser()
{
	FILE* f = fopen("userPass.txt", "r");
	char buf[256];
	node* p;
	int index;
	while( ! feof(f))
	{
		fgets(buf, 256, f);
		buf[strlen(buf) - 1] = 0; 
		if (isdigit(buf[0]))
		{
			index = buf[0] - '0';
		}
		else
		{
			index = tolower(buf[0]) - 'a' + 10;
		}
		
		p = userPass[index];
		
		if (p == NULL || p->size == 256)
		{
			userPass[index] = new node();
			userPass[index]->size = 0;
			userPass[index]->next = p;
			p = userPass[index];
		}
		
		(p->info)[p->size] = new char[strlen(buf) + 1];
		strcpy((p->info)[p->size], buf);
		(p->size)++;
	}
	
	fclose(f);
}

bool check(char* buf)
{	
	node* p;
	if (isdigit(buf[0]))
	{
		p = userPass[buf[0] - '0'];
	}
	else
	{
		p = userPass[tolower(buf[0]) - 'a' + 10];
	}
	
	while (p != NULL)
	{
		for(int i = 0; i < p->size; i++)
		{
			if ( strcmp( (p->info)[i], buf) == 0)
				return 1;
		}
		p = p->next;
	}
	
	return 0;
}

int main(int argc, char** argv)
{
	if (argc != 2 || atoi(argv[1]) == 0)
	{
		printf("Tham so khong hop le\n");
		return 0;
	}	
	readFileUser();
	
	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) == SOCKET_ERROR)
	{
		return 0;
	}

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(atoi(argv[1]));

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);
	printf("Listening...\n");

	if (! InitializeCriticalSectionAndSpinCount(&CriticalSection, 0x00000400))
		return 0;
	while (true) {
		SOCKET client = accept(listener, NULL, NULL);
		printf("New client connected: %d\n", client);
		CreateThread(0, 0, ClientThread, &client, 0, 0);
	}
	
	closesocket(listener);
	WSACleanup();
	DeleteCriticalSection(&CriticalSection);
    return 0;
}


DWORD WINAPI ClientThread(LPVOID lpParams)
{
	SOCKET client = *((SOCKET *)lpParams);
	
	char bufUserPass[256];
	int res; 
	char msg[] = "Enter username and password: ";
	do
	{
		send(client, msg, strlen(msg), 0);
		res = recv(client, bufUserPass, sizeof(bufUserPass), 0);
		if (res == SOCKET_ERROR || res == 0)
			break;
		bufUserPass[res-1] = 0;
	} while(check(bufUserPass) == false);
	strcpy(msg, "Login successfully\n");
	send(client, msg, strlen(msg), 0);
	printf("%d is logged in\n", client);

	char buf[256];
	char command[512];
	
	EnterCriticalSection(&CriticalSection);
	
	do
	{
		res = recv(client, buf, sizeof(buf), 0);
		buf[strlen(buf) - 1] = 0;
		if (res == SOCKET_ERROR)
			break;
		else if (res == 1)
			continue;
		sprintf(command, "%s>C:\\temp\\out.txt", buf);
		system(command);
	}while(1);
	
	LeaveCriticalSection(&CriticalSection);
	return 1;
}

