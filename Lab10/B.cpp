#include <iostream>
#include <stdio.h>
#define MAXN 200010
using namespace std;

struct node
{
	int to;
	int nxt;
}g1[MAXN], g2[MAXN];

int n, m;
int head1[MAXN], head2[MAXN];
int cnt1 = 0, cnt2 = 0;
int vis[MAXN];
int order_cnt = 1;

inline void add1(int x, int y)
{
	cnt1++;
	g1[cnt1].to = y;
	g1[cnt1].nxt = head1[x];
	head1[x] = cnt1;
}

inline void add2(int x, int y)
{
	cnt2++;
	g2[cnt2].to = y;
	g2[cnt2].nxt = head2[x];
	head2[x] = cnt2;
}

void dfs(int x, int head[], node g[])
{
	for (int i = head[x]; i; i = g[i].nxt)
	{
		int ver = g[i].to;
		if (!vis[ver])
		{
			order_cnt++;
			vis[ver] = 1;
			dfs(ver, head, g);
		}
	}
}

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		head1[i] = 0, head2[i] = 0;
	}
	for (int i = 1; i <= m; i++)
	{
		int x, y;
		scanf("%d%d", &x, &y);
		add1(x, y);
		add2(y, x);
	}
	vis[1] = 1;
	dfs(1, head1, g1);
	if (order_cnt != n)
	{
		printf("wawawa");
	}
	else
	{
		order_cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			vis[i] = 0;
		}
		dfs(1, head2, g2);
		if (order_cnt != n)
		{
			printf("wawawa");
		}
		else
		{
			printf("Bravo");
		}
	}
	return 0;
}