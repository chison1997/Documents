#include <stdio.h>

int n;
int *A;
int count = 0, c = 0;

void print()
{
	count++;
	for(int i = 0; i < n; i++)
		printf("%d", A[i]);
	printf("\n");
}

//liet ke xau nhi phan
void TRY1(int k)
{
	for(int v = 0; v <= 1; v++)
	{	
		A[k] = v;
		
		if (k == n-1)
		{
			print();
		}
		else
			TRY1(k + 1);
	}
}


//khong co 2 bit 1 dung lien nhau
void TRY2(int k)
{
	for(int v = 0; v <= 1; v++)
	{
		if (v == 1)
		{
			if ( k != 0 && A[k-1] == 1)
				return;
		}
		
		A[k] = v;
		
		if (k == n-1)
		{
			print();
		}
		else
			TRY2(k + 1);
	}
}


//khong co 2 bit 1 dung lien nhau va co dung 7 bit 1
void TRY3(int k)
{
	for(int v = 0; v <= 1; v++)
	{
		if (v == 1)
		{
			if ( k != 0 && A[k-1] == 1)
				return;
			c++;
		}
		
		if (c > 7)
		{
			c--;
			return;
		}
		A[k] = v;
		
		if (k == n-1)
		{
			if(c == 7)
				print();
		}
		else
			TRY3(k + 1);

	}
	c--;
}

int main()
{
	scanf("%d", &n);
	A = new int[n];
	TRY1(0);
	printf("-------------\nCount: %d\n", count);
	delete A;
	return 0;
}
