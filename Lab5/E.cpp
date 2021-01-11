#include <iostream>
#include <stdio.h>
#include <queue>
using namespace std;

struct node
{
	int frequency;
	int col;
	int order;
	bool operator<(const node& a) const
    {
		if (frequency == a.frequency) 
		{
			return order < a.order;
		}
		else
		{
			return frequency < a.frequency;
		}
    }
};

priority_queue<node> q;
int m[100000 + 10];

int main()
{
	char str[10];

	int color;
	int count = 0;
	int total = 0;
	for (int i = 1; i <= 100000; i++)
	{
		m[i] = 0;
	}
	while (true)
	{
		scanf("%s", str);
		if (str[0] == 'n')
		{
			break;
		}
		else if (str[0] == 'p')
		{
			scanf("%d", &color);
			count++;
			total++;
			node tmp;
			tmp.col = color;
			tmp.frequency = m[color] + 1;
			m[color]++;
			tmp.order = count;
			q.push(tmp);
		}
		else
		{
			if (total == 0)
			{
				printf("pa\n");
			}
			else
			{
				node tmp = q.top();
				m[tmp.col]--;
				printf("%d\n", tmp.col);
				q.pop();
				total--;
			}
		}
	}
	return 0;
}