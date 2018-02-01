#include <stdio.h>
#include <list>
#include <stack>
#include <queue>
#include <map>
#include <string>

#include <iostream>
#include <fstream>

using namespace std;

int main()
{
//    list<int> L;
//
//    for(int i = 1; i < 10; i++)
//        L.push_back(i);
//    
//    printf("Size of List: %d\n", L.size());
//    for(list<int>::iterator it = L.begin(); it != L.end(); it++)
//    {
//    	printf("%d ", *it);
//	}

//	stack<int> S;
//	for(int i = 1; i < 10; i++)
//		S.push(i);
//	
//	while(!S.empty())
//	{
//		printf("%d ", S.top());
//		S.pop();
//	}

	//queue<int> Q;
	
	
	map<string, int> M;
	ifstream f;
	f.open("words.txt");
	
	string line;
	while(getline(f, line))
	{
		//cout << line << endl;
		int o = M[line];
		o = o + 1;
		M[line] = o;
	}
	
	cout << "----------RESULT------------" << endl; 
	for(auto it = M.begin(); it != M.end(); it++)
	{
		cout << it->first << " " << it->second << endl;
	}


	return 0;
}
