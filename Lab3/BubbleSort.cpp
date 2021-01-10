#include <iostream>
using namespace std;

int a[100000 + 10] = { 0 };
int b[100000 + 10] = { 0 };
long long sum = 0;

void merge(int a[], int l, int mid, int r)
{
	int left = l, right = mid + 1;
	int count = 0;
	while (left <= mid && right <= r)
	{
		if (a[left] <= a[right])
		{
			b[count] = a[left];
			left++;
		}
		else
		{
			sum += (long long)mid - left + 1;
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
	int T;
	int n;
	cin >> T;
	while (T > 0)
	{
		T--;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		sum = 0;
		mergesort(a, 0, n - 1);
		cout << sum << endl;
	}
	
	return 0;
}