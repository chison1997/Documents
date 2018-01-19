#include <stdio.h>

int main(int argc, char** argv)
{
	FILE* f = fopen("dl.inp", "r");
	int a, b;
	fscanf(f, "%d", &a);
	fscanf(f, "%d", &b);
	int c = a + b;
	FILE* g = fopen("kq.out", "w");
	fprintf(g, "%d", c);
	fclose(g);
	fclose(f);
	return 0;
}
