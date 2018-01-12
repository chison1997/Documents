#ifndef _def_h
#define _def_h

#include <winsock2.h>
#include <map>
#include <string>
#include <time.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <vector>
#include <algorithm>
#include <unistd.h>
using namespace std;


#define BUF_SIZE 4096

bool operator == (in_addr a1, in_addr a2)
{
	return (a1.s_addr == a2.s_addr);
 } 

enum METHOD {GET, PUT, DELE, POST, HEAD, TRACE, OPTIONS, LOCK, MKCOL, COPY, MOVE};
char* method[] = {"GET", "PUT", "DELETE", "POST", "HEAD", "TRACE", 
					"OPTIONS", "LOCK", "MKCOL", "COPY", "MOVE"};
#define METHOD_NUM sizeof(method) / sizeof(char*)

enum GENERAL_HEADER_ENUM {Connection, Date, MIME_Version, Trailer, Transfer_Encoding, Upgrade, Via};
char* GeneralHeader[] = {"Connection: ", "Date: ", "MIME-Version: ", "Trailer: ", 
							"Transfer-Encoding: ", "Upgrade: ", "Via: "};
#define GENERAL_HEADER_NUM sizeof(GeneralHeader) / sizeof(char*)

enum REQUEST_HEADER_ENUM {Client_IP,From,Host,Referer,UA_Color,UA_CPU,UA_Disp,UA_OS,UA_Pixels,User_Agent, 
							Accept,Accept_Charset,Accept_Encoding, Accept_Language, TE, Expect, 
							If_Match, If_Modified_Since, If_None_Match, If_Range, 
							If_Unmodified_Since, Range, Authorization, Cookie, Cookie2, 
							Max_Forwards, Proxy_Authorization, Proxy_Connection};
char* RequestHeader[] = {"Client-IP: ","From: ","Host: ","Referer: ","UA-Color: ","UA-CPU: ",
							"UA-Disp: ","UA-OS: ","UA-Pixels: ","User-Agent: ", "Accept: ", 
							"Accept-Charset: ", "Accept-Encoding: ", "Accept-Language: ", "TE: ", "Expect: ", 
							"If-Match: ", "If-Modified-Since: ", "If-None-Match: ", "If-Range: ", 
							"If-Unmodified-Since: ", "Range: ", "Authorization: ", "Cookie: ", "Cookie2: ", 
							"Max-Forwards: ", "Proxy-Authorization: ", "Proxy-Connection: "};
#define REQUEST_HEADER_NUM sizeof(RequestHeader) / sizeof(char*)
						
enum RESPONSE_HEADER_ENUM {Age,Public,Retry_After,Server,Title,Warning};	
char* ResponseHeader[] = {"Age: ","Public: ","Retry-After: ","Server: ",
							"Title: ","Warning: "};
#define  RESPONSE_HEADER_NUM sizeof(ResponseHeader) / sizeof(char*)					
					
enum ENTITY_HEADER_ENUM {Allow,Location,Content_Base, Content_Encoding, 
						Content_Language, Content_Length, Content_Location, 
						Content_MD5, Content_Range,Content_Type,ETag,
						Expires,Last_Modified};							
char* EntityHeader[] = {"Allow: ","Location: ", "Content-Base: ", "Content-Encoding: ", 
						"Content-Language: ", "Content-Length: ", "Content-Location: ", 
						"Content-MD5: ", "Content-Range: ", "Content-Type: ", "ETag: "
						"Expires: ","Last-Modified: "};
#define  ENTITY_HEADER_NUM sizeof(EntityHeader) / sizeof(char*)		


//enum EXTENSION_HEADER_ENUM { };
//char*  ExtensionHeader[] = {};
//					 

struct CLIENT{
	SOCKET clientSocket;
	SOCKADDR_IN addr;
};


struct REQUEST{
	METHOD m;
	char* URL;
	char* version;
	char* generalHeader[GENERAL_HEADER_NUM] = {NULL};
	char* requestHeader[REQUEST_HEADER_NUM] = {NULL};
	char* entityHeader[ENTITY_HEADER_NUM] = {NULL};
	char* body;
};
void free(REQUEST* rq);

REQUEST* parseRequest(char* buf);
void getHeader(char* headerBegin, char* headerEnd, char** header, char** headerName, int headerNum);


void get(REQUEST* req, CLIENT* c);
void put(REQUEST* req, char* buf, int len, CLIENT* c);
//void dele(REQUEST* req, CLIENT* c);
void post(REQUEST* req, char* buf, int len, CLIENT* c);
void head(REQUEST* req, CLIENT* c);
//void trace(REQUEST* req, CLIENT* c);
void options(REQUEST* req, CLIENT* c);
//void lock(REQUEST* req, CLIENT* c);
//void mkcol(REQUEST* req, CLIENT* c);
//void copy(REQUEST* req, CLIENT* c);
//void move(REQUEST* req, CLIENT* c);


