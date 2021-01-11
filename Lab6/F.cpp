#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <map>
#include <algorithm>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;

int nxt[500010];
char alphabet[26] = { 'a','b', 'c', 'd', 'e', 'f', 'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p', 'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z'};
char table[3], text[500010], tmp[500010];

void getnext()
{
	int len = strlen(text);
	nxt[0] = -1;
	int k = -1;
	int j = 0;
	while (j < len) {
		if (k == -1 || text[k] == text[j])
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

		map<char, char>m;
		for (int i = 0; i < 26; i++)
		{
			cin >> table;
			m[table[0]] = alphabet[i];
		}
		cin >> text;
		int len = strlen(text);
		int tlen = len;
		for (int i = 0; i < len; i++)
		{
			tmp[i] = text[i];
		}
		len /= 2;
		if (tlen % 2 == 1)
		{
			len++;
		}
		for (int i = 0; i < len; i++)
		{
			text[i] = m[text[i]];
		}
		getnext();
		int maxx = nxt[tlen];
		if (maxx > tlen / 2)
		{
			maxx = tlen / 2;
		}
		int tmplen = tlen - maxx;
		cout << tmplen;

	return 0;
}