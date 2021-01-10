#include <iostream>
using namespace std;

int a[100000 + 10];
int bad[100000 + 10];
int nxt[100000 + 10];
int pre[100000 + 10];
int p[100000 + 10];

bool check(int x)
{
	if (pre[x] == -1)
	{
		return true;
	}
	else
	{
		if (a[pre[x]] <= a[x] && a[x] <= a[nxt[x]])
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void deletep(int x)
{
	if (pre[x] != -1 && nxt[x] != -1)
	{
		nxt[pre[x]] = nxt[x];
		pre[nxt[x]] = pre[x];
		pre[x] = -1;
		nxt[x] = -1;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> a[i];
			nxt[i] = i + 1;	pre[i] = i - 1; p[i] = i;
		}
		a[0] = -1; a[n + 1] = 100010;
		nxt[0] = 1; nxt[n + 1] = -1;
		pre[0] = -1; pre[n + 1] = n;
		while (true)
		{
			bool flag = true;
			int countbad = 0;
			for (int i = 1; i <= n; i++)
			{
				if (!check(p[i]))
				{
					bad[++countbad] = p[i];
					flag = false;
				}
			}
			if (flag)
			{
				break;
			}
			int count = 0;
			for (int i = 1; i <= countbad; i++)
			{
				if (a[pre[bad[i]]] != -1 && a[pre[bad[i]]] <= a[bad[i]])
				{
					p[++count] = pre[bad[i]];
				}
				if (a[nxt[bad[i]]] != 100010 && a[nxt[bad[i]]] >= a[bad[i]])
				{
					p[++count] = nxt[bad[i]];
				}
			}
			n = count;
			for (int i = 1; i <= countbad; i++)
			{
				deletep(bad[i]);
			}
		}
		int st = nxt[0];
		while (a[st] != 100010)
		{
			cout << a[st] << ' ';
			st = nxt[st];
		}
		cout << endl;
	}
	return 0;
}