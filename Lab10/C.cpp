#include <iostream>
#include <cstdio>
#include <queue>
#include <cmath>
#include <float.h>
using namespace std;

struct node
{
	int x, y;
	double dis;
	bool operator < (const node &a) const
	{
		return dis > a.dis;
	}
};

priority_queue<node> q;

int n, m;
int grid[310][310];
double dis[310][310], v[310][310], t[310][310];
bool vis[310][310];
int dx[4] = {1, -1, 0, 0}, dy[4] = {0, 0, 1, -1};

int main()
{
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			scanf("%d", &grid[i][j]);
			dis[i][j] = DBL_MAX;
		}
	}
	v[1][1] = 1;
	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= m; j++)
		{
			v[i][j] = v[1][1] * pow(2, grid[1][1] - grid[i][j]);
			t[i][j] = 1.0 / v[i][j];
		}
	}
	dis[1][1] = 0;
	node st;
	st.x = 1, st.y = 1, st.dis = 0;
	q.push(st);
	while (!q.empty())
	{
		node tmp = q.top();
		q.pop();
		int tmpx = tmp.x, tmpy = tmp.y;
		if (vis[tmpx][tmpy])
			continue;
		vis[tmpx][tmpy] = true;
		for (int i = 0; i < 4; i++)
		{
			int newx = tmpx + dx[i], newy = tmpy + dy[i];
			if (newx > 0 && newx <= n && newy > 0 && newy <= m)
			{
				if (!vis[newx][newy])
				{
					if (dis[newx][newy] > dis[tmpx][tmpy] + t[tmpx][tmpy])
					{
						dis[newx][newy] = dis[tmpx][tmpy] + t[tmpx][tmpy];
						node nxt;
						nxt.x = newx, nxt.y = newy, nxt.dis = dis[newx][newy];
						q.push(nxt);
					}
				}
			}
		}
	}
	printf("%.2f", dis[n][m]);
	return 0;
}