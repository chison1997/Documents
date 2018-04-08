#include <stdio.h>
#include <stdlib.h>

int main()
{
	FILE* f = fopen("bang_gia.txt", "w");
	int n;
	scanf("%d", &n);
	
	fprintf(f, "%d\n", n);
	for(int i = 0; i < n; i++)
	{
		for(int j = 0; j < n; j++)
		{
			fprintf(f, "%d ", rand() % 50 + 1);
		}
		fprintf(f, "\n");
	}
	fclose(f);
	return 0;
}
