#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

const int MAXN = 100010;

int n, m;
int cnt = 0;
int head[MAXN], deg[MAXN], vis[MAXN];

struct node
{
	int to, nxt;
}graph[MAXN * 2];

queue<int>q;

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
	for (int i = 1; i <= n; i++)
	{
		head[i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		deg[u]++, deg[v]++;
		add(u, v);
		add(v, u);
	}
	for (int i = 1; i <= n; i++)
	{
		if (deg[i] <= 1)
		{
			q.push(i);
			vis[i] = 1;
		}
	}
	while (!q.empty())
	{
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = graph[i].nxt)
		{
			int ver = graph[i].to;
			if (!vis[ver])
			{
				deg[ver]--;
				if (deg[ver] == 1)
				{
					q.push(ver);
					vis[ver] = 1;
				}
			}
		}
	}
	bool flag = true;
	for (int i = 1; i <= n; i++)
	{
		if (!vis[i])
		{
			flag = false;
			break;
		}
	}
	if (flag)
	{
		printf("Good");
	}
	else
	{
		printf("Bad");
	}
	return 0;
}