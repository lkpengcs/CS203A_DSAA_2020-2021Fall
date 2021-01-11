#include <iostream>
#include <stdio.h>
#define MAXN 100010
using namespace std;

int n, k;
int cnt = 0;
int head[MAXN];
int ans = 0, id = -1;
int vis[MAXN], a[MAXN];

struct node
{
	int nex;
	int to;
}tree[MAXN * 2];

inline void add(int x, int y)
{
	cnt++;
	tree[cnt].to = y;
	tree[cnt].nex = head[x];
	head[x] = cnt;
	
}

void dfs(int x, int f, int d) 
{
	if (d > ans && vis[x])
	{
		ans = d;
		id = x;
	}
		for (int i = head[x]; i; i = tree[i].nex)
		{
			int v = tree[i].to;
			if (v != f)
			{
				dfs(v, x, d + 1);
			}
		}
	
}

int main()
{
	int T;
	scanf("%d", &T);
	while (T > 0)
	{
		cnt = 0, ans = 0, id = 0;
		T--;
		scanf("%d%d", &n, &k);
		for (int i = 1; i <= n; i++)
		{
			head[i] = 0;
			vis[i] = 0;
		}
		for (int i = 1; i <= n - 1; i++)
		{
			int a, b;
			scanf("%d%d", &a, &b);
			add(a, b);
			add(b, a);
		}
		int tmp;
		for (int i = 1; i <= k; i++)
		{
			scanf("%d", &a[i]);
			vis[a[i]] = 1;
			tmp = a[i];
		}
		dfs(tmp, 0, 0);
		ans = 0;
		dfs(id, 0, 0);
		printf("%d\n", (ans + 1) / 2);
	}
	return 0;
}