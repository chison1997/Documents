#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

int main()
{
	FILE* f = fopen("dayso.inp", "r");
	int sum = 0, max = INT_MIN, min = INT_MAX, n;
	fscanf(f, "%d", &n);
	int *A = new int[n];
	for(int i = 0; i < n; i++)
	{
		fscanf(f, "%d", A + i);
		sum += A[i];
		if (A[i] > max)
			max = A[i];
		if (A[i] < min)
			min = A[i];
	}
	fclose(f);
	
	f = fopen("kq.out", "w");
	fprintf(f, "%d %d %d\n", sum, min, max);
	fclose(f);
	delete A;
	return 0;
}
