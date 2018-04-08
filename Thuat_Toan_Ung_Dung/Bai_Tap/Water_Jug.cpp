#include <stdio.h>
#include <queue>
#include <list>
#include <stack>

using namespace std;

struct state
{
	int x;
	int y;
	char* msg;
	state* p;
};

queue<state*> Q;
list<state*> L;
int visited[100][100] = {{0}};
state* f;

int a, b, c;

state* state1(state* s0)
{
	if (visited[s0->x][0])
		return NULL;
	
	state* s = new state{s0->x, 0, "Do het nuoc o coc 2", s0};
	visited[s->x][s->y] = 1;
	Q.push(s);
	L.push_back(s);
	return s;
}

state* state2(state* s0)
{
	if (visited[0][s0->y])
		return NULL;
	
	state* s = new state{0, s0->y, "Do het nuoc o coc 1", s0};
	visited[s->x][s->y] = 1;
	Q.push(s);
	L.push_back(s);
	return s;
}

state* state3(state* s0)
{
	if (visited[a][s0->y])
		return NULL;
	
	state* s = new state{a, s0->y, "Do day nuoc vao coc 1", s0};
	visited[s->x][s->y] = 1;
	Q.push(s);
	L.push_back(s);
	return s;
}

state* state4(state* s0)
{
	if (visited[s0->x][b])
		return NULL;
	
	state* s = new state{s0->x, b, "Do day nuoc vao coc 2", s0};
	visited[s->x][s->y] = 1;
	Q.push(s);
	L.push_back(s);
	return s;
}

state* state5(state* s0)
{
	if (s0->x + s0->y < a)
		return NULL;
	if (visited[a][s0->x + s0->y - a])
		return NULL;
	
	state* s = new state{a, s0->x + s0->y - a, "Do nuoc tu coc 2 vao day coc 1", s0};
	visited[s->x][s->y] = 1;
	Q.push(s);
	L.push_back(s);
	return s;
}

state* state6(state* s0)
{
	if (s0->x + s0->y >= a)
		return NULL;
	if (visited[s0->x + s0->y][0])
		return NULL;
	
	state* s = new state{s0->x + s0->y, 0, "Do het nuoc tu coc 2 vao coc 1", s0};
	visited[s->x][s->y] = 1;
	Q.push(s);
	L.push_back(s);
	return s;
}

state* state7(state* s0)
{
	if (s0->x + s0->y < b)
		return NULL;
	if (visited[s0->x + s0->y - b][b])
		return NULL;
	
	state* s = new state{s0->x + s0->y - b, b, "Do nuoc tu coc 1 vao day coc 2", s0};
	visited[s->x][s->y] = 1;
	Q.push(s);
	L.push_back(s);
	return s;
}


state* state8(state* s0)
{
	if (s0->x + s0->y >= b)
		return NULL;
	if (visited[0][s0->x + s0->y])
		return NULL;
	
	state* s = new state{0, s0->x + s0->y, "Do het nuoc tu coc 1 vao coc 2", s0};
	visited[s->x][s->y] = 1;
	Q.push(s);
	L.push_back(s);
	return s;
}

bool check(state* s)
{
	if (s == NULL)
		return false;
	return s->x == c || s->y == c;
}


state* waterJug()
{
		
	while (!Q.empty())
	{
		state* s = Q.front();
		Q.pop();

		if (check(f = state1(s))) return f;
		if (check(f = state2(s))) return f;
		if (check(f = state3(s))) return f;
		if (check(f = state4(s))) return f;
		if (check(f = state5(s))) return f;
		if (check(f = state6(s))) return f;
		if (check(f = state7(s))) return f;
		if (check(f = state8(s))) return f;
	}
}

void print()
{
	stack<state*> S;
	while (f != NULL)
	{
		S.push_back(f);
		f = f->p;
	}
	while (!S.empty())
	{
		state* s = S.top();
		printf("%s, (%d, %d)\n", s->msg, s->x, s->y);
		S.pop();
	}

}

void free()
{
	while(!L.empty())
	{
		delete L.top();
		L.pop();
	}
}

int main()
{
	
	scanf("%d %d %d", &a, &b, &c);
	
	state* s0 = new state();
	s0->x = 0;
	s0->y = 0;
	s0->msg = NULL;
	s0->p = NULL;
	
	Q.push(s0);
	L.push_back(s0);
	visited[0][0] = 1;
	
	waterJug();
	
	print();
	
	free();
	
	return 0;
}
