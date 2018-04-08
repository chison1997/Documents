#include <stdio.h>
#include <stdlib.h>

int X[9][9];

bool col[9][10] = {{0}}; // col[c][v] neu v da xuat hien tren cot c
bool row[9][10] = {{0}};
bool square[3][3][10] = {{{0}}};

void mark(int r, int c, int v, bool x)
{
	col[c][v] = x;
	row[r][v] = x;
	square[r/3][c/3][v] = x;
}

bool check(int r, int c, int v)
{
	if (col[c][v])
		return false;
	if (row[r][v])
		return false;
	if (square[r/3][c/3][v])
		return false;
	return true;
}

void print()
{
	for(int i = 0; i < 9; i++)
	{
		for(int j = 0; j < 9; j++)
		{
			printf("%d ", X[i][j]);
			if ((j+1)%3 == 0)
				printf(" ");
		}
		printf("\n");
		if ((i+1)%3 == 0)
				printf("\n");
	}
	printf("-----------------\n");
}

void TRY(int r, int c)
{
	for(int v = 1; v <= 9; v++)
	{
		if (check(r, c, v))
		{
			X[r][c] = v;
			mark(r, c, v, 1);
			
			if (r == 8 && c == 8)
			{
				print();
				//exit(0);
				system("PAUSE");
			}
			else if (c < 8)
				TRY(r, c + 1);
			else
				TRY(r + 1, 0);
				
			mark(r, c, v, 0);
		}
	}
}


int main()
{
	TRY(0, 0);
	
	return 0;
}
