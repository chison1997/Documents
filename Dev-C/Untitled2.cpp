#include <stdio.h>
#include <math.h>

main()
{
	int X = 1, n = 1;
	while (X <= 1000)
	{
		X = (int) pow(2, X);
		n ++;
	}
	printf("%d\n", n);
}