//create response header
char* createResponseHeader(int statusCode, char* fileName, long len);
//get GMT time for Date header
char* getTime();
//get file MIME name type 
char* getType(char* fileName);
//get status name
char* getStatusName(int statusCode);

void writeLog(CLIENT* c);
int recvTimeout(SOCKET s, int milli_seconds);


/*------------------------------------------------------*/

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

char* getLastModified(char *fileName) {	
	char* timeStr = new char[128];
	struct stat buf;
	if (!stat(fileName, &buf))
	{
		strftime(timeStr, 128, "%a, %d %b %Y %H:%M:%S GMT", localtime( &buf.st_mtime));
		return  timeStr;	
	}
	else
	{
		delete timeStr;
        return NULL;
    }
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

char* createResponseHeader(int statusCode, char* fileName, long len)
{
	
	char* buf = new char[1024];
	char* Date = getTime();
	char* Status = getStatusName(statusCode);
	
	
	if ( statusCode == 200 &  len != 0 )
	{
		char* Type = getType(fileName);
		char* LastModified = getLastModified(fileName);
		sprintf(buf, "HTTP/1.1 200 OK\nDate: %s\nContent-Type: %s\nContent-length: %d\nLast-Modified: %s\n\n", Date, Type, len, LastModified);
		delete LastModified;
		
	}
	else
	{
		sprintf(buf, "HTTP/1.1 %d %s\nDate: %s\nConnection: close\n\n", statusCode, Status, Date);
		
	}

	delete Date;
	return buf;
}


void free(REQUEST* rq)
{
	if (rq == NULL)
		return;
		
	delete rq->URL;
	delete rq->version;
	
	for(int i = 0; i < GENERAL_HEADER_NUM; i++)
		delete rq->generalHeader[i];

	for(int i = 0; i < REQUEST_HEADER_NUM; i++)
		delete rq->requestHeader[i];

	delete rq;
}

void getHeader(char* headerBegin, char* headerEnd, char** header, char** headerName, int headerNum)
{
	char* start;
	int len;
	
	for(int i = 0; i < headerNum; i++)
	{	
		start = strstr(headerBegin, headerName[i]);
	
		if (start != NULL && start < headerEnd)
		{	
			start += strlen(headerName[i]);
			len = strstr(start, "\n") - start;
			
			header[i] = (char*) calloc(len + 1, sizeof(char));
			memcpy(header[i], start, len);
		}
	}
}

REQUEST* parseRequest(char* buf)
{
	
	char methodTemp[8], pathTemp[256], versionTemp[16], temp[512];
	sscanf(buf, "%s %s %s", methodTemp, pathTemp, versionTemp);
	if(strlen(methodTemp) == 0 | strlen(pathTemp) == 0 | strlen(versionTemp) == 0)
		return NULL;	
		
	REQUEST* rq = new REQUEST();
	int i;
	for(i = 0; i < METHOD_NUM; i++)
	{
		if (strcmp(methodTemp, method[i]) == 0)
		{
			rq->m = (METHOD) i;
			break;
		}
	}
	if (i == METHOD_NUM)
	{
		delete rq;
		return NULL;
	}
	
	rq->URL = new char[strlen(pathTemp) + 1];
	strcpy(rq->URL, pathTemp);
	rq->version = new char[strlen(versionTemp) + 1];
	strcpy(rq->version, versionTemp);
	
	char* headerBegin = strstr(buf, "\n"); 

	char* headerEnd = strstr(buf, "\n\n");
	if (headerEnd == NULL)
	{
		char end[] = {10, 13};
		headerEnd = strstr(buf, end);
	}
	if (headerEnd == NULL)
	{
		headerEnd = buf + strlen(buf);
	}
	
	getHeader(headerBegin, headerEnd, rq->generalHeader, GeneralHeader, GENERAL_HEADER_NUM);
	
	getHeader(headerBegin, headerEnd, rq->requestHeader, RequestHeader, REQUEST_HEADER_NUM);
	
	getHeader(headerBegin, headerEnd, rq->entityHeader, EntityHeader, ENTITY_HEADER_NUM);
	
	rq->body = headerEnd + 2;
		
	return rq;
}



char* convert (char* URL, char* root) {
		char* fileName = new char[256];
		if (strcmp(URL, "/") == 0)
			sprintf(fileName, "%s\\index.html", root);
		else
		{
			int j = 0; char temp[256];
			for (int i = 0; i < strlen(URL); i++, j++){
				if (URL[i] == '/')
					temp[j] = '\\';
					else if (URL[i]=='%' && URL[i+1]=='2' && URL[i+2]=='0')
					{
						temp[j]= ' ';
						i+=2;
					   }   
					   else 
					   temp[j] = URL[i];
				}
				temp[j]=0;
				sprintf(fileName, "%s\%s", root, temp);
			}
		
			
			return fileName;
	}
			
long getSize(char* fileName)
{
	FILE* f = fopen(fileName, "r");
	
	fseek(f, 0, SEEK_END);
	long size = ftell(f);
	fseek(f, 0, SEEK_SET);
	
	fclose(f);
	return size;
}

void get(REQUEST* req, CLIENT* c)
{
	char* fileName = convert(req->URL, "VietHome");
	
	//tinh dung luong file
    int size = getSize(fileName);
	   
	int statusCode = 200;   
	
	//tao header
	if (size == -1)
	{
		size = 0;
		statusCode = 404;
	}
	
	char* header = createResponseHeader(statusCode, fileName, size);

	int res = send(c->clientSocket, header, strlen(header), 0);
	delete header;
	
	if (res == 0 || res == SOCKET_ERROR)
	{
		delete fileName;
		return;
	}
		
	FILE* f = fopen(fileName, "rb");
	
	delete fileName;
	
	//send file
	char buf[2048];
	while(1)
	{
		res = fread(buf, 1, sizeof(buf), f);
		if (res > 0)
			send(c->clientSocket, buf, res, 0);
		else
			break;
	}	
	
	fclose(f);
	
}

void put(REQUEST* req, char* buf, int res, CLIENT* c)
{
	char* fileName = convert(req->URL, "VietHome\\Data");
	char* header;

	FILE* f = fopen(fileName, "wb");

 
	req->body++;
	int len = res - (req->body - buf);
	fwrite(req->body , 1, len, f);
	buf[0] = 0;
	fd_set set;
	timeval timeout;
	if(req->entityHeader[Content_Length] == NULL)
	{
		header = createResponseHeader(400, NULL, 0);
		len = -1;
	}
	else
	{
		len = atoi(req->entityHeader[Content_Length]) - len;
		header = createResponseHeader(201, NULL, 0);
	}
	while(len > 0)
	{   

		FD_ZERO(&set);
		FD_SET(c->clientSocket, &set);
		timeout.tv_sec = 500;
		timeout.tv_usec = 0;
		res =  select(0, &set, NULL, NULL, &timeout);
	
		if((res == 0)|| (res == SOCKET_ERROR))
		{
			break;
		}
		res = recv(c->clientSocket, buf, BUF_SIZE, 0);
		len -= res;
		if (res > 0)
			fwrite(buf, 1, res, f);
		else 
			break;
		
	}
	
	send(c->clientSocket, header, strlen(header), 0);
	fclose(f);

	delete header;
}

void post(REQUEST* req, char* buf, int len, CLIENT* c)
{
	char* header;
	if (strcmp(req->URL, "/checkbrowser") == 0)
	{
		buf[len] = 0;
		FILE* f = fopen("Browser.txt", "a");
		static const int l = strlen("checkbrowser=");
		fprintf(f, "%s\n", req->body + 1 + l);
		header = createResponseHeader(200, NULL, 0);
		fclose(f);
	}
	else 
	{
		header = createResponseHeader(404, NULL, 0);
	}
	send(c->clientSocket, header, strlen(header), 0);
	
	delete header;

}


void options(REQUEST* req, CLIENT* c)
{
	char buf[] = "HTTP/1.1 200 OK\nAllow:  GET,PUT,POST,HEAD,OPTIONS\n\n";
	send(c->clientSocket, buf, strlen(buf), 0);
}

void head(REQUEST* req, CLIENT* c)
{
	char* fileName = convert(req->URL, "VietHome");
	
	//tinh dung luong file
    int size = getSize(fileName);
	   
	int statusCode = 200;   
	
	//tao header
	if (size == -1)
	{
		size = 0;
		statusCode = 404;
	}
	
	char* header = createResponseHeader(statusCode, fileName, size);

	send(c->clientSocket, header, strlen(header), 0);
	
	delete header;
	
}

void writeLog(CLIENT* c)
{
	FILE *f = fopen("log.txt","a");
	fprintf(f,"%s\t%s\n",inet_ntoa((c->addr).sin_addr),getTime());
		
	fclose(f);
}

void delay(int milli_seconds)
{
    // Stroing start time
    clock_t start_time = clock();
 
    // looping till required time is not acheived
    while (clock() < start_time + milli_seconds);
}

void showMenu()
{
	printf("________________MENU________________\n");
	printf("ShowNumThread [show_time_second] [frequency]\n");
	printf("ShowBlockList\n");
	printf("Block [IP]\n");
	printf("UnBlock [IP]\n");
	printf("UnBlock\n");
	printf("ShowMenu\n");
	printf("Exit\n");
	printf("____________________________________\n");
}


#endif
