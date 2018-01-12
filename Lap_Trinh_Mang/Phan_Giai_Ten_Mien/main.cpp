#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <ws2tcpip.h>
#include <string.h>

int main(int argc, char** argv) {
	WSADATA wsaData;
	WORD wVersion = MAKEWORD(2, 2);
	if (WSAStartup(wVersion, &wsaData))
	{
		printf("Version not supported\n");
		return 0;
	}
	
	addrinfo* result;
	sockaddr_in address;
	
	char* name = new char[100];
	
	if (argc == 1)
	{
		printf("Nhap ten mien: "); gets(name);
	}
	else
	{
		strcpy(name, argv[1]);
	}

	if (getaddrinfo(name, "http", NULL, &result) == 0 )
	{
		memcpy(&address, result->ai_addr, result->ai_addrlen);
		printf("IP: %s\n", inet_ntoa(address.sin_addr));
	}
	else
	{
		printf("Khong phan giai duoc ten mien\n");
	}
		
	if (WSACleanup())
	{
		printf("SOKET ERROR\n");
	}
	system("PAUSE");
	return 0;
}
