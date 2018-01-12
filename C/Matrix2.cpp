//Su dung con tro tro toi con tro

#include <stdio.h>
#include <conio.h>

void AllocMatrix(int ***A,int m, int n)
{
	*A=new int* [m];
	if (*A==NULL) printf("Khong du bo nho!");
	int* temp= new int[m*n];
	if (temp==NULL) printf("Khong du bo nho!");
	for(int i=0; i<m;i++)
	{
		(*A) [i]=temp;
		temp+=n;
		
	}
}

void InputMatrix(int **A, int m, int n, char Name)
{
	for(int i=0;i<m;i++) 
		for(int j=0;j<n;j++)
		{
			printf("%c[%d][%d]= ",Name,i+1,j+1); scanf("%d",&A[i][j]);
		 } 
}

void SumMatrix(int **C, int **A, int **B, int m, int n)
{
		for(int i=0;i<m;i++) 
			for(int j=0;j<n;j++)
				C[i][j]=A[i][j]+B[i][j];
}

void Output(int **A, int m, int n, char Name)
{
	printf("\nMa tran %c:\n",Name);
	for(int i=0;i<m;i++) 
	{
		for(int j=0;j<n;j++)	
			printf(" %5d", A[i][j]);
		printf("\n");
	}
	printf("\n");
	
}

void FreeMatrix(int **A, int m)
{
	
		for(int i=0; i<m; i++)
			delete []A[i]; 
			
		delete []A;
	
}

main()
{
	int m,n;
	int **A=NULL, **B=NULL, **C=NULL;
	
	do
	{printf("Nhap so dong cua ma tran: "); scanf("%d",&m);
	printf("Nhap so cot cua ma tran: "); scanf("%d",&n);
	} while (m*n==0);
	
	AllocMatrix(&A,m,n); 
	AllocMatrix(&B,m,n);
	AllocMatrix(&C,m,n);
	
	InputMatrix(A,m,n,'A'); 
	Output(A,m,n,'A');
	
	InputMatrix(B,m,n,'B');
	Output(B,m,n,'B');

	
	SumMatrix(C,A,B,m,n);
	
	printf("Ket qua:\n");
	Output(C,m,n,'C');
	
	FreeMatrix(A,m);
	FreeMatrix(B,m);
	FreeMatrix(C,m);
}
