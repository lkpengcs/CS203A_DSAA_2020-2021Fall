#include <iostream>
using namespace std;

int a[10] = { 29,18,25,47,58,12,51,10 };

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
	for (int i = 0; i < 8; i++)
	{
		cout << a[i] << ' ';
	}
	cout << endl;
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
	if (l < r)
	{
		int po = partition(l, r);
		quicksort(l, po - 1);
		quicksort(po + 1, r);
	}
}

int main()
{
	quicksort(0, 7);
	return 0;
}