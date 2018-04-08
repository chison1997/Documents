#include <stdio.h>
#include <winsock2.h>

int main(int argc, char** argv) {
	WSADATA wsaData;
	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) )
	{
		printf("Phien ban khong duoc ho tro\n");
	}
	sockaddr_in addr;
    addr.sin_family = AF_INET;
    addr.sin_port = htons(554);
    addr.sin_addr.s_addr = inet_addr("192.168.16.106");
    
	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
    
	if (connect(s, (sockaddr*) &addr, sizeof(addr)) == SOCKET_ERROR)
	{
		printf("Connect error.\n");
		return 0;
	}
    else
    {
    	printf("Connected.\n");
	}
	const char* msg = "OPTIONS rtsp://192.168.16.109/onvif1 RTSP/1.0\r\nCSeq: 1\r\nUser-Agent: LibVLC/2.2.1 (LIVE555 Streaming Media v2014.07.25)\r\r\n\n"; 
    
	if (send(s, msg, strlen(msg), 0) == SOCKET_ERROR)
	{
		printf("Send error.\n");
		return 0;
	}
    
	char buf[256];
    recv(s, buf, sizeof(buf), 0);
    printf("%s.\n", buf);
	
	
	WSACleanup();
	return 0;
}
