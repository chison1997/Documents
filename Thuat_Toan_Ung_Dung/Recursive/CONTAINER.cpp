#include <stdio.h>

int W, H;
int N;
int w[13], h[13];
bool C[31][31] = {{0}};

void readData()
{
	scanf("%d %d", &H, &W);
	scanf("%d", &N);
	for(int i = 0; i < N; i++)
	{
		scanf("%d %d", &h[i], &w[i]);
	}
	
}

void mark(int x, int y, int w, int h, bool v)
{
	for(int X = x; X < x + w; X++)
		for(int Y = y; X < y + h; Y++)
			C[X][Y] = v;
}	

bool check(int x, int y, int w, int h)
{
	for(int X = x; X < x + w; X++)
		for(int Y = y; X < y + h; Y++)
			if (C[X][Y] == 1)
				return 0;
	return 1;
}

bool TRY(int k)
{
	for(int X = 0; X <= W-w[k]; X++)
		for(int Y = 0; Y <= H-h[k]; Y++)
		{
			if (check(X, Y, w[k], h[k]))
			{
				mark(X, Y, w[k], h[k], 1);
				
				if (k == N)
					return 1;
				else
				{
					if (TRY(k+1))
						return 1;
				}
				
				mark(X, Y, w[k], h[k], 0);	
			}	
		}
	
	return 0;
}

bool preCheck()
{
	int S = 0;
	for(int i = 0; i < N; i++)
	{
		if (w[i] > W)
			return 0;
		if (h[i] > H)
			return 0;
		S += h[i] * w[i];
	}
	return S <= W * H;
}

int main()
{
	readData();
	if (preCheck() == 0)
		printf("0");
	else
		printf("%d", TRY(0));
	return 0;
}
