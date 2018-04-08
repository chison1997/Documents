#include <stack>
#include <string>
#include <iostream>
#include <stdio.h>

using namespace std;

bool match(char c, char cc)
{
	if (c == '[')
		return cc == ']';
	else if (c == '{')
		return cc == '}';
	else if (c == '(')
		return cc == ')'; 
	return false;
}

bool check(string p)
{
	stack<char> S;
	
	for(int i = 0; i < p.length(); i++)
	{
		if (p[i] == '[' || p[i] == '{' || p[i] == '(')
			S.push(p[i]);
		else
		{
			if (S.empty())
				return false;
				
			if (match(S.top(), p[i]) == false)
				return false;
			
			S.pop();
		}
	}
	if (S.empty())
		return true;
	return false;
}

int main()
{
	string p;
	int T;
	scanf("%d", &T);
	for(int i = 0; i < T; i++)
	{
		cin >> p;
		printf("%d\n", check(p));
	}
	return 0;
}
