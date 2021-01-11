#include <iostream>
#include <stdio.h>
using namespace std;

int T, n, m;
int a[1010][1010];

int main()
{
	scanf("%d", &T);
	while (T--)
	{
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				a[i][j] = 0;
			}
		}
		int u, v;
		for (int i = 1; i <= m; i++)
		{
			scanf("%d%d", &u, &v);
			a[u][v]++;
		}
		for (int i = 1; i <= n; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				printf("%d ", a[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}