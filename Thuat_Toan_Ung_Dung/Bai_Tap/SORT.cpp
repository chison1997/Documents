#include <stdio.h>
#include <stdlib.h>
#define gc getchar

int neg;

int scandigits(float *x, int div) {
  register int c = gc();
  register float pow10 = 1;

  *x = 0;
  while ( (c < '0' || c > '9') && c != '-' ) {
    c = gc();
  }
  if ( c == '-' ) {
    neg = 1;
    c = gc();
  }
  while ( !(c < '0' || c > '9') ) {
    *x *= 10;
    *x += (c - '0');
    pow10 *= 10;
    c = gc();
  }
  if ( neg )
    *x = -*x;
  if ( div )
    *x /= pow10;
  return c;
}

void scanfloat(float *x) {
  float left, right = 0;
  neg = 0;
  int ret = scandigits(&left, 0);
  if ( ret == '.' )
    scandigits(&right, 1);
  *x = left + right;
}

void swap(float* a, float* b)
{
	register float t = *a;
	*a = *b;
  *b = t;
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

int main()
{
    float* A;
    int n;
    
    scanf("%d", &n);
    A = new float[n];
    for(int i = 0; i < n; i++)
    {
       scanfloat(A + i);
    }
    quickSort(A, 0, n-1);
    for(int i = 0; i < n; i++)
        printf("%.2f ", A[i]);
  
    delete A;
    return 0;
}