#include <iostream>
using namespace std;

struct node
{
	int value, next, pre;
};

node a[100000 + 10];

int main()
{
	int n, T, k;
	cin >> T;
	while (T > 0)
	{
		T--;
		cin >> n >> k;
		for (int i = 1; i <= n; i++)
		{
			a[i].value = i;
			a[i].next = i + 1;
			a[i].pre = i - 1;
		}
		a[1].pre = n;
		a[n].next = 1;
		int number = n;
		int po = 1;
		while (number != 0)
		{
			number--;
			for (int i = 1; i < k-1; i++)
			{
				po = a[po].next;
			}
			cout << a[a[po].next].value << ' ';
			a[po].next = a[a[po].next].next;
			po = a[po].next;
		}
		cout << endl;
	}
	return 0;
}