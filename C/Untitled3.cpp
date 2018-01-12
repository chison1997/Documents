#include<stdio.h>
#include<conio.h>

void FreeMatrix(float **M,int  R)
{
	for(int i=0; i<R;i++)
 delete []M[i]; // giai phong cac hang
delete []M;
}

main()
{
	int R=5, C=5;
	// Nhap R,C;
float ** M = new float *[R];
for(int i=0; i<R;i++)
 M[i] = new float[C];
//dung M[i][j] nhu binh thuong
for(int i=0;i<R;i++)
	for(int j=0;j<C;j++) M[i][j]=1;
	
for(int i=0;i<R;i++)
	for(int j=0;j<C;j++)  printf("%f ",M[i][j]);
// giai phong

	FreeMatrix(M,R);

}
