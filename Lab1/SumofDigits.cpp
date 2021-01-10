#include <iostream>
#include <cmath>
using namespace std;

bool judge(long long x, long long y)
{
	long long sum = 0;
	while (x != 0)
	{
		sum += x % 10;
		x /= 10;
		if (sum > y)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int t;
	cin >> t;
	while (t > 0)
	{
		t--;
		long long n, s,count = 0,countTime=0;
		cin >> n >> s;
		while (!judge(n, s))
		{
			count += (long long)(10 - (n % 10)) *(long long) pow(10, countTime);
			n += 10 - (n % 10);
			n /= 10;
			countTime++;
		}
		cout << count << endl;
	}
	return 0;
}