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
	char cmd[16], id[64], tmp[64];

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
							if (strcmp(cmd, "client_id:") != 0)
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

						sprintf(sendbuf, "%s: %s", ids[j], buf);

						for (int j = 0; j < numRegisteredClients; j++)
							if (registeredClients[j] != sockets[i])
								send(registeredClients[j], sendbuf, strlen(sendbuf), 0);
					}
				
				
			}
		}

	}

	closesocket(listener);
	WSACleanup();

	return 0;
}
