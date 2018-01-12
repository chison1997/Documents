
#include <stdio.h>
#include <winsock2.h>
#include <string.h>


DWORD WINAPI ClientThread(LPVOID lpParams);

int check(char* num)
{
	for(int i = 0; i < strlen(num); i++)
	{
		if (!isdigit(num[i]))
			return 0;
	}
	return 1;
}

int main(int argc, char** argv)
{
	
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(9000);

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);


	while (true) {
		SOCKET client = accept(listener, NULL, NULL);
		printf("New client connected: %d\n", client);
		CreateThread(0, 0, ClientThread, &client, 0, 0);
	}
	
	closesocket(listener);
	WSACleanup();

    return 0;
}

DWORD WINAPI ClientThread(LPVOID lpParams)
{
	SOCKET client = *((SOCKET *)lpParams);
	
	char buf[1024];
	char cmd[8];
	char num1[8];
	char num2[8];
	char temp[16];
	int res; 

	
	while(1)
	{
		res = recv(client, buf, sizeof(buf), 0);

		if (res == SOCKET_ERROR || res == 0)
			break;
		
		buf[res] = 0;
		
		res = sscanf(buf, "%s %s %s %s", cmd, num1, num2, temp);
	
		
		if (res != 3)
		{
			char* error = "ERROR Cu phap khong hop le\n";
			send(client, error, strlen(error), 0);
		}
		else if ((strcmp(cmd, "ADD") && strcmp(cmd, "SUB")) != 0)
		{
			char* error = "ERROR Lenh khong hop le (lenh la ADD hoac SUB)\n";
			send(client, error, strlen(error), 0);
		}
		else if ((check(num1) && check(num2)) == 0)
		{
			char* error = "ERROR Sau lenh phai la 2 so\n";
			send(client, error, strlen(error), 0);
		}
		else
		{
			int result;
			if (strcmp(cmd, "ADD") == 0)
				result = atoi(num1) + atoi(num2);
			else
				result = atoi(num1) - atoi(num2);
		
			char msg[32];
			sprintf(msg, "OK %d\n", result);
			send(client, msg, strlen(msg), 0);
		}
			
	} 

	closesocket(client);
}

