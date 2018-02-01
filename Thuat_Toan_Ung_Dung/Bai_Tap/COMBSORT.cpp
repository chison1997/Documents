#include <stdio.h>
#include <math.h>
#define gc getchar


int neg;

int scandigits(float *x, int div) {
  register int c = gc();
  register float pow10 = 1;
  if ( x == NULL ) {
    return -1;
  }
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
  if ( x == NULL ) {
    return;
  }
  neg = 0;
  int ret = scandigits(&left, 0);
  if ( ret == '.' )
    scandigits(&right, 1);
  *x = left + right;
}

void swap(float& a, float& b)
{
	register float A = a, B = b;
	b = A;
	a = B;
}

void combSort(float* A, int n)
{
    int gap = n;
    float shrink = 1.3;
    bool sorted = 0;

    while ((gap > 1) || (sorted == 0))
    {
        gap = floor(gap/shrink);
        if (gap < 1) gap = 1;
        int i = 0;
        if (gap == 1)
            sorted = 1;

        while (i + gap < n)
        {
            if (A[i] > A[i+gap])
            {
                swap(A[i], A[i+gap]);
                if (gap == 1)
                    sorted = 0;
            }
            i++;
        }
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    float * A = new float[n];

    for(int i = 0; i < n; i++)
        scanfloat(A + i);
    combSort(A, n);
    
    for(int i = 0; i < n; i++)
        printf("%.2f ", A[i]);
    return 0;
}