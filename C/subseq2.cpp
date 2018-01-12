#include<conio.h>
#include<stdio.h>
#include <stdlib.h>
#include <time.h> 

int A[1000000];

void CreatSeq(int n)   // Tao file chua day so
{
	FILE *f =fopen("seq.txt","w");
	fprintf(f,"%d\n",n);
	//srand (time(NULL));
	for(int i=0; i<n;i++)
	{	
		//srand (time(NULL));
		int x=100- rand()%200;
		fprintf(f,"%d ",x);
	}
	fclose(f);
}

void ReadSeq()	//doc file va dua day so vao mang
{
	int n;
	FILE *f = fopen("seq.txt","r");
	fscanf(f,"%d",&n);
	
	for(int i=0; i<n;i++)
	{
		 fscanf(f,"%d",&A[i]);
		
	}
	
	
	fclose(f);
}

int SubSeq(int n)  //tinh toan, tim tong day con be nhat
{
	ReadSeq();
	int S=A[0], max=S;
	for(int i=1; i<n;i++)
	{
		if (S>0) S+=A[i];
		else S=A[i];
		
		max=max<S? S : max;
	}
	return max;
}

main(){
	int n;
	printf("n= "); scanf("%d",&n);
	
	CreatSeq(n);
	
	printf("%d ",SubSeq(n));

}
