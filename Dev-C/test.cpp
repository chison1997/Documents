#include <stdio.h>

main()
{
	int *a, *b;
	a = new int;
	b = new int;
	scanf("%d %d", a, b);
	printf("%d", *a + *b);
}
