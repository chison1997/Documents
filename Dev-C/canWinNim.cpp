#include <stdio.h>

char* A;

bool canWinNim(int n)
{
	if (n == 4)
		return 0;
	if (n <= 0)
		return 0;
	if (n < 4)
		return 1;
	
	if (A[n] != -1)
		return A[n];
	
	bool res = 0;
	if (!canWinNim(n - 1))
	{
		res = 1;
	}
	if (!canWinNim(n - 2))
		res = 1;
	if (!canWinNim(n - 3))
		res = 1;

	A[n] = (char) res;
	
	return res;
}

bool canWinNim(char* path)
{
	int n;
	//...
	A = new char[n + 1];
	
	for(int i = 0; i <= n; i++)
		A[i] = -1;
	
	bool result = canWinNim(n);
	
	delete A;
	
	return result;
	//...
}

main()
{
	canWinNim(path);
}
