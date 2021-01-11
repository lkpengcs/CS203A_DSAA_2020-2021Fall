#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

typedef pair< int, int > p;

const int MAXN = 400010;

priority_queue < p, vector<p>, greater<p> > q;

int n, m;
int cnt = 0;
int head[MAXN / 2], dis[MAXN / 2];

struct node
{
	int to, nxt, weight;
}graph[MAXN * 2];

inline void add(int a, int b, int c)
{
	cnt++;
	graph[cnt].to = b;
	graph[cnt].nxt = head[a];
	graph[cnt].weight = c;
	head[a] = cnt;
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++)
	{
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		add(u, v, w);
	}
	dis[1] = 0;
	for (int i = 2; i <= n; i++)
	{
		dis[i] = 2147483647;
	}
	q.push(make_pair(0, 1));
	while (!q.empty())
	{
		p t = q.top();
		q.pop();
		int x = t.first, y = t.second;
		if (x != dis[y])
		{
			continue;
		}
		for (int i = head[y]; i; i = graph[i].nxt)
		{
			if (dis[graph[i].to] > dis[y] + graph[i].weight)
			{
				dis[graph[i].to] = dis[y] + graph[i].weight;
				q.push(make_pair(dis[graph[i].to], graph[i].to));
			}
		}
	}
	if (dis[n] == 2147483647)
	{
		printf("-1");
	}
	else
	{
		printf("%d", dis[n]);
	}
	return 0;
}
