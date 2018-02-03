#include <stdio.h>

int n;
bool* mark;
int* X;
int count = 0;

void print()
{
	count++;
	for(int i = 0; i < n; i++)
		printf("%d ", X[i]);
	printf("\n");
}

void TRY(int k)
{
	for(int v = 1; v <= n; v++)
	{
		if (mark[v] == 0)
		{
			X[k] = v;
			mark[v] = 1;
			
			if (k == n-1)
				print();
			else
				TRY(k+1);
				
			mark[v] = 0;	
		}
	}
}

int main()
{
	scanf("%d", &n);
	mark = new bool[n];
	for(int i = 0 ; i < n; i++)
		mark[i] = 0;
	X = new int[n];
	
	TRY(0);
	printf("-------------\nCount: %d\n", count);
	delete X;
	delete mark;
	return 0;
}
