#include <iostream>
using namespace std;

int main()
{
	int n, m, L;
	int p[100000 + 10];
	int di[100000 + 10];
	int l = 0, r = 0;
	cin >> n >> m >> L;
	for (int i = 0; i < n; i++)
	{
		cin >> p[i];
	}
	p[n] = L;
	for (int i = 0; i < n; i++)
	{
		di[i] = p[i + 1] - p[i];
		l = max(l, di[i]);
		r += di[i];
	}
	while (l < r)
	{
		int mid = (l + r) >> 1;
		int count = 1;
		int sum = di[0];
		for (int i = 1; i < n; i++)
		{
			if (sum + di[i] <= mid)
			{
				sum += di[i];
			}
			else
			{
				count++;
				if (count > m)
				{
					break;
				}
				sum = di[i];
			}
		}
		if (count > m)
		{
			l = mid + 1;
		}
		else
		{
			r = mid;
		}
	}
	cout << r;
	return 0;
}