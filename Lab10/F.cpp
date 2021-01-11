#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#include <vector>
#include <limits.h>
using namespace std;

struct node
{
	int to, nxt;
	long long w;
}g[50010];

struct point
{
	int u, num;
	long long sum;
	bool operator < (const point& a) const
	{
		return sum > a.sum;
	}
};

priority_queue<point>q;
vector<int>portal[50010];

int n, m, p, k, S, T;
int head[50010];
int cnt = 0;
long long dis[50010][20];
bool vis[50010][20];

inline void add(int x, int y, long long z)
{
	cnt++;
	g[cnt].to = y;
	g[cnt].nxt = head[x];
	g[cnt].w = z;
	head[x] = cnt;
}

int main()
{
	scanf("%d%d%d%d", &n, &m, &p, &k);
	memset(head, 0, sizeof(head));
	for (int i = 1; i <= m; i++)
	{
		int u, v;
		long long w;
		scanf("%d%d%lld", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= p; i++)
	{
		int u, v;
		scanf("%d%d", &u, &v);
		portal[u].push_back(v);

	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 0; j <= k; j++)
		{
			dis[i][j] = LLONG_MAX;
			vis[i][j] = false;
		}
	}
	scanf("%d%d", &S, &T);
	point st;
	st.num = 0, st.u = S, st.sum = 0;
	q.push(st);
	dis[S][0] = 0;
	while (!q.empty())
	{
		point tmp = q.top();
		q.pop();
		int from = tmp.u;
		long long len = tmp.sum;
		int used = tmp.num;
		if (vis[from][used])
			continue;
		vis[from][used] = true;
		for (int i = head[from]; i; i = g[i].nxt)
		{
			int ver = g[i].to;
			if (!vis[ver][used] && dis[ver][used] > dis[from][used] + g[i].w)
			{
				dis[ver][used] = dis[from][used] + g[i].w;
				point newnode;
				newnode.num = used;
				newnode.sum = dis[ver][used];
				newnode.u = ver;
				q.push(newnode);
			}
		}
		if (used < k)
		{
			int portal_len = portal[from].size();
			for (int i = 0; i < portal_len; i++)
			{
				int ver = portal[from][i];
				if (!vis[ver][used + 1] && dis[ver][used + 1] > dis[from][used])
				{
					dis[ver][used + 1] = dis[from][used];
					point newnode;
					newnode.num = used + 1;
					newnode.sum = dis[ver][used + 1];
					newnode.u = ver;
					q.push(newnode);
				}
			}
		}
	}
	long long ans = LLONG_MAX;
	for (int i = 0; i <= k; i++)
	{
		ans = min(ans, dis[T][i]);
	}
	printf("%lld", ans);
	return 0;
}