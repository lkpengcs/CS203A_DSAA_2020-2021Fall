#include <iostream>
#include <stdio.h>
#include <vector>
#define MAXN 100010
using namespace std;

int T, n;
int cnt = 0;
int head[MAXN];
int vis[MAXN], a[MAXN], num[MAXN];

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

bool check1(int x, int f)
{
	if (num[x] == 2)
	{

	}
	for (int i = head[x]; i; i = tree[i].nex)
	{
		int y = tree[i].to;
		if (y != f)
		{
			if (num[x] < 2 && num[y] > 0)
			{
				return false;
			}
			if (a[y] < a[x])
			{
				return false;
			}
			else
			{
				return check1(y, x);
			}
		}
	}
	return true;
}

bool check2(int x, int f)
{
	for (int i = head[x]; i; i = tree[i].nex)
	{
		int y = tree[i].to;
		if (y != f)
		{
			if (num[x] < 2 && num[y] > 0)
			{
				return false;
			}
			if (a[y] > a[x])
			{
				return false;
			}
			else
			{
				return check2(y, x);
			}
		}
	}
	return true;
}

int main()
{
	scanf("%d", &T);
	for (int t = 1; t <= T; t++)
	{
		scanf("%d", &n);
		cnt = 0;
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			vis[i] = 0;
			head[i] = 0;
			num[i] = 0;
		}
		int x, y;
		int cnt1 = 0, cnt2 = 0;
		bool flag = true;
		for (int i = 1; i < n; i++)
		{
			scanf("%d%d", &x, &y);
			add(x, y);
			add(y, x);
			vis[y] = 1;
			num[x]++;
			if (num[x] > 2)
			{
				flag = false;
			}
		}
		if (!flag)
		{
			printf("Case #%d: NO\n", t);
		}
		else
		{
			int root = 0;
			for (int i = 1; i <= n; i++)
			{
				if (vis[i] == 0)
				{
					root = i;
					break;
				}
			}
			if (check1(root, 0) || check2(root, 0))
			{
				printf("Case #%d: YES\n", t);
			}
			else
			{
				printf("Case #%d: NO\n", t);
			}
		}		
	}
	return 0;
}