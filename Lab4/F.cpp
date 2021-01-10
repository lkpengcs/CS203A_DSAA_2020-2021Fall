#include <iostream>
#include <stdio.h>
#include <string.h>
#include <string>
using namespace std;

const int N = 502;

char s[200000 + 10];
char a[N][N * 21];
int len[N];
int numofl, lenofl;

char find(int x)
{
	int count = 0;
	for (int i = 0; i < numofl; i++)
	{
		if (count + len[i] >= x)
		{
			return a[i][x - count - 1];
		}
		count += len[i];
	}
}

void insert(int x, char c)
{
	int count = 0;
	int row = 0;
	for (int i = 0; i < numofl; i++)
	{
		if (count + len[i] >= x)
		{
			row = i;
			break;
		}
		if (i == numofl - 1)
		{
			row = numofl - 1;
			break;
		}
		count += len[i];
	}
	int p = x - count - 1;
	if (p >= len[row])
	{
		p = len[row];
	}
	for (int i = len[row]; i > p; i--)
	{
		a[row][i] = a[row][i - 1];
	}
	a[row][p] = c;
	len[row]++;
}

int main()
{
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	int T;
	scanf("%d", &T);
	while (T > 0)
	{
		T--;
		int n;
		scanf("%s%d", s, &n);
		
		int strlength = strlen(s);
		lenofl = (strlength + N - 1) / N;
		numofl = (strlength - 1) / lenofl + 1;
		for (int i = 0; i < numofl; i++)
		{
			len[i] = lenofl;
		}
		for (int i = 0; i < strlength; i++)
		{
			a[i / lenofl][i % lenofl] = s[i];
		}
		len[numofl - 1] = (strlength - 1) % lenofl + 1;
		while (n > 0)
		{
			n--;
			int operate;
			char op[3];
			int pos;
			scanf("%d", &operate);
			if (operate == 1)
			{
				scanf("%s%d", op, &pos);
				insert(pos, op[0]);
			}
			else
			{	
				scanf("%d", &pos);
				printf("%c\n", find(pos));
			}
		}
	}
	return 0;
}