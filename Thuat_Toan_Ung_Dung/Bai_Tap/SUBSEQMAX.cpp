#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* A;
int n;

long maxSubseq()
{
	long Smax = A[0], S = A[0];

	for(int i = 1; i < n; i++)
	{
		if (S <= 0)
		{
			S = A[i];
		}
		else 
		{
			S += A[i];
		}
		if (S > Smax)
			Smax = S;
	}
	return Smax;

}

int main(int argc, char** argv)
{
	scanf("%d", &n);
	A = new int[n];
	for(int i = 0; i < n; i++)
	{
		scanf("%d", &A[i]);
	}
	
    printf("%ld", maxSubseq());

	delete A;
	return 0;
}
