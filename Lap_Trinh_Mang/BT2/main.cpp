//TCPServer
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>

int main(int argc, char** argv) {
	if (argc != 4)
	{
		printf("Tham so khong hop le\n");
		return 0;
	}
	
	WSADATA wsaData; 	
	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) )
	{
		printf("Phien ban khong duoc ho tro\n");
	}
	
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons(atoi(argv[1]));
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	SOCKET listening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	bind(listening, (SOCKADDR*) &addr, sizeof(addr));
	
	listen(listening, 5);
	printf("Waiting for client...\n");
	
	SOCKET client = accept(listening, NULL, NULL);
	
	char buf[1024];
	int res;
	
	FILE* fsend = fopen(argv[2], "rb");
	printf("File: %s\n", argv[2]);
	
	while (1)
	{
		res = fread(buf, 1, sizeof(buf), fsend);
		if (res == 0)
		{
			break;
		}

		send(client, buf, res, 0);

		if (res < 1024)
			break;
	}
	fclose(fsend);
	
	FILE* frecv = fopen(argv[3], "wb");
	while (1)
	{
		res = recv(client, buf, sizeof(buf), 0);
		if (res == SOCKET_ERROR || res == 0)
			break;

		fwrite(buf, 1, res, frecv);
	}
	fclose(frecv);
	
	
	closesocket(listening);
	closesocket(client);
	WSACleanup();
	return 0;
}
