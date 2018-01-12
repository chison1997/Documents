//serverinfo
#include <stdio.h>
#include <winsock2.h>
#include <conio.h>

#define BUFFER_SIZE 1024

int main(int argc, char** argv) {
	if (argc != 2)
	{
		printf("Tham so khong hop le\n");
		getch();
		return 0;
	}
	
	WSADATA wsaData;
	if (WSAStartup(MAKEWORD(2, 2), &wsaData))
	{
		printf("Phien ban khong duoc ho tro\n");
		return 0;
	}
	
	SOCKET listening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons( atoi( argv[1] ) );
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	bind(listening, (SOCKADDR*) &addr, sizeof(addr));
	
	listen(listening, 5);
	
	SOCKADDR_IN clientAddr;
	int addrLen = sizeof(clientAddr);
	
	SOCKET clientSocket = accept(listening, (SOCKADDR*) &clientAddr, &addrLen);
	
	char buf[BUFFER_SIZE];
	
	while(1)
	{
		int res = recv(clientSocket, buf, BUFFER_SIZE, 0);
		if (res == 0 || res == SOCKET_ERROR)
		{
			break;
		}
		printf("Thong tin cua %s:\n%s", inet_ntoa(clientAddr.sin_addr), buf);
	}
	
	closesocket(listening);
	closesocket(clientSocket);
	WSACleanup();
	return 0;
}
