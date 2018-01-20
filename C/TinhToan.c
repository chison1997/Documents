#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char* argv[])
{
	char ch;
	int tong = 0, hieu = 0;
	while ((ch = getopt(argc, argv, "th")) != EOF)
	{
		switch(ch)
		{
			case 't':
				tong = 1;
				break;
			case 'h':
				hieu = 1;
				break;
		}

	}

	argc -= optind;
	argv += optind;

	if ((tong | hieu) == 0)
	{
		fprintf(stderr, "Syntax Error.\n");
	}
	else if ((tong & hieu) == 1)
	{
		fprintf(stderr, "Syntax Error.\n");
	}
	else if (tong == 1)
	{
		int sum = 0;
		for(int i = 0; i < argc; i++)
		{
			sum += atoi(argv[i]);
		}
		printf("Tong = %d\n", sum);
	}
	else
	{
		int sub = atoi(argv[0]);
		for(int i = 1; i < argc; i++)
		{
			sub -= atoi(argv[i]);
		}
		printf("Hieu = %d\n", sub);
	}

	return 0;
}