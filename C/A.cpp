#include <stdio.h>
#include <conio.h>

//find A(n) by recursive
int ARecursive(int n)
{
	if (n <= 4) return n;
	return ARecursive(n - 4) + ARecursive(n - 3) - ARecursive(n - 2) + ARecursive(n - 1);
}

//find sum by recursive
int sumRecursive(int n)
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
		{
			sum += ARecursive( i );
		}
	return sum;
}

// find A(n) non-recursive
int A(int n)
{
	if (n <= 4) return n;
	int k1 = 1, k2 = 2, k3 = 3, k4 = 4, i=4, a;
	while (i < n)
	{
		i++;
		a = k1 + k2 - k3 + k4;
		k1 = k2;
		k2 = k3;
		k3 = k4;
		k4 = a; 
	}
	return a;
}
 
// find sum non-recursive
int sum(int n)
{
	if (n <= 4) return n * (n + 1) * 0.5;
	int k1 = 1, k2 = 2, k3 = 3, k4 = 4, i=4, sum = 10, a;
	while (i < n)
	{
		i++;
		a = k1 + k2 - k3 + k4;
		sum += a;
		k1 = k2;
		k2 = k3;
		k3 = k4;
		k4 = a; 
	}
	return sum;	
}

main()
{
	for(int i = 1; i <= 20; i++)
	{//	printf("%d, %d \n", ARecursive( i ), A( i ));
		printf("%d, %d \n", sumRecursive( i ), sum( i ));
		}
	getch();
}
