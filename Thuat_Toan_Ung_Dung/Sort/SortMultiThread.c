#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>
#include "quickSort.h"

#define RAM 3


int m, n, l, done = 0;;
float * A;
char* fn;

void read(long o,float* A, int n, int c)
{
	FILE* f = fopen(fn, "r");
	printf("start read file %d\n", c);
	fseek(f, o, SEEK_SET);
	for(int i = 0; i < n; i ++)
	{
		fscanf(f, "%f", A + c*i);
	}
	printf("Read done %d\n", c);
	fclose(f);
}

void* subThread(void* a)
{
	printf("Create Thread\n");
	read(m, A+l-1, l, -1);
	quickSort(A, 0, l-1);
	done = 1;
	return NULL;
}

int main(int argc, char** argv)
{
	
	if (argc != 2)
	{
		fprintf(stderr, "Syntax Error\n%s InputFile\n", argv[0]);
	}
	
	time_t start = clock();

	FILE* f;
	f = fopen(argv[1], "r");
	fn = argv[1];
	fscanf(f, "%d", &n);

	
	l = RAM*1024*1024/(sizeof(float));
	m = n - l;
	A = (float*) malloc(RAM*1024*1024);
	
	pthread_t t0;
	if (pthread_create(&t0, NULL, subThread, NULL) == -1)
	{
		fprintf(stderr,"Can't create thread\n");
	}

	read(0, A, m, 1);
	quickSort(A, 0, m-1);
	printf("quickSort done\n");

	FILE* t = fopen("temp.txt", "wb+rb");
	for(int i = 0; i < m; i++)
	{
		fwrite(A + i, 4, sizeof(float), t);
	}
	printf("Write temp file done\n");
	fseek(t, 0, SEEK_SET);

	while (!done);
	printf("OK\n");
	// for(int i = 0; i < l; i++)
	// {
	// 	//printf("OK\n");
	// 	fscanf(f, "%f", A + i);
	// }
	// quickSort(A, 0, l-1);


	// for (int i = 0; i < m; ++i)
	// {
	// 	float temp;
	// 	fread(&temp, 1, sizeof(temp), t);
	// 	//printf("%f ", temp);
	// }

//Merge
	FILE* g = fopen("out.txt", "w");
	int i = 0, j = 0;
	float temp;
	fread(&temp, 4, sizeof(temp), t);
	while (i < m && j < l)
	{
		if (temp <= A[j])
		{
			fprintf(g, "%.2f ", temp);
			i++;
			fread(&temp, 4, sizeof(temp), t);
		}
		else
		{
			fprintf(g, "%.2f ", A[j]);
			j++;
		}
	}
	while (i < m)
	{
		fprintf(g, "%.2f ", temp);
		i++;
		fread(&temp, 1, sizeof(temp), t);
	}
	while (j < l)
	{
		fprintf(g, "%.2f ", A[j]);
		j++;
	}

	printf("Time: %.2f s\n", (float)(clock() - start) / CLOCKS_PER_SEC);

	fclose(g);
	fclose(t);

	free(A);
	fclose(f);

	return 0;
}
