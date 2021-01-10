#include <iostream>
using namespace std;

int main()
{
	int T, n, m;
	cin >> T;
	while (T > 0)
	{
		T--;
		int a[100000 + 10] = { 0 };
		int b[100000 + 10] = { 0 };
		cin >> n >> m;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		for (int i = 0; i < m; i++)
		{
			cin >> b[i];
		}
		int l = 0;
		int r = 0;
		while (l < n && r < m)
		{
			if (a[l] <= b[r])
			{
				cout << a[l] << ' ';
				l++;
			}
			else
			{
				cout << b[r] << ' ';
				r++;
			}
		}
		while (l < n)
		{
			cout << a[l] << ' ';
			l++;
		}
		while (r < m)
		{
			cout << b[r] << ' ';
			r++;
		}
		cout << endl;
	}
	return 0;
}