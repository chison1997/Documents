#include <stdio.h>
#include <winsock2.h>
#include <conio.h>

#define BUFFER_SIZE 256

int main(int argc, char** argv) {
	if (argc != 2)
	{
		printf("Tham so khong hop le\n");
		getch();
		return 0;
	}
	
	WSADATA wsaData;
	if( WSAStartup(MAKEWORD(2, 2), &wsaData) )
	{
		printf("Phien ban khong duoc ho tro\n");
		return 0;
	}
	
	SOCKADDR_IN addr;
	addr.sin_family = AF_INET;
	addr.sin_port = htons( atoi( argv[1] ) );
	addr.sin_addr.s_addr = htonl(INADDR_ANY);
	
	
	SOCKET listening = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	
	bind(listening, (SOCKADDR*) &addr, sizeof(addr));
	
	listen(listening, 5);
	
	SOCKET clientSocket = accept(listening, NULL, NULL);
	
	char buf[BUFFER_SIZE];
	
	int res = recv(clientSocket, buf, BUFFER_SIZE, 0);
	int sum = 0, count = 0;
	bool flag = 1;
	
	for(int i = 0; i < res && count != 10; i++)
	{
		if ((isdigit(buf[i]) || buf[i] == '-') && flag == 1)
		{
			sum += atoi(buf + i);
			count++;
			flag = 0;
		}
		else if (! isdigit( buf[i] ))
			flag = 1;
		
	}
	if (count < 10)
		printf("Chi co %d so, Khong du 10 so\n", count);
	
	printf("sum = %d\n", sum);
	
	closesocket(listening);
	closesocket(clientSocket);
	WSACleanup();
	return 0;
}
