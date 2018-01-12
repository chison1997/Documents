#include<stdio.h>
#include<ctype.h>
#include<string.h>
#include<conio.h>

char S[25],s[25];
int n, count;
FILE *f=fopen("iloveyou.txt","w");

void process()
{
	count++;
	//printf("%d %s\n",count,s);
	printf("%s\n",s);
	fprintf(f,"%s\n",s);
}

void TRY(int k)
{
	
	if (isspace(S[k])) 
	{
		s[k]=' ';
		TRY(k+1);
	}
	else
	{	
		
		s[k]=tolower(S[k]);
		if (k==n) process();
		else TRY(k+1);
		
		s[k]=toupper(S[k]);
		if (k==n) process();
		else TRY(k+1);
		
	}
}

main()
{
	gets(S);
	printf("\n");
	n=strlen(S)-1;
	
	TRY(0);
	getch();
	
}
