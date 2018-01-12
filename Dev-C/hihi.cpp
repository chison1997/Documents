#include <stdio.h>

main()
{
	FILE* f = fopen("hihi.txt", "w");
	for(int i = 0; i < 1000; i++)
		fprintf(f, ":) ");
		
	fclose(f);
}
