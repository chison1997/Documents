// mytelnets
//  _  _   ___  ____ 
// / )( \ / __)/ ___)
// \ \/ /( (__ \___ \
//  \__/  \___)(____/



#include "stdafx.h"
#include <WinSock2.h>
#include <ctype.h>


#define INFO_NODE_SIZE 256

struct node {
	int size;
	char* info[INFO_NODE_SIZE];
	node* next;
};

node* userPass[36] = { NULL };

void readFileUser()
{
	FILE* f = fopen("userPass.txt", "r");
	char buf[256];
	node* p;
	int index;
	while (!feof(f))
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

bool check(char* buf, SOCKET s)
{

	char user[128], pass[128], temp[36];
	int res = sscanf(buf, "%s %s %s", user, pass, temp);
	if (res != 2)
	{
		char msg[] = "Wrong format\n";
		send(s, msg, strlen(msg), 0);
		return 0;
	}
	else
	{
		sprintf(buf, "%s %s", user, pass);
	}


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
		for (int i = 0; i < p->size; i++)
		{
			if (strcmp((p->info)[i], buf) == 0)
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
		printf("THam so khong hop le\n");
		system("PAUSE");
		return 0;
	}

	WSADATA wsa;
	if (WSAStartup(MAKEWORD(2, 2), &wsa) == SOCKET_ERROR)
	{
		printf("Phien ban khong duoc ho tro\n");
		system("PAUSE");
		return 0;
	}

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(atoi(argv[1]));

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);
	printf("listening...\n");
	fd_set fdread;
	int res;

	SOCKET clients[1024];
	int numClients = 0;

	char buf[256];

	while (true)
	{
		printf("\n\n");
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
					do {

						char* msg = "Enter user name and password: ";
						res = send(clients[i], msg, strlen(msg), 0);
						if (res == SOCKET_ERROR || res == 0)
							continue;
						res = recv(clients[i], buf, sizeof(buf), 0);
						if (res == SOCKET_ERROR || res == 0)
							continue;
						buf[res] = 0;

					} while (!check(buf, clients[i]));


					char command[512];


					do
					{
						res = recv(clients[i], buf, sizeof(buf), 0);
						buf[strlen(buf) - 1] = 0;
						if (res == SOCKET_ERROR)
							break;
						else if (res == 1)
							continue;
						sprintf(command, "%s>C:\\temp\\out.txt", buf);
						system(command);
					} while (1);


				}

		}
	}

	closesocket(listener);
	for (int i = 0; i < numClients; i++)
	{
		closesocket(clients[i]);
	}
	WSACleanup();
	return 0;
}

