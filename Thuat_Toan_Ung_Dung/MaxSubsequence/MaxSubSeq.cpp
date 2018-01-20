#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int* A;
int n;

//Algo 1
//long maxSubseq()
//{
//	long max = A[0]; 
//	for(int i = 0; i < n; i++)
//		for(int j = i; j < n; j++)
//		{
//			int s = 0;
//			for(ing k = i; k <= j; k++)
//				s += A[k];			
//			if (s > max)
//				max = s;
//		}
//	return max;
//}

//Algo 2
long maxSubseq()
{
	long max = A[0]; 
	for(int i = 0; i < n; i++)
	{
		int s = 0;
		for(int j = i; j < n; j++)
		{
			s += A[j];			
			if (s > max)
				max = s;
		}
	}
	return max;
}

void readFile(char* fn)
{
	FILE* f;
	if ( !(f = fopen(fn, "r")) )
	{
		fprintf(stderr, "Can't open the file.\n");
		exit(1);
	}
	fscanf(f, "%d", &n);
	A = new int[n];
	for(int i = 0; i < n; i++)
	{
		fscanf(f, "%d", &A[i]);
	}
	fclose(f);
}

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Syntax Error\n%s inputFile\n", argv[0]);
		return 1;
	}
	
	readFile(argv[1]);
	
	time_t t = clock();
	
	printf("Max Weight: %ld\n", maxSubseq());
	printf("Time: %.2f\n", (float)(clock() - t)/CLOCKS_PER_SEC);
	
	delete A;
	return 0;
}
