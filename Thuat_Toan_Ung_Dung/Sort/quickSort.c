#include <stdio.h>
#include "quickSort.h"

void quickSort(float* A, int L, int R)
{
	if (L < R)
	{
		int index = (L + R) / 2;
		index = partition(A, L, R, index);
		if (L < index)
			quickSort(A, L, index - 1);
		if (index < R)
			quickSort(A, index + 1, R);
	}
}

int partition(float* A, int L, int R, int indexPivot)
{
	float pivot = A[indexPivot];
	swap(&A[indexPivot], &A[R]);
	int storeIndex = L;

	for(int i = L; i <= R-1; i++)
		if(A[i] < pivot)
		{
			swap(&A[storeIndex], &A[i]);
			storeIndex++;
		}
	swap(&A[storeIndex], &A[R]);

	return storeIndex;
}

void swap(float* a, float* b)
{
	// register float t = *a;
	// *a = *b;
	// *b = t;

	register float A = *a, B = *b;
	*b = A;
	*a = B;

}
void print(float* A, int n)
{
	for(int i = 0; i < n; i++)
		printf("%f \n", A[i]);
	printf("\n");
}