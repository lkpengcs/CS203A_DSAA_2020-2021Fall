#include <iostream>
#include <algorithm>
using namespace std;

int T, n, K;
long long M;
int a[100000 + 10];
int b[100000 + 10];

long long judge(int x)
{
	int r = 0;
	int count = 0;
	long long sum = 0;
	for (int i = 0; i < n; i++)
	{
		while (r < n && count < K)
		{
			if (a[r] >= x)
			{
				count++;
			}
			r++;
		}
		if (count == K)
		{
			sum += (long long) n - r + 1;
		}
		if (a[i] >= x)
		{
			count--;
		}
	}
	return sum;
}

int main()
{
	cin >> T;
	while (T > 0)
	{
		T--;
		cin >> n >> K >> M;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
			b[i] = a[i];
		}
		sort(b, b + n);
		int left = 0, right = n - 1;
		long long result = 0;
		while (left < right)
		{
			int mid = (left + right) / 2 + 1;
			if (judge(b[mid]) >= M)
			{
				result = b[mid];
				left = mid + 1;
			}
			else
			{
				right = mid - 1;
			}
		}
		cout << result << endl;
	}
	return 0;
}