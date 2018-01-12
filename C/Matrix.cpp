//Su dung con tro

#include <stdio.h>
#include <conio.h>

void AllocMatrix(int **A,int m, int n) //cap phat bo nho cho ma tran 
{
	*A=new int[m*n];
	if (*A==NULL) printf("Khong du bo nho!");
}

void InputMatrix(int *A, int m, int n, char Name) //Nhap ma tran co ten la Name, co m hang, m cot, do con tro A tro toi
{
	for(int i=0;i<m;i++) 
		for(int j=0;j<n;j++)
		{
			printf("%c[%d][%d]= ",Name,i+1,j+1); scanf("%d",&A[i*n+j]);
		 } 
}

void SumMatrix(int *C, int *A, int *B, int m, int n) //Tinh tong ma tran C=A+B, la cac ma tran m*n
{
		for(int i=0;i<m*n;i++) 
			C[i]=A[i]+B[i];
}

void Output(int *A, int m, int n, char Name) //Hien thi ma tran ra man hinh
{
	printf("\nMa tran %c:\n",Name);
	for(int i=0;i<m;i++) 
	{
		for(int j=0;j<n;j++)	printf("%5d", A[i*n+j]);
		
		
		printf("\n");
	}
	printf("\n");
	
}

void FreeMatrix(int *A) //Giai phong bo nho
{
	
	delete [] A;
}

main()
{
	int m,n;
	int *A=NULL, *B=NULL, *C=NULL;
	do
	{printf("Nhap so dong cua ma tran: "); scanf("%d",&m);
	printf("Nhap so cot cua ma tran: "); scanf("%d",&n);
	} while (m*n==0);
	
	//Cap phat bo nho
	AllocMatrix(&A,m,n); 
	AllocMatrix(&B,m,n);
	AllocMatrix(&C,m,n);
	
	//Nhap 2 ma tran A va B
	InputMatrix(A,m,n,'A'); 
	Output(A,m,n,'A');
	
	InputMatrix(B,m,n,'B');
	Output(B,m,n,'B');

	//Tinh C=A+B
	SumMatrix(C,A,B,m,n);
	
	//In C ra man hinh
	printf("Ket qua:\n");
	Output(C,m,n,'C');
	
	//Giai phong bo nho
	FreeMatrix(A);
	FreeMatrix(B);
	FreeMatrix(C);
}
