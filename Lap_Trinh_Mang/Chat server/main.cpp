//Chat server
//@author VCS
#include <stdio.h>
#include <winsock2.h>
#include <vector>
#include <regex>
using namespace std;

vector <SOCKET> clients;

DWORD WINAPI ClientThread(LPVOID lpParams);


bool check(char* info)
{
	if (std::regex_match(info, std::regex("(client_id: )(.*)")))
		return true;
		
	return false;
}

int main(int argc, char** argv)
{
	if (argc != 2 || atoi(argv[1]) == 0)
	{
		printf("Tham so khong hop le\n");
		return 0;
	}
	
	WSADATA wsa;
	WSAStartup(MAKEWORD(2, 2), &wsa);

	SOCKET listener = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);

	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	addr.sin_port = htons(atoi(argv[1]));

	bind(listener, (SOCKADDR *)&addr, sizeof(addr));
	listen(listener, 5);

	clients.reserve(64);

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
	char name[256];
	char msg[512];
	char timeStr[32];
	int res; 
	do
	{
		res = recv(client, buf, sizeof(buf), 0);
		if (res == SOCKET_ERROR || res == 0)
			break;
		buf[res-1] = 0;
		
	} while(check(buf) == false);
	
	strcpy(name, buf + strlen("client_id: "));
	
	int index = -1;
	for(int i = 0; i < clients.size(); i++)
		if (clients[i] == 0)
		{
			clients[i] = client;
			index = i;
			break;
		}
	if (index == -1)
		clients.push_back(client);
	
	
	do
	{
		res = recv(client, msg, sizeof(buf), 0);
		
		time_t  t;
		time(&t);

		if (res == SOCKET_ERROR || res == 0)
			break;
		msg[res] = 0;
		
		strcpy(timeStr, ctime(&t));
		timeStr[strlen(timeStr) - 1] = 0;
		strcpy(buf, timeStr);
		strcat(buf, ", ");
		strcat(buf, name);
		strcat(buf, ": ");
		strcat(buf, msg);
					
		for (int i = 0; i < clients.size(); i++)
			if (clients[i] != client)
			{
				send(clients[i], buf, strlen(buf), 0);
			}
			
	} while(1);

	clients[index] = 0;
	closesocket(client);

}
