#include "encrypt.h"
#include <stdlib.h>
#include <time.h>



void encrypt(char* message)
{
	static int  init = 0;
	if (init == 0 )
	{
		srand(time(NULL));
		key = (char)( rand() % 256);
		init = 1;
	}
	while(*message)
	{
		*message = *message + key;
		message++;
	}
}

void decrypt(char* message)
{
	while(*message)
	{
		*message = *message - key;
		message++;
	}
}