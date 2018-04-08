//tim so nghiem cua x1 + x2 + ... + xn = M
//xi >= 1

#include <stdio.h>

int n, M, T = 0; //T: tong tich luy
int* X;

void print()
{
	for(int i = 1; i <= n; i++)
		printf("%d ", X[i]);
	printf("\n");
}

void TRY(int k)
{
	for(int v = 1; v <= M - (n-k) - T; v++)
	{
		X[k] = v;
		T += v;
		if (k == n)
		{
			if (T == M)
				print();
		}
		else
			TRY(k+1);
		T -= v;
		
	}
}

int main()
{
	scanf("%d %d", &n, &M);
	X = new int[n+1];
	TRY(1);
	
	return 0;
}
