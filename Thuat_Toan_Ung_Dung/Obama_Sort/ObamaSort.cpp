#include <stdio.h>

int main(int argc, char** argv)
{
	if (argc != 2)
	{
		fprintf(stderr, "Syntax Error\n%s InputFile\n", argv[1]);
	}
	
	FILE* f = fopen(argv[1], "r");
	int n;
	fscanf(f, "%d", &n);
	int m = n - 780000;
	float *A = new float[m];
	for(int i = 0; i < m; i++)
	{
		fscanf(f, "%f", A + i);
	}
	
	quickSort(A, m);
	
	FILE* t = fopen("temp.txt", "wb");
	for(int i = 0; i < m; i++)
		fwrite(A + i, sizeof(float), 1, t);
	fclose(t);
	
	fclose(t);
	
	fclose(f);
	return 0;
}
