#include <iostream>
using namespace std;

int n, s, a[3000 + 10];

int cal(int l, int num)
{
	int r = n - 1;
	long long sum = 0;
	while (l < r)
	{
		if (a[l] + a[r] == num)
		{
			if (a[l] == a[r])
			{
				long long count =(long long) r - l + 1;
				sum += count * (count - 1) / 2;
				l = r;
			}
			else
			{
				long long count1 = 0;
				long long count2 = 0;
				int al = a[l];
				int ar = a[r];
				while (al == a[l])
				{
					l++;
					count1++;
				}
				while (ar == a[r])
				{
					r--;
					count2++;
				}
				sum += count1 * count2;

			}
		}
		else if (a[l] + a[r] > num)
		{
			r--;
		}
		else
		{
			l++;
		}
	}
	return sum;
}

int main()
{
	cin >> n >> s;
	for (int i = 0; i < n; i++)
	{
		cin >> a[i];
	}
	long long result = 0;
	if (n < 3)
	{
		result = 0;
	}
	else
	{
		for (int i = 0; i < n - 2; i++)
		{
			/*if (i > 0 && a[i] == a[i - 1])
			{
				continue;
			}*/
			result += cal(i + 1, s - a[i]);
		}
		cout << result << endl;
	}
	return 0;
}