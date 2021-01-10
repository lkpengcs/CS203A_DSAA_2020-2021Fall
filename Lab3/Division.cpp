#include <iostream>
using namespace std;

int n, m;
long long a[300000 + 10] = { 0 };
long long sum[300000 + 10] = { 0 };
long long b[300000 + 10] = { 0 };

void merge(long long a[], int l, int mid, int r)
{
	int left = l, right = mid + 1;
	int count = 0;
	while (left <= mid && right <= r)
	{
		if (a[left] >= a[right])
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

void mergesort(long long a[], int l, int r)
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
	cin >> n >> m;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	a[n] = 0;
	sum[n] = 0;
	for (int i = n - 1; i > -1; i--)
	{
		sum[i] = sum[i + 1] + a[i];
	}
	mergesort(sum, 1, n - 1);
	long long result = 0;
	for (int i = 0; i < m; i++)
	{
		result += sum[i];
	}
	cout << result << endl;
	return 0;
}