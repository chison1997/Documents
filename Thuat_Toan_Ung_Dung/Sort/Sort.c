#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "quickSort.h"

#define RAM 3

int main(int argc, char** argv)
{
	
	if (argc != 2)
	{
		fprintf(stderr, "Syntax Error\n%s InputFile\n", argv[0]);
	}
	
	time_t start = clock();

	FILE* f = fopen(argv[1], "r");
	int n;
	fscanf(f, "%d", &n);

	
	int l = RAM*1024*1024/(sizeof(float));
	int m = n - l;
	float * const A = (float*) malloc(RAM*1024*1024);
	
	for(int i = 0; i < m; i++)
	{
		fscanf(f, "%f", A + i);
	}

	quickSort(A, 0, m-1);
	

	FILE* t = fopen("temp.txt", "wb+rb");
	for(int i = 0; i < m; i++)
	{
		fwrite(A + i, 4, sizeof(float), t);
	}
	fseek(t, 0, SEEK_SET);

	

	for(int i = 0; i < l; i++)
	{
		//printf("OK\n");
		fscanf(f, "%f", A + i);
	}
	quickSort(A, 0, l-1);


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
