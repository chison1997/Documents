//Traveling Salesman Problem
//__     __                          ____ _     _   ____
//\ \   / /   _  ___  _ __   __ _   / ___| |__ (_) / ___|  ___  _ __
// \ \ / / | | |/ _ \| '_ \ / _` | | |   | '_ \| | \___ \ / _ \| '_ \
//  \ V /| |_| | (_) | | | | (_| | | |___| | | | |  ___) | (_) | | | |
//   \_/  \__,_|\___/|_| |_|\__, |  \____|_| |_|_| |____/ \___/|_| |_|
//                          |___/
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <time.h>

int** A;
int n;
int* x;
bool* visited;
int f;
int f_best;
int* x_best;
int cmin = INT_MAX;

void readData(char* fn)
{
	FILE* f = fopen (fn, "r");
	fscanf(f, "%d", &n);
	A = new int*[n];
	x = new int[n];
	x_best = new int[n];
	visited = new bool[n];
	
	n--;
	for(int i = 0; i <= n; i++)
	{
		A[i] = new int[n+1];
		for(int j = 0; j <= n; j++)
		{
			fscanf(f, "%d", &A[i][j]);
			if (i != j && cmin > A[i][j])
				cmin = A[i][j];
		}
	}
	fclose(f);
}

void free()
{
	delete x;
	delete x_best;
	delete visited;
	for(int i = 0; i <= n; i++)
	{
		delete A[i];
	}
	delete A;
}

void init()
{
	for(int i = 0; i <= n; i++)
	{
		visited[i] = false;
	}
	f = 0;
	f_best = INT_MAX;
}

void updateBest()
{
	int t = f + A[x[n]][0];
	if (t < f_best)
	{
		f_best = t;
		memcpy(x_best, x, (n+1)*sizeof(int));
	}
}

void print()
{
	for(int i = 0; i <= n; i++)
	{
		printf("%d ", x_best[i]);
	}
	printf(", f_best = %d\n", f_best);
}

void TRY(int k)
{
	for(int v = 1; v <= n; v++)
	{
		if (visited[v] == false)
		{
			x[k] = v;
			visited[v] = true;
			f += A[x[k-1]][x[k]];
			int g = f + (n+1-k) * cmin; //dieu kien can duoi
			if (k == n)
			{
				updateBest();
			}
			else
			{
				if (g < f_best)
					TRY(k+1);
			}
			
			visited[v] = false;
			f -= A[x[k-1]][x[k]];
		}
	}
}


int main()
{
	readData("TSP.txt");	
	init();

	x[0] = 0;
	visited[0] = true;
	time_t t = clock();
	TRY(1);
	printf("Time: %.2f s\n", (float)(clock() - t)/CLOCKS_PER_SEC);
	print();
	free();
	
}
