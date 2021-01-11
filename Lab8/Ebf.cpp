#pragma GCC optimize(3, "Ofast", "inline")

#include <iostream>
#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int n, l, k;
int a[100010];
vector<int>v;

inline int read() {
	char ch = getchar();
	int x = 0, f = 1;
	while (ch < '0' || ch > '9') {
		if (ch == '-')
			f = -1;
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x * f;
}

int main()
{
	n = read(), l = read();
	for (int i = 0; i < n; i++)
	{
		a[i] = read();
	}
	for (int i = 0; i < l; i++)
	{
		v.push_back(a[i]);
	}
	sort(v.begin(), v.end());
	k = read();
	printf("%d\n", v[k - 1]);
	for (int i = 0; i < n - l; i++)
	{
		k = read();
		bool judge = false;
		for (int j = 0; j < l; j++)
		{
			if (v[j] == a[i])
			{
				v.erase(v.begin() + j);
				break;
			}
		}
		for (int j = 0; j < l - 1; j++)
		{
			if (v[j] >= a[i + l])
			{
				v.insert(v.begin() + j, a[i + l]);
				judge = true;
				break;
			}
		}
		if (!judge)
		{
			v.push_back(a[i + l]);
		}
		printf("%d\n", v[k - 1]);
	}
	return 0;
}