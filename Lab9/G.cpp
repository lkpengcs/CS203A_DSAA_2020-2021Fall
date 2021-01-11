#include <iostream>
#include <stdio.h>
using namespace std;

const int MAXN = 100010;
const int mod = 1e9 + 7;

struct node
{
	int nxt, to;
}edge[MAXN];

int head[MAXN], indeg[MAXN];
long long dp[MAXN], a[MAXN], b[MAXN];
int cnt = 0, T, n, m;

inline void add(int x, int y)
{
	cnt++;
	edge[cnt].to = y;
	edge[cnt].nxt = head[x];
	head[x] = cnt;
}

long long dfs(int x)
{
	if (dp[x] != -1)
	{
		return dp[x];
	}
	dp[x] = 0;
	for (int i = head[x]; i; i = edge[i].nxt)
	{
		int ver = edge[i].to;
		dp[x] = (dp[x] + b[ver] + dfs(ver)) % mod;
	}
	return dp[x];
}

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			head[i] = 0, indeg[i] = 0, dp[i] = -1;
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%lld%lld", &a[i], &b[i]);
		}
		for (int i = 1; i <= m; i++)
		{
			int u, v;
			scanf("%d%d", &u, &v);
			add(u, v);
			indeg[v]++;
		}
		for (int i = 1; i <= n; i++)
		{
			if (indeg[i] == 0)
			{
				dfs(i);
			}
		}
		long long ans = 0;
		for (int i = 1; i <= n; i++)
		{
			ans = (ans + (dp[i] * a[i]) % mod) % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}