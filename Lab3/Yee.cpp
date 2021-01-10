#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int b[5000000 + 10] = { 0 };

void merge(int a[], int l, int mid, int r)
{
	int left = l, right = mid + 1;
	int count = 0;
	while (left <= mid && right <= r)
	{
		if (a[left] < a[right])
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

void mergesort(int a[], int l, int r)
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
	int n, k;
	cin >> n >> k;
	int a[5000000 + 10] = { 0 };
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	mergesort(a, 0, n - 1);
	cout << a[k - 1];
	return 0;
}