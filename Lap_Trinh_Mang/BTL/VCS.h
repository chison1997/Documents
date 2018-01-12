#ifndef _VCS_h
#define _VCS_h

#include <map>
#include <string>
#include <time.h>
#include <string.h>
char* getTime()
{
	char timeStr[64];
	char* timeGMT = new char[64];
	time_t  t;
	time(&t);
	struct tm * ptm;
	ptm = gmtime(&t);
	t = mktime(ptm);
	strcpy(timeStr, ctime(&t));
	timeStr[strlen(timeStr) - 1] = 0;
	memcpy(timeGMT, timeStr, 3);
	sprintf(timeGMT + 3, ",%s GMT", timeStr + 3);
	return timeGMT;
}

char* getType(char* fileName)
{
	char extension[16];
	int i, l = strlen(fileName);
	for(i = l - 1; i >= 0; i--)
	{
		if (fileName[i] == '.')
			break;
	}
	
	strcpy(extension, fileName + i);
	static bool flag = false;
	static int n;
	static char** exName;
	static char** typeName;
	if (flag == false)
	{
		//printf("Init\n");
		FILE* f = fopen("extension.txt", "r");
		fscanf(f,"%d", &n);
		exName = new char*[n];
		typeName = new char*[n];
		
		char exNameTemp[16], typeNameTemp[128];
		
		for(int i = 0; i <= n; i++)
		{
			
			fscanf(f, "%s", exNameTemp);
			fscanf(f, "%s", typeNameTemp);
			
			exName[i] = new char[strlen(exNameTemp) + 1];
			typeName[i] = new char[strlen(typeNameTemp) + 1];
			
			strcpy(exName[i], exNameTemp);
			strcpy(typeName[i], typeNameTemp);
		}
		
		flag = true;
		fclose(f);
	}
	
	for(int i = 0; i <= n; i++)
	{
		if ( strcmp(extension, exName[i]) == 0)
			return typeName[i];
	}
	
	return NULL;
}

char* getStatusName(int statusCode)
{
	static int statusInt[] = {100, 101, 200, 201, 202, 203, 204, 205, 206, 300, 301, 302, 303, 304, 305, 306, 307, 400, 401, 402, 403, 404, 405, 406, 407, 408, 409, 410, 411, 412, 413, 414, 415, 416, 417, 500, 501, 502, 503, 504, 505}; 
	static char* statusName[] = {"Continue", "Switching Protocols", "OK", "Created", "Accepted", "Non-Authoritative Information", "No Content", "Reset Content", "Partial Content", "Multiple Choices", "Moved Permanently", "Found", "See Other", "Not Modified", "Use Proxy", "306", "Temporary Redirect", "Bad Request", "Unauthorized", "Payment Required", "Forbidden", "Not Found", "Method Not Allowed", "Not Acceptable", "Proxy Authentication Required", "Request Timeout", "Conflict", "Gone", "Length Required", "Precondition Failed", "Request Entity Too Large", "Request URI Too Long", "Unsupported Media Type", "Requested Range Not Satisfiable", "Expectation Failed", "Internal Server Error", "Not Implemented", "Bad Gateway", "Service Unavailable", "Gateway Timeout", "HTTP Version Not Supported"};         
	
	static std::map<int, char*> status;
	static bool flag = false;
	
	if (flag == false)
	{
		for(int i = 0; i < sizeof(statusInt)/sizeof(int); i++)
			status[statusInt[i]] = statusName[i];
		flag = true;
	}
	
	return status[statusCode];
}

char* createResponseHeader(int statusCode, char* fileName, unsigned long len)
{
	
	char* buf = new char[1024];
	char* Date = getTime();
	char* Status = getStatusName(statusCode);
	char* Type = getType(fileName);

	if (fileName != NULL)
	{
		
		sprintf(buf, "HTTP/1.1 %d %s\nDate: %s\nConnection: close\nServer: DDHS\nContent-Type: %s\nContent-Length: %d\n\n", statusCode, Status, Date, Type, len);
	
	}
	else
	{
		sprintf(buf, "HTTP/1.1 %d %s\nDate: %s\nConnection: close\nServer: DDHS\n\n", statusCode, Status, Date);
		
	}

	delete Date;
	return buf;
}



#endif
