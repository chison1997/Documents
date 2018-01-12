//clientinfo
#include <winsock2.h>
#include <ws2tcpip.h>
#include <stdio.h>
#include <string.h>
#include <regex>

#define BUFFER_SIZE 1024
#define MAX_COMPUTERNAME_LENGTH  15
#define MAX_DRIVER_STRINGS_LENGTH 50

using namespace std;

bool isIPv4Address(char* s) {
	regex r("[0-9]{1,3}(.[0-9]{1,3}){3}");
	if(!regex_match(s,r))return false;
	int a,b,c,d;
	sscanf(s, "%d.%d.%d.%d", &a, &b, &c, &d);
	return a<256 && b<256 && c<256 && d<256;
}

void drive(char* name, char* free, char* all)
{
	DWORD sectorsPerCluster;	
	DWORD bytesPerSector;
	DWORD numberOfFreeClusters;
	DWORD totalNumberOfClusters;
	GetDiskFreeSpace(name, &sectorsPerCluster, &bytesPerSector, &numberOfFreeClusters, &totalNumberOfClusters);
	
	DWORDLONG freeBytes =  (DWORDLONG) numberOfFreeClusters * sectorsPerCluster * bytesPerSector;
	DWORDLONG allBytes = (DWORDLONG) totalNumberOfClusters * sectorsPerCluster * bytesPerSector; 
	strcpy(free, std::to_string(freeBytes).c_str());
	strcpy(all, std::to_string(allBytes).c_str());

}

int main(int argc, char** argv)
{
	
	if (argc != 3)
	{
		printf("Tham so khong hop le\n");
		return 0;
	}
	
	WSADATA wsaData; 	
	if ( WSAStartup(MAKEWORD(2, 2), &wsaData) )
	{
		printf("Phien ban khong duoc ho tro\n");
	}

	SOCKET s = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	SOCKADDR_IN serverAddress;
	
	if (isIPv4Address(argv[1]))
	{
		//is IP address
		serverAddress.sin_family = AF_INET;
		serverAddress.sin_port = htons(atoi(argv[2]));
		serverAddress.sin_addr.s_addr = inet_addr(argv[1]);
	}
	else
	{
		//is domain name
		addrinfo* result;
		if (getaddrinfo(argv[1], NULL, NULL, &result) == 0)
		{
			memcpy(&serverAddress, result->ai_addr, result->ai_addrlen);
			serverAddress.sin_port = htons(atoi(argv[2]));
		}
		else
		{
			printf("Khong phan giai duoc ten mien\n");
		}
		
	}
	
	if (connect(s, (SOCKADDR*) &serverAddress, sizeof(serverAddress)) != SOCKET_ERROR)
	{
		char buf[BUFFER_SIZE];

		char computerName[MAX_COMPUTERNAME_LENGTH + 1];
		DWORD computerNameSize = MAX_COMPUTERNAME_LENGTH + 1;
		GetComputerName(computerName, &computerNameSize);
		strcpy(buf, computerName);
		int len = strlen(buf);
		buf[len] = '\n'; buf[len+1] = '\0'; len++;

		char nameDrive[MAX_DRIVER_STRINGS_LENGTH];
		char free[20];
		char all[20];
		int numberDrive = GetLogicalDriveStrings(BUFFER_SIZE - 1, nameDrive) / 4;
		for(int i = 0; i < numberDrive; i++)
		{
			drive(nameDrive + 4*i, free, all);
			strcat(buf, nameDrive + 4*i);
			strcat(buf, " ");
			strcat(buf, free);
			strcat(buf, " Bytes free of ");
			strcat(buf, all);
			strcat(buf, " Bytes\n");

		}
		printf("%s", buf);
		send(s, buf, strlen(buf), 0);

	}
	else
	{
		printf("Ket noi that bai\n");
	}
	
	closesocket(s);
	WSACleanup();
	return 0;
}
