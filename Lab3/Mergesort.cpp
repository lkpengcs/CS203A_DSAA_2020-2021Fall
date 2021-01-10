#include <iostream>
using namespace std;

int a[10] = { 29,18,25,47,58,12,51,10 };
int b[10] = { 0 };

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
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
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
	mergesort(a, 0, 7);
	return 0;
}