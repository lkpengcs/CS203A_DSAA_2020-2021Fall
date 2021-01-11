#include <iostream>
#include <stdio.h>
#include <cmath>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;

int n, k;
int a[3000000 + 10];

int main()
{
	int maxlen = 1;
	int minn, maxn;
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n - maxlen; i++)
	{
		minn = a[i], maxn = a[i];
		for (int j = i + 1; j <= n; j++)
		{
			minn = minn < a[j] ? minn : a[j];
			maxn = maxn > a[j] ? maxn : a[j];
			if (maxn - minn <= k)
			{
				maxlen = maxlen > (j - i + 1) ? maxlen : (j - i + 1);
			}
			else
			{
				break;
			}
		}
	}
	printf("%d", maxlen);
	return 0;
}