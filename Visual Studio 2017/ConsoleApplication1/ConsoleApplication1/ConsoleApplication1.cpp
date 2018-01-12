// ConsoleApplication1.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "winsock2.h"

int main()
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	SOCKADDR_IN addr;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_family = AF_INET;
	addr.sin_port = htons(8888);

	bind(listener, (SOCKADDR*)&addr, sizeof(addr));

	listen(listener, 5);
	printf("Listening....\n");
	fd_set fdread;
	int res;

	SOCKET clients[1024];
	int numClients = 0;

	char buf[512];

	while (1)
	{
		FD_ZERO(&fdread);

		FD_SET(listener, &fdread);

		for (int i = 0; i < numClients; i++)
		{
			FD_SET(clients[i], &fdread);
		}

		res = select(0, &fdread, NULL, NULL, NULL);

		if (res == SOCKET_ERROR)
		{
			break;
		}
		if (res > 0)
		{
			if (FD_ISSET(listener, &fdread))
			{
				SOCKET client = accept(listener, NULL, NULL);
				printf("Client accepted: %d\n", client);
				clients[numClients] = client;
				numClients++;
			}
			for (int i = 0; i < numClients; i++)
			{
				if (FD_ISSET(clients[i], &fdread))
				{
					res = recv(clients[i], buf, sizeof(buf), 0);
					if (res == SOCKET_ERROR || res == 0)
					{
						continue;
					}
					buf[res] = 0;
					printf("%s", buf);

				}
			}
		}

	}

	closesocket(listener);
	for (int i = 0; i < numClients; i++)
	{
		closesocket(clients[i]);
	}
	WSACleanup;
    return 0;
}

