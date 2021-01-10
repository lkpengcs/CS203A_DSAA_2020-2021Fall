#include <iostream>
#define MOD 1000000007
using namespace std;
int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		long long n;
		cin >> n;
		long long result;
		if (n % 2 == 0)
		{
			result = n / 2;
			long long tmp = n + 1;
			result = result * tmp % MOD;
		}
		else
		{
			result = (n + 1) / 2;
			long long tmp = n;
			result = result * tmp % MOD;
		}
		result = result * result % MOD;
		cout << result << endl;
	}
	return 0;
}