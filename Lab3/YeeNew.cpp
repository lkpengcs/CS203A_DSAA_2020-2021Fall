#include <iostream>
#include <stdio.h>
using namespace std;

int a[5000000 + 10] = { 0 };
int b[5000000 + 10] = { 0 };

int n, k;

int partition(int l, int r)
{
	int i = l - 1;
	int value = a[r];
	for (int j = l; j < r; j++)
	{
		if (a[j] <= value)
		{
			i++;
			swap(a[i], a[j]);
		}
	}
	swap(a[i + 1], a[r]);
	return i + 1;
}
/*
int randomPartition(int l, int r)
{
	int i = rand() % (r - l + 1) + l;
	swap(a[i], a[r]);
	return partition(l, r);
}*/

void quicksort(int l, int r)
{
	if (l == r && l == k - 1) {
		cout << a[k - 1] << endl;
	}
	if (l < r)
	{
		int po = partition(l, r);
		if (po < k - 1)
		{
			quicksort(po + 1, r);
		}
		else if (po > k - 1)
		{
			quicksort(l, po - 1);
		}
		else
		{
			cout << a[k - 1] << endl;
		}
	}
}

int main()
{
	//scanf("%d%d", &n, &k);
	cin >> n >> k;
	for (int i = 0; i < n; i++)
	{
		scanf("%d", &a[i]);
		//cin >> a[i];
	}
	//srand(time(NULL));
	/*
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % n;
	}*/
	int l = 0, r = n - 1;
	quicksort(l, r);
/*	for (int i = 0; i < n; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;*/
	return 0;
}