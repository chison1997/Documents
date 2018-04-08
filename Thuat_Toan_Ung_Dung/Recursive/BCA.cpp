#include <stdio.h>
#include <limits.h>
#include <stack>
using namespace std; 

int n, m;
//map<int, set<int>> preference;
int preference[11][31] = {{0}};

//int** conflicting;
int conflicting[31][31] = {{0}};

int A[31];
int count[11] = {0};
int best = INT_MAX;

stack<int> maxLoad;


void readData()
{
	scanf("%d %d", &m, &n);
	for(int i = 0; i < m; i++)
	{
		int num;
		scanf("%d", &num);
		//set<int> s;
		for(int j = 0; j < num; j++)
		{
			int v;
			scanf("%d", &v);
			//s.insert(v);
			preference[i][v] = 1;
		}
		//preference[i] = s;
	}
	
//	A = new int[n+1];
//	conflicting = new int*[n+1];
//	for(int i = 1; i <= n; i++)
//	{
//		conflicting[i] = new int[n+1];
//		for(int j = 1; j <= n; j++)
//			conflicting[i][j] = 0;
//	}
//	count = new int[n+1];
//	for(int i = 1; i <= n; i++)
//		count = 0;
	
	int k;
	scanf("%d", &k);
	for(int i = 0; i < k; i++)
	{
		int a, b;
		scanf("%d %d", &a, &b);
		conflicting[a][b] = 1;
		conflicting[b][a] = 1;
	}
	
	maxLoad.push(0);
	
}


bool check(int k, int v)//mon k thay v
{
	if (preference[v][k] == 0)
		return false;
	if (count[v] + 1 >= best)
		return false;
	
	for(int i = 1; i < k; i++)
	{
		if ( A[i] == v && conflicting[i][k] == 1)
			return false;
	}
	return true;
}

void TRY(int k)
{
	for(int v = 1; v <= m; v++)
	{
		//if (preference[v].find(k) != preference[v].end())
			if (check(k, v))
			{
				A[k] = v;
				count[v] ++;
				bool flag = 0;
				if (count[v] > maxLoad.top())
					{
						flag = 1;
						maxLoad.push(count[v]);
					}
				if (k == n)
				{
					if (maxLoad.top() < best)
						best = maxLoad.top();
				}
				else
				{
					//if (maxLoad.top() > (m-k)/n && maxLoad.top() < best) 
						TRY(k+1);
				}
					
				if (flag == 1)
					maxLoad.pop();
				count[v] --;
			}
	}
}

int main()
{
	readData();
	
	TRY(1);
	if (best == INT_MAX)
		printf("-1");
	else
		printf("%d", best);
	return 0;
}
