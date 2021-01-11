#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

int a[1010];
priority_queue <int, vector<int>, greater<int> > q;
int main()
{
	int T, n;
	int tlen;
	scanf("%d", &T);
	while (T > 0)
	{
		tlen = 0;
		T--;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &a[i]);
			q.push(a[i]);
		}
		while (q.size() >= 2)
		{
			int x = q.top();
			q.pop();
			int y = q.top();
			q.pop();
			int tmp = x + y;
			tlen += tmp;
			q.push(tmp);
		}
		while (!q.empty())
		{
			q.pop();
		}
		printf("%d\n", tlen);
	}
	return 0;
}