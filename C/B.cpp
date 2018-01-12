#include <stdio.h>
#include <conio.h>

int BRecursive(int n)
{
	if (n <= 4) return n;
	return BRecursive(n - 4) - BRecursive(n - 3) + BRecursive(n - 2) + BRecursive(n - 1);
}

int sumRecursive(int n)
{
	int sum = 0;
	for(int i = 1; i <= n; i++)
		{
			sum += BRecursive( i );
		}
	return sum;
}

// find B(n) non-recursive
int B(int n)
{
	if (n <= 4) return n;
	int k1 = 1, k2 = 2, k3 = 3, k4 = 4, i=4, b;
	while (i < n)
	{
		i++;
		b = k1 - k2 + k3 + k4;
		k1 = k2;
		k2 = k3;
		k3 = k4;
		k4 = b; 
	}
	return b;
}
 
// find sum non-recursive
int sum(int n)
{
	if (n <= 4) return n * (n + 1) * 0.5;
	int k1 = 1, k2 = 2, k3 = 3, k4 = 4, i=4, sum = 10, b;
	while (i < n)
	{
		i++;
		b = k1 - k2 + k3 + k4;
		sum += b;
		k1 = k2;
		k2 = k3;
		k3 = k4;
		k4 = b; 
	}
	return sum;	
}


main()
{
	for(int i = 1; i <= 20; i++)
		printf("%d %d\n", sum( i ), sumRecursive( i ));
		getch();
}
