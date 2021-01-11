#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

struct node
{
	int value;
	int id;
};

int n, k;
node a[3000000 + 10];
node in[3000000 + 10];
node de[3000000 + 10];

int inhead, intail, dehead, detail;

void update(int x)
{
	while (a[x].value >= in[intail].value && intail >= inhead)
	{
		intail--;
	}
	in[++intail] = a[x];
	while (a[x].value <= de[detail].value && detail >= dehead)
	{
		detail--;
	}
	de[++detail] = a[x];
}

int main()
{
	int maxlen = 1;
	int len = 1;
	inhead = dehead = 1;
	intail = detail = 1;
	scanf("%d%d", &k, &n);
	for (int i = 1; i <= n; i++)
	{
		scanf("%d", &a[i].value);
		a[i].id = i;
	}
	int l = 1, r = 2;
	in[1] = a[1], de[1] = a[1];
	while (r <= n)
	{
		update(r);
		len++;
		if (de[1].value - in[1].value > k)
		{
			maxlen = max(len - 1, maxlen);
			if (in[1].id < de[1].id)
			{
				l = in[1].id + 1;
				inhead++;
			}
			else
			{
				l = de[1].id + 1;
				dehead++;
			}
			len = r - l + 1;
		}
		r++;
	}
	printf("%d", maxlen);
	return 0;
}