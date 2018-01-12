#include<conio.h>
#include<stdio.h>

double A[100][100];


double C(int k,int n)
{
	if ((k==0) || (k==n)) A[k][n]=1;
	else if (A[k][n]==-1) A[k][n]=C(k,n-1)+C(k-1,n-1);
	return A[k][n];
}

main()
{
	int k,n;
	printf("k= "); scanf("%d", &k);
	printf("n= "); scanf("%d", &n);
	
	for(int i=1;i<=k;i++) for(int j=1;j<=n;j++)A[i][j]=-1;
	
	printf("%.0lf ", C(k,n));
}
