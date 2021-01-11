#include <iostream>
#include <stdio.h>
using namespace std;

const int N = 100010;

struct node
{
	int nxt, to;
}graph[N * 2];

int cnt = 0, m, a, b;
int head[N];

long long total = 0, num1 = 0, num2 = 0, num3 = 0, n;

inline void add(int x, int y)
{
	cnt++;
	graph[cnt].to = y;
	graph[cnt].nxt = head[x];
	head[x] = cnt;
}

void dfs(int x, int f, int v1, int v2, bool flag)
{
	for (int i = head[x]; i; i = graph[i].nxt)
	{
		int ver = graph[i].to;
		if (ver != f)
		{
			if (ver == v1 || ver == v2)
			{
				flag = true;

			}

		}
	}
}

int main()
{
	scanf("%lld%d%d%d", &n, &m, &a, &b);
	if (a > b)
	{
		swap(a, b);
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		add(u, v), add(v, u);
	}
	total = n * (n - 1) / 2;

	return 0;
}