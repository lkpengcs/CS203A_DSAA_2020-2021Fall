#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int n, m;
int fa[1010];
long long sum = 0;

struct node
{
	int u, v;
	long long w;
}g[20010];

bool cmp(node a, node b)
{
	return a.w < b.w;
}

int getf(int x)
{
	if (x == fa[x])
	{
		return x;
	}
	else
	{
		return fa[x] = getf(fa[x]);
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		fa[i] = i;
	}
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		long long w;
		scanf("%d%d%lld", &u, &v, &w);
		g[i].u = u, g[i].v = v, g[i].w = w;
	}
	sort(g + 1, g + 1 + m, cmp);
	for (int i = 1; i <= m; i++)
	{
		int fx = getf(g[i].u), fy = getf(g[i].v);
		if (fx != fy)
		{
			fa[fx] = fy;
			sum += g[i].w;
		}
	}
	printf("%lld", sum);
	return 0;
}