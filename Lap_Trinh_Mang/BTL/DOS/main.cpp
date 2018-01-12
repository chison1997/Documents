//TCPClient
#include <winsock2.h>
#include <conio.h>
#include <stdio.h>


DWORD WINAPI ClientThread(LPVOID lpParam);
int num = 0;
SOCKADDR_IN serverAddress;
int main(int argc, char** argv)
{
	
	WSADATA wsaData; 	
	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) )
	{
		printf("Phien ban khong duoc ho tro\n");
	}
		
	char ip[256];
	
	printf("IP: "); gets(ip);
	//is IP address
	serverAddress.sin_family = AF_INET;
	serverAddress.sin_port = htons(80);
	serverAddress.sin_addr.s_addr = inet_addr(ip);
	
	for(int i = 0; i < 10; i++)	
		CreateThread(0, 0, ClientThread, NULL, 0, 0);
		
	
	//closesocket(s);
	while(num > 0);
	getch();
	WSACleanup();
	return 0;
}

DWORD WINAPI ClientThread(LPVOID lpParam)
{
	num++;
	for(int i = 0; i < 500; i++)
	{
		printf("%d\n", i);
		SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		connect(s, (SOCKADDR*) &serverAddress, sizeof(serverAddress));
		//closesocket(s);
	}
	num--;
}


