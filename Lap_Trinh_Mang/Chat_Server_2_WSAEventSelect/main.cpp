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
	char * ids[WSA_MAXIMUM_WAIT_EVENTS];
	char buf[1024], sendbuf[1024];
	char cmd[16], id[64], tmp[64], msg[1024];

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
				
				buf[res] = 0;
				
				int j = 0;
					for (; j < numRegisteredClients; j++)
						if (registeredClients[j] == sockets[i])
							break;
					if (j >= numRegisteredClients)
					{
						// chua dang nhap
						buf[res] = 0;
						res = sscanf(buf, "%s %s %s", cmd, id, tmp);
						if (res != 2)
						{
							char * msg = "Wrong format. Please send again.\n";
							send(sockets[i], msg, strlen(msg), 0);
						}
						else
						{
							if (strcmp(cmd, "CONNECT") != 0)
							{
								char * msg = "Wrong format. Please send again.\n";
								send(sockets[i], msg, strlen(msg), 0);
							}
							else
							{
								// Correct format
								char * msg = "OK. You can send message now.\n";
								send(sockets[i], msg, strlen(msg), 0);

								registeredClients[numRegisteredClients] = sockets[i];
								ids[numRegisteredClients] = (char *)malloc(64);
								memcpy(ids[numRegisteredClients], id, strlen(id) + 1);
								numRegisteredClients++;

								break;
							}
						}
					}
					else
					{
						// da dang nhap
						// Xu ly buffer
						buf[res] = 0;
						
						res = sscanf(buf, "%s %s", cmd, tmp);
						
						if (strcmp(cmd, "LIST") == 0)
						{
							sendbuf[0] = 0;
							for(int j = 0; j < numRegisteredClients; j++)
							{
								if( 1024 - strlen(sendbuf) > strlen(ids[j]))
								{
									strcat(sendbuf, ids[j]);
									strcat(sendbuf, "\n");
								}
								else
								{
									send(sockets[i], sendbuf, strlen(sendbuf), 0);
									sendbuf[0] = 0;
									j--;
								}
							}
						}
						else if (strcmp(cmd, "SEND") == 0 && strcmp(tmp, "ALL") != 0) 
						{
							for(int j = 0; j < numRegisteredClients; j++)
							{
								if (sockets[i] == registeredClients[j])
								{
									strcpy(id, ids[j]);
									break;
								}
							}
							sscanf(buf, "%s %s", cmd, tmp);
							bool flag = 0;
							for(int j = 0; j < numRegisteredClients; j++)
							{
								if (strcmp(tmp, ids[j]) == 0)
								{
									flag = 1;
									sprintf(sendbuf, "%s %s", id, buf + strlen(cmd) + strlen(tmp) + 2);
									res = send(registeredClients[j], sendbuf, strlen(sendbuf), 0);
								}
							}
							if (flag == 0 || res == SOCKET_ERROR)
							{
								char msg[] = "ERROR";
								send(sockets[i], msg, strlen(msg), 0);
							}
							else
							{
								char msg[] = "OK";
								send(sockets[i], msg, strlen(msg), 0);
							}
						}
						else if (strcmp(cmd, "SEND") == 0)
						{
							bool flag = 0;
							sprintf(sendbuf, "%s: %s", ids[j], buf);
							for (int j = 0; j < numRegisteredClients; j++)
							if (registeredClients[j] != sockets[i])
								{
									res = send(registeredClients[j], sendbuf, strlen(sendbuf), 0);
									if (res == SOCKET_ERROR)
										flag = 1;
								}
							
							if (flag == 1)
							{
								char msg[] = "ERROR";
								send(sockets[i], msg, strlen(msg), 0);
							}
							else
							{
								char msg[] = "OK";
								send(sockets[i], msg, strlen(msg), 0);
							}
						}
						else if (strcmp(cmd, "DISCONNECT") == 0)
						{
							registeredClients[j] = registeredClients[numRegisteredClients-1];
							delete ids[j];
							ids[j] = ids[numRegisteredClients - 1];
							numRegisteredClients--;
						}
						
					}
				
				
			}
		}

	}

	closesocket(listener);
	WSACleanup();

	return 0;
}
