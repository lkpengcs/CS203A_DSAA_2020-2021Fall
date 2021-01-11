#include <iostream>
#include <string>
#include <cstring>
#include <stdio.h>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int n;
	string str;
	string tmp;
	int prefix = 10000, suffix = 10000;
	cin >> n;
	cin >> str;
	int strlen = str.length();
	for (int t = 0; t < n - 1; t++)
	{
		cin >> tmp;
		int l = 0, r = tmp.length() - 1;
		int tmplen = strlen - 1;
		int tmpprefix = 0, tmpsuffix = 0;
		while (l <= r && str[l] == tmp[l])
		{
			l++, tmpprefix++;
		}
		while (r >= 0 && tmplen >= 0 && str[tmplen] == tmp[r])
		{
			r--, tmplen--, tmpsuffix++;
		}
		prefix = (prefix < tmpprefix) ? prefix : tmpprefix;
		suffix = (suffix < tmpsuffix) ? suffix : tmpsuffix;
	}
	cout << prefix * suffix;
	return 0;
}