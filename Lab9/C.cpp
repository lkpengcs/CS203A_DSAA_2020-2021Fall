#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAXN = 100010;

int n, m;
int cnt = 0;
int head[MAXN], indeg[MAXN];

struct node
{
	int to, nxt;
}graph[MAXN];

priority_queue < int, vector<int>, greater<int> > q;

inline void add(int a, int b)
{
	cnt++;
	graph[cnt].to = b;
	graph[cnt].nxt = head[a];
	head[a] = cnt;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add(x, y);
		indeg[y]++;
	}
	for (int i = 1; i <= n; i++)
	{
		if (!indeg[i])
		{
			q.push(i);
		}
	}
	while (!q.empty())
	{
		int x = q.top();
		q.pop();
		printf("%d ", x);
		for (int i = head[x]; i; i = graph[i].nxt)
		{
			int ver = graph[i].to;
			indeg[ver]--;
			if (!indeg[ver])
			{
				q.push(ver);
			}
		}
	}
	return 0;
}