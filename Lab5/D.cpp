#include <iostream>
#include <stdio.h>
using namespace std;

int T, n, q;
int top = -1;
int ans[200000 + 10];

struct node
{
	int id;
	int val;
};

node odata[200000 + 10], op[200000 + 10];

void push(node x)
{
	if (top < n - 1)
	{
		top++;
		op[top] = x;
	}
}

node peek()
{
	if (top != -1)
	{
		return op[top];
	}
}

void pop()
{
	if (top >= 0)
	{
		top--;
	}
}

int main()
{
	scanf("%d", &T);
	while (T > 0)
	{
		top = -1;
		T--;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &odata[i].val);
			odata[i].id = i;
		}
		for (int i = n; i >= 1; i--)
		{
			if (top == -1)
			{
				ans[i] = -1;
				push(odata[i]);
			}
			else
			{
				node stop = peek();
				while (odata[i].val >= stop.val)
				{
					pop();
					if (top != -1)
					{
						stop = peek();
					}
					else
					{
						break;
					}
				}
				if (odata[i].val >= stop.val)
				{
					ans[i] = -1;
				}
				else
				{
					ans[i] = stop.id - i;
				}
				push(odata[i]);
			}
		}
		scanf("%d", &q);
		int k;
		for (int i = 1; i <= q; i++)
		{
			scanf("%d", &k);
			printf("%d\n", ans[k]);
		}
	}
	return 0;
}