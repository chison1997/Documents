#include <stdio.h>

int main()
{
	int* a = new int[100];
	for(int i = 0; i < 100; i++)
		printf("%d ", a[i]);
	
	return 0;
}
