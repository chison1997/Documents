
#include <stdio.h>

int n;
int* X;
bool f = 0;
int count = 0;

bool Canlidate(int v, int i)
{
	for(int j = 1; j <= i-1; j++)
	{
		if ((X[j] == v) || (v + i == X[j] + j) || (v - i == X[j] - j))
			return false;
	}
	return true;
}

void print()
{
	f = 1;
	count ++;
	for(int i = 1; i <= n; i++)
		printf("%d ", X[i]);
	printf("\n");
}

void TRY(int i)
{
	for(int v = 1; v <= n; v++)
	{
		if (Canlidate(v, i))
		{
			X[i] = v;
			if (i == n)
			{
				print();	
			}
			else
			{
				TRY(i+1);
					
			}
		}
	}

}

int main()
{
	scanf("%d", &n);
	X = new int[n+1];
	TRY(1);
	if (f == 0)
		printf("Khong tim duoc cach xep.\n");
	else
	{
		printf("-----------------\nCount: %d\n", count);
	}
	return 0;
}
