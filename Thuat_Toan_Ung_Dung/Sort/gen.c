#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv)
{
	srand(time(NULL));
	int n;
	if (argc != 3 || (n = atoi(argv[1])) == 0)
	{
		fprintf(stderr,"Syntax Error\n%s Number OutputFileName\n", argv[0]);
	}
	
	time_t t = clock();
	FILE* f = fopen(argv[2], "w");
	fprintf(f, "%d\n", n);
	for(int i = 0; i < n; i++)
		fprintf(f, "%.2f ", rand()%1000 + (rand() % 100) * 0.01);
	fprintf(stdout, "Time: %.2f s\n", (float)(clock() - t)/CLOCKS_PER_SEC);
	fclose(f);
	return 0;
}
