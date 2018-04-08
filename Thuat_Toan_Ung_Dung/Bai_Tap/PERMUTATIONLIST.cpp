#include <stdio.h>


int n, k;
bool* mark;
int* X;
int count = 0;


bool TRY(int i)
{
	for(int v = 1; v <= n; v++)
	{
		if (mark[v] == 0)
		{
			X[i] = v;
			mark[i] = 1;
			
			if (i == n-1)
			{
                count++;
                if (count == k)
                    return true;
            }
			else
				if (TRY(i+1))
                    return true;
				
			mark[v] = 0;	
		}
	}
    return false;
}


int main()
{
    scanf("%d %d", &n, &k);
	mark = new bool[n];
	for(int i = 0 ; i < n; i++)
		mark[i] = 0;

	X = new int[n];
	
	bool res = TRY(0);
	if (res == false)
        printf("-1\n");
    else{
        for(int i = 0; i < n; i++)
            printf("%d ", X[i]);
    }
	delete X;
	delete mark;
	return 0;

    return 0;
}