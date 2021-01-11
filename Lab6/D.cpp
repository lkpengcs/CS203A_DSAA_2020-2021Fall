#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
using namespace std;

int n;
char str[200010];
int nxt[200010];

void getnext(string s)
{
	int strlen = s.length();
	nxt[0] = -1;
	int k = -1;
	int j = 0;
	while (j < strlen) {
		if (k == -1 || s[k] == s[j])
		{
			nxt[++j] = ++k;
		}
		else
		{
			k = nxt[k];
		}
	}
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d", &n);
	for (int t = 1; t <= n; t++)
	{
		scanf("%s", str);
		string s = str;
		int strlen = s.length();
		getnext(s);
		int len = strlen - nxt[strlen];
		if (len != strlen && strlen % len == 0)
		{
			printf("0\n");
		}
		else
		{
			printf("%d\n", len - strlen % len);
		}
	}
	return 0;
}