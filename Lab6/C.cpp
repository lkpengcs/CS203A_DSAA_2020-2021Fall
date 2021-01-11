#include <iostream>
#include <stdio.h>
#include <cstring>
#include <string>
using namespace std;

char str[1010][1010];
int n, q;
int sum = 0;
int nxt[2020];

int nextmax(string s)
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
	return nxt[strlen];
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", str[i]);
	}
	scanf("%d", &q);
	for (int t = 1; t <= q; t++)
	{
		int i, j;
		char tmp[2];
		scanf("%d%d", &i, &j);
		scanf("%s", tmp);
		string stri = str[i];
		string strj = str[j];
		string l = stri + '@' + strj;
		string r = strj + '@' + stri;
		int lmax = nextmax(l);
		int rmax = nextmax(r);
		if (tmp[0] == '>' && lmax > rmax)
		{
			sum++;
		}
		if (tmp[0] == '<' && lmax < rmax)
		{
			sum++;
		}
		if (tmp[0] == '=' && lmax == rmax)
		{
			sum++;
		}
	}
	printf("%d\n", sum);
	return 0;
}