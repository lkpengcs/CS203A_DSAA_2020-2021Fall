#include <iostream>
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

struct node
{
	int id;
	vector<node>next;
};

node a[100010];

int main()
{
	int T, n;
	scanf("%d", &T);
	while (T > 0)
	{
		T--;
		scanf("%d", &n);
		int tmp;
		for (int i = 1; i < n; i++)
		{
			scanf("%d", &tmp);
			node tmpnode;
			tmpnode.id = i + 1;
			a[tmp].next.push_back(tmpnode);
		}
		queue<int>q;
		a[1].id = 1;
		q.push(1);
		while (!q.empty())
		{
			int x = q.front();
			printf("%d ", x);
			q.pop();
			int len = a[x].next.size();
			if (len)
			{
				for (int i = 0; i < len; i++)
				{
					q.push(a[x].next[i].id);
				}
			}
			a[x].next.clear();
		}
		printf("\n");
	}
	return 0;
}