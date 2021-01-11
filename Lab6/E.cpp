#include <iostream>
#include <stdio.h>
#include <string>
#include <cstring>
#include <vector>
#include <algorithm>
#pragma GCC optimize(3,"Ofast","inline")
using namespace std;

vector<unsigned long long>v;
const int base = 139;
string str1, str2;

bool judge(int x)
{
	v.clear();
	int str1len = str1.length(), str2len = str2.length();
	unsigned long long p = 1, h = 0;
	for (int i = 0; i < x; i++)
	{
		h = str1[i] + h * base;
		p = p * base;
	}
	v.push_back(h);
	for (int i = x; i < str1len; i++)
	{
		h = h * base + str1[i] - p * str1[i - x];
		v.push_back(h);
	}
	h = 0;
	sort(v.begin(), v.end());
	for (int i = 0; i < x; i++)
	{
		h = str2[i] + h * base;
	}
	if (binary_search(v.begin(), v.end(), h))
	{
		return true;
	}
	for (int i = x; i < str2len; i++)
	{
		h = h * base + str2[i] - p * str2[i - x];
		if (binary_search(v.begin(), v.end(), h))
		{
			return true;
		}
	}
	return false;
}

int main()
{
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> str1 >> str2;
	int l = 0, r = str1.length() > str2.length() ? str2.length() : str1.length();
	while (l <= r)
	{
		int mid = l + (r - l) / 2;
		if (judge(mid))
		{
			l = mid + 1;
		}
		else
		{
			r = mid - 1;
		}
	}
	cout << r;
	return 0;
}