#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <cstring>
#include <cstdlib>
using namespace std;

int n, m;
int cnt = 0;
int f[505010];

int getf(int x)
{
	if (f[x] == -1)
	{
		return x;
	}
	else
	{
		return f[x] = getf(f[x]);
	}
}

struct node
{
	int u, v;
	long long w;
}g[1000010];

bool cmp(node x, node y)
{
	return x.w > y.w;
}

int main()
{
	scanf("%d%d", &n, &m);
	long long a[n+10][m+10];
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%lld", &a[i][j]);
		}
	}
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			int x = i - 1, y = j - 1;
			if (x > 0)
			{
				cnt++;
				g[cnt].u = i * m + j + 1, g[cnt].v = x * m + j + 1, g[cnt].w = a[i][j] * a[x][j];
			}				
			if (y > 0)
			{
				cnt++;
				g[cnt].u = i * m + j + 1, g[cnt].v = i * m + y + 1, g[cnt].w = a[i][j] * a[i][y];
			}
		}
	}
	long long sum = 0;
	sort(g + 1, g + cnt + 1, cmp);
	memset(f, -1, sizeof(f));
	int num = 0;
	for (int i = 1; i <= cnt; i++)
	{
		int fx = getf(g[i].u), fy = getf(g[i].v);
		if (fx != fy)
		{
			f[fx] = fy;
			sum += g[i].w;
			num++;
		}
		if (num == n * m - 1)
		{
			break;
		}
	}
	printf("%lld", sum);
	return 0;
}