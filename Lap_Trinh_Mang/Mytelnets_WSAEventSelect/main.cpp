#include <stdio.h>
#include <winsock2.h>

int main(int argc, char** argv)
{
	if (argc != 2 || atoi(argv[1]) == 0)
	{
		printf("Tham so khong hop le\n");
		return 0;
	}
	
	SOCKET sockets[WSA_MAXIMUM_WAIT_EVENTS];
	WSAEVENT events[WSA_MAXIMUM_WAIT_EVENTS];
	int totalEvents = 0;

	SOCKET registeredClients[WSA_MAXIMUM_WAIT_EVENTS];
	int numRegisteredClients = 0;

	char buf[1024], cmdbuf[1024], filebuf[1024];
	char user[64], pass[64], tmp[64];

	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(atoi(argv[1]));

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);

	WSAEVENT newEvent = WSACreateEvent();
	WSAEventSelect(listener, newEvent, FD_ACCEPT);

	sockets[totalEvents] = listener;
	events[totalEvents] = newEvent;
	totalEvents++;

	WSANETWORKEVENTS networkEvents;

	while (true)
	{
		int index = WSAWaitForMultipleEvents(totalEvents, events, FALSE, 5000, FALSE);
		if (index == WSA_WAIT_FAILED)
			break;
		if (index == WSA_WAIT_TIMEOUT)
		{
			printf("Timed out.\n");
			continue;
		}

		index = index - WSA_WAIT_EVENT_0;
		for (int i = index; i < totalEvents; i++)
		{
			index = WSAWaitForMultipleEvents(1, &events[i], FALSE, WSA_INFINITE, FALSE);
			if (index == WSA_WAIT_FAILED)
				continue;
			if (index == WSA_WAIT_TIMEOUT)
			{
				printf("Timed out.\n");
				continue;
			}

			WSAEnumNetworkEvents(sockets[i], events[i], &networkEvents);
			if (networkEvents.lNetworkEvents & FD_ACCEPT)
			{
				if (networkEvents.iErrorCode[FD_ACCEPT_BIT] != 0)
					continue;

				SOCKET client = accept(sockets[i], NULL, NULL);
				
				if (totalEvents > WSA_MAXIMUM_WAIT_EVENTS)
				{
					printf("Too many events.\n");
					closesocket(client);
					continue;
				}

				newEvent = WSACreateEvent();
				WSAEventSelect(client, newEvent, FD_READ);

				sockets[totalEvents] = client;
				events[totalEvents] = newEvent;
				totalEvents++;

				printf("New client accepted: %d", client);
			}

			if (networkEvents.lNetworkEvents & FD_READ)
			{
				if (networkEvents.iErrorCode[FD_READ_BIT] != 0)
					continue;

				int res = recv(sockets[i], buf, sizeof(buf), 0);
				if (res == SOCKET_ERROR || res == 0)
					continue;
				
				int j = 0;
					for (; j < numRegisteredClients; j++)
						if (registeredClients[j] == sockets[i])
							break;
					if (j >= numRegisteredClients)
					{
						// chua dang nhap
						
						// Xu ly buffer
						buf[res] = 0;
						res = sscanf(buf, "%s %s %s", user, pass, tmp);
						if (res != 2)
						{
							char msg[] = "Wrong format. Please send again.\n";
							send(sockets[i], msg, strlen(msg), 0);
						}
						else
						{
							sprintf(buf, "%s %s", user, pass);
							int found = 0;
							FILE *f = fopen("D:\\Test\\data.txt", "r");
							while (fgets(filebuf, sizeof(filebuf), f) != NULL)
							{
								filebuf[strlen(filebuf) - 1] = 0;
								if (strcmp(buf, filebuf) == 0)
								{
									found = 1;
									break;
								}
							}
							fclose(f);

							if (found == 0)
							{
								char msg[] = "Wrong username or password. Please send again.\n";
								send(sockets[i], msg, strlen(msg), 0);
							}
							else
							{
								char msg[] = "OK. You can send command now.\n";
								send(sockets[i], msg, strlen(msg), 0);

								registeredClients[numRegisteredClients] = sockets[i];
								numRegisteredClients++;
							}
						}
					}
					else
					{
						// da dang nhap
						buf[res - 1] = 0;
						sprintf(cmdbuf, "%s > D:\\Test\\out.txt", buf);
						system(cmdbuf);

						FILE *f = fopen("D:\\Test\\out.txt", "r");
						while (fgets(filebuf, sizeof(filebuf), f) != NULL)
							send(sockets[i], filebuf, strlen(filebuf), 0);
						fclose(f);
					}
			}
		}

	}

	closesocket(listener);
	WSACleanup();

	return 0;
}
