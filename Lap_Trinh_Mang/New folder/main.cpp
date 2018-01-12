#include <iostream>
#include <stdio.h>
#include <winsock2.h>
#include <string.h>

int stream(char* msg, FILE* f)
{
	int count = 0;
	while (!feof(f) &&  count < 256)
	{
		msg[count] = fgetc(f);
		count++;
	}
	return count;
}

int main(int argc, char** argv) 
{
	WSADATA wsaData;
	WORD wVersion = MAKEWORD(2, 2);
	if(WSAStartup(wVersion, &wsaData))
	{
		printf("Version not supported\n");
		return 0;
	}
	
	
	
	SOCKADDR_IN client;
	client.sin_family = AF_INET;
	client.sin_port = htons(8888);
	client.sin_addr.s_addr = htonl(INADDR_ANY);
	
	int res;
	
//	while(1)
//	{
		//FILE* f = fopen("sudoku.html", "r");
		SOCKET s1 = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
		bind(s1, (SOCKADDR *) &client, sizeof(client));
		listen(s1, 5);
		
		printf("Waiting for client...\n");
		
		SOCKET s2 = accept(s1, NULL, NULL);
		
		//printf("Client connected %d\n", s1);
		printf("S1: %d, S2: %d\n", s1, s2);
		
//		char* msg = new char[256];
//		msg[255] = '\0';
//		char buf[] = "HTTP/1.1 200 OK\r\nDate: Mon, 23 May 2005 22:38:34 GMT\r\nContent-Type: text/html; charset=UTF-8\r\nContent-Encoding: UTF-8\r\nContent-Length: 2672\r\nLast-Modified: Wed, 08 Jan 2003 23:11:55 GMT\r\nServer: Apache/1.3.3.7 (Unix) (Red-Hat/Linux)\r\nETag: \"3f80f-1b6-3e1cb03b\"\r\nAccept-Ranges: bytes\r\nConnection: close\n\0";
//		send(s2, buf, strlen(buf), 0);
		
//		while (1)
//		{
//			
//			
//			int count = stream(msg, f);
//			int res = send(s2, msg, count, 0);
//		
//			if (res != SOCKET_ERROR)
//			{
//				printf("%d bytes are sent\n", res);
//			}
//			else
//			{
//				printf("Sending failed\n");
//				break;
//			}
//			if (feof(f))
//				break;
//		}

		char buf[256];
		while (true) {
			res = recv(s2, buf, sizeof(buf), 0);
			if (res <= 0)
				break;
			buf[res] = 0;
			printf("%s\n", buf);
		}
		
		closesocket(s1);
		closesocket(s2);
		//fclose(f);
//	}
	
	
	if(WSACleanup())
	{
		printf("SOCKET ERROR\n");
	}
	return 0;
}
