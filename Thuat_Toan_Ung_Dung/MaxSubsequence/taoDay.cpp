#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main(int argc, char** argv)
{
	int n = atoi(argv[1]);
	
	srand(time(NULL));
	FILE* f = fopen(argv[2], "w");
	fprintf(f, "%d\n", n);
	for(int i = 0; i < n; i++)
	{
		fprintf(f, "%d ", 50 - rand()%100);
	}




	
	fprintf(f, "\n");
	
	fclose(f);	
	
	return 0;
}
