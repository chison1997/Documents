// chatServer
//  _  _   ___  ____ 
// / )( \ / __)/ ___)
// \ \/ /( (__ \___ \
//  \__/  \___)(____/


#include "stdafx.h"
#include "winsock2.h"


SOCKET clients[1024];
int numClients = 0;

void RemoveClient(SOCKET client)
{
	int i = 0;
	for (; i < numClients; i++)
		if (clients[i] == client)
			break;
	if (i < numClients - 1)
		clients[i] = clients[numClients - 1];
	numClients--;
}


int main()
{
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(8888);

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);

	fd_set fdread;
	int res;


	char buf[256];

	while (true)
	{
		FD_ZERO(&fdread);

		FD_SET(listener, &fdread);
		for (int i = 0; i < numClients; i++)
			FD_SET(clients[i], &fdread);

		res = select(0, &fdread, NULL, NULL, NULL);
		if (res == SOCKET_ERROR)
			break;
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
				if (FD_ISSET(clients[i], &fdread))
				{
					char buf[256], sendbuf[256];
					int res;

					char cmd[16], id[64], tmp[64];

					while (true)
					{
						res = recv(clients[i], buf, sizeof(buf), 0);
						if (res == SOCKET_ERROR || res == 0)
						{
							closesocket(clients[i]);
							return 1;
						}

						// Xu ly buffer
						buf[res] = 0;
						res = sscanf(buf, "%s %s %s", cmd, id, tmp);
						if (res != 2)
						{
							char * msg = "Wrong format. Please send again.\n";
							send(clients[i], msg, strlen(msg), 0);
						}
						else
						{
							if (strcmp(cmd, "client_id:") != 0)
							{
								char * msg = "Wrong format. Please send again.\n";
								send(clients[i], msg, strlen(msg), 0);
							}
							else
							{
								// Correct format
								char * msg = "OK. You can send message now.\n";
								send(clients[i], msg, strlen(msg), 0);

								break;
							}
						}
					}

					while (true)
					{
						res = recv(clients[i], buf, sizeof(buf), 0);
						if (res == SOCKET_ERROR || res == 0)
						{
							RemoveClient(clients[i]);
							closesocket(clients[i]);
							break;
						}

						// Xu ly buffer
						buf[res] = 0;

						sprintf(sendbuf, "%s: %s", id, buf);

						for (int j = 0; j < numClients; j++)
							if (clients[i] != clients[j])
								send(clients[j], sendbuf, strlen(sendbuf), 0);
					}

				}
		}
	}

	closesocket(listener);
	WSACleanup();
	return 0;
}
