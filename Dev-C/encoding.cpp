#include <stdio.h>
#include <string.h>


int superPow(int a, int b[], int len)
{
	int *B = new int[8 * len];
		
	for(int i = 0; i < len / sizeof(int); i++)
	{
		int x = b[i];
		for(int j = sizeof(int) * 8 - 1; j >= 0; j--)
		{
			B[i*sizeof(int)*8 + j] = (x & (1 << (sizeof(int) * 8 - 1 - j))) ? 1 : 0;	
		}	
	}
	
	
	int k = len * 8;
	int p = a % 1337;
	if (B[k-1] != 0)
		B[k - 1] = p;
	

	for(int i = k - 2; i >= 0; i--)
	{
		p = (p * p) % 1337;
		if (B[i] == 1)
			B[i] = p;
	}

	p = 1;
	for(int i = 0; i < k; i++)	
	{
		if (B[i] != 0)
			p = (p * B[i]) % 1337;
	}
	
	return p;
}



main()
{
	
	int b[] = {1, 0, 0};
	int len = sizeof(b);
	char buf[256];
	gets(buf);
	printf("%s\n", buf);
	FILE* f = fopen("encoding.txt", "w");
	for(int i = 0; i < strlen(buf); i++)
		fprintf(f, "%c", superPow(buf[i], b, len));
}
