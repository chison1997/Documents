//TCPClient
#include <winsock2.h>

#include <stdio.h>



int main(int argc, char** argv)
{
	
	WSADATA wsaData; 	
	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) )
	{
		printf("Phien ban khong duoc ho tro\n");
	}
		
	
	SOCKADDR_IN serverAddress;
		

		//is IP address
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons(80);
		serverAddress.sin_addr.s_addr = inet_addr("127.0.0.1");
	
	for(int i = 0; i < 1000000; i++)
	{
		printf("%d\n", i);
		SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		 connect(s, (SOCKADDR*) &serverAddress, sizeof(serverAddress));
		closesocket(s);
	}
	//closesocket(s);
	WSACleanup();
	return 0;
}
