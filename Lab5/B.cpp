#include <iostream>
#include <stdio.h>
#define N 20000010
using namespace std;

int queue[N];
int head, tail, n;
char c[5];

void push(int x)
{
	if (tail < n)
	{
		queue[tail] = x;
		tail++;
	}
}

void dequeue()
{
	if (head < tail)
	{
		head++;
	}
}

void front()
{
	if (head < tail)
	{
		printf("%d\n", queue[head]);
	}
}

int main()
{
	scanf("%d", &n);
	head = 0; tail = 0;
	for (int i = 1; i <= n; i++)
	{
		scanf("%s", &c);
		if (c[0] == 'E')
		{
			int tmp;
			scanf("%d", &tmp);
			push(tmp);
		}
		else if (c[0] == 'D')
		{
			dequeue();
		}
		else
		{
			front();
		}
	}
	for (int i = head; i < tail; i++)
	{
		printf("%d ", queue[i]);
	}
	return 0;
}