#include <stdio.h>

int m[100][100] = {{0}};

int C(int k, int n)
{
	if (k == 0 || k == n)
		m[k][n] = 1;
	else if (m[k][n] == 0)
		m[k][n] = C(k-1, n-1) + C(k, n-1);
	return m[k][n];
}

int main()
{
	printf("%d\n", C(16, 32));
	
	return 0;
}
