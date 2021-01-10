#include <iostream>
using namespace std;

int n;
long long x1, x2;

struct line
{
	long long y1;
	long long y2;
};

line a[100000 + 10];
line b[100000 + 10];

void merge(line a[], int l, int mid, int r)
{
	int left = l, right = mid + 1;
	int count = 0;
	while (left <= mid && right <= r)
	{
		if (a[left].y1 >= a[right].y1)
		{
			b[count] = a[left];
			left++;
		}
		else
		{
			b[count] = a[right];
			right++;
		}
		count++;
	}
	while (left <= mid)
	{
		b[count] = a[left];
		left++;
		count++;
	}
	while (right <= r)
	{
		b[count] = a[right];
		right++;
		count++;
	}
	int length = r - l + 1;
	for (int i = 0; i < length; i++)
	{
		a[l + i] = b[i];
	}
}

void mergesort(line a[], int l, int r)
{
	if (l == r)
	{
		return;
	}
	else
	{
		int mid = l + (r - l) / 2;
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

int main()
{
	cin >> n >> x1 >> x2;
	for (int i = 0; i < n; i++)
	{
		long long k, b;
		cin >> k >> b;
		a[i].y1 = k * x1 + b;
		a[i].y2 = k * x2 + b;
	}
	mergesort(a, 0, n - 1);
	long long minn = a[0].y2;
	bool flag = false;
	for (int i = 1; i < n; i++)
	{
		if (a[i].y2 > minn && a[i].y1 != a[i-1].y1)
		{
			cout << "YES";
			flag = true;
			break;
		}
		else
		{
			minn = min(minn, a[i].y2);
		}
	}
	if (!flag)
	{
		cout << "NO";
	}
	return 0;
}