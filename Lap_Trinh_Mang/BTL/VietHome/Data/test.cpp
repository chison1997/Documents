#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <ctype.h>
#include <string.h>

using namespace std;

struct DaThuc
{
	vector<float> v;
	char name[4];
};

vector<DaThuc> P;

DaThuc* findP(char* s)
{
	char name[4];
	sscanf(s, "%s", name);
	for(int i = 0; i < P.size(); i++)
	{
		if (strcmp(name, P[i].name) == 0)
		{
			return &(P[i]);
		}
	}
	return NULL;
}

main()
{
	FILE* f = fopen("data 03.txt", "r");
	char s[128];

	P.reserve(8);
	
	while(!feof(f))
	{
		fscanf(f, "%s", s);
		if (strstr(s, "[") != NULL) //khai bao da thuc
		{
			DaThuc p;
			sscanf(s, "%s", p.name);
			for(int i = strstr(s, "[") - s; i < strlen(s); i++)
			{
				if(!isalpha(s[i]))
				{
					p.v.push_back(atof(s + 1));
				}
			}
			P.push_back(p);
		
		
		}
		else
		{
			DaThuc p;
			DaThuc *p1, *p2;
			sscanf(s, "%s", p.name);
			char* res = strstr(strstr(s, "="), "P");
			p1 = findP(res);
			p2 = findP(strstr(res + 1, "P"));
			
			if (strstr(s, "+") != NULL)
			{
				
			}
			else if (strstr(s, "-") != NULL)
			{
				
			}
			else if (strstr(s, "*") != NULL)
			{
				
			}
			
			P.push_back(p);
		}
	}
	


}
