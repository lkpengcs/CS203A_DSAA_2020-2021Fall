#include <iostream>
using namespace std;

int selection(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n - 1; i++)
	{
		int k = i;
		for (int j = i + 1; j < n; j++)
		{
			if (a[k] > a[j])
			{
				k = j;
			}
			count++;
		}
			swap(a[i], a[k]);
			count++;
	}
	return count;
}

int insertion(int a[], int n)
{
	int count = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = i; j > 0; j--)
		{
			count++;
			if (a[j - 1] > a[j])
			{
				swap(a[j - 1], a[j]);
				count++;
			}
			else
			{
				break;
			}
		}
	}
	return count;
}

int main()
{
	int T, n;
	cin >> T;
	while (T > 0)
	{
		T--;
		cin >> n;
		int a[1000 + 10] = { 0 };
		int b[1000 + 10] = { 0 };
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[i] = a[i];
		}
		int insertCount = insertion(a, n);
		int selectCount = selection(b, n);
		for (int i = 0; i < n; i++)
		{
			cout << a[i] << ' ';
		}
		cout << endl;
		if (insertCount < selectCount)
		{
			cout << "Insertion Sort wins!" << endl;
		}
		else
		{
			cout << "Selection Sort wins!" << endl;
		}
	}
	return 0;
}