#include <iostream>
using namespace std;

int maxheap[300000 + 10];
int minheap[300000 + 10];
int a[300000 + 10];

void maxinsert(int x)
{
	while (x > 1)
	{
		if (maxheap[x] > maxheap[x / 2])
		{
			swap(maxheap[x], maxheap[x / 2]);
			x = x / 2;
		}
		else
		{
			break;
		}
	}
}

void mininsert(int x)
{
	while (x > 1)
	{
		if (minheap[x] < minheap[x / 2])
		{
			swap(minheap[x], minheap[x / 2]);
			x = x / 2;
		}
		else
		{
			break;
		}
	}
}

void maxmodify(int st, int en)
{
	int tmp = st * 2;
	while (tmp <= en)
	{
		if (tmp < en && maxheap[tmp] < maxheap[tmp + 1])
		{
			tmp++;
		}
		if (maxheap[st] < maxheap[tmp])
		{
			swap(maxheap[st], maxheap[tmp]);
			st = tmp;
			tmp = st * 2;
		}
		else
		{
			break;
		}
	}
}

void minmodify(int st, int en)
{
	int tmp = st * 2;
	while (tmp <= en)
	{
		if (tmp < en && minheap[tmp] > minheap[tmp + 1])
		{
			tmp++;
		}
		if (minheap[st] > minheap[tmp])
		{
			swap(minheap[st], minheap[tmp]);
			st = tmp;
			tmp = st * 2;
		}
		else
		{
			break;
		}
	}
}

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		int n;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			maxheap[i] = 0;
			minheap[i] = 0;
			cin >> a[i];
		}
		int count1 = 0;
		int count2 = 0;
		for (int i = 1; i <= n; i++)
		{
			int mid = a[i];
			if (i == 1)
			{
				minheap[++count1] = a[i];
			}
			else
			{
				if (mid < minheap[1])
				{
					maxheap[++count2] = a[i];
					maxinsert(count2);
				}
				else
				{
					minheap[++count1] = a[i];
					mininsert(count1);
				}
			}
			if (i % 2 == 1 && count1 - 1 > count2)
			{
				maxheap[++count2] = minheap[1];
				maxinsert(count2);
				minheap[1] = minheap[count1--];
				minmodify(1, count1);
			}
			else if (i % 2 == 1 && count1 - 1 < count2)
			{
				minheap[++count1] = maxheap[1];
				mininsert(count1);
				maxheap[1] = maxheap[count2--];
				maxmodify(1, count2);
			}
			if (i % 2 == 1)
			{
				cout << minheap[1] << ' ';
			}
		}
		cout << endl;
	}
	return 0;
}