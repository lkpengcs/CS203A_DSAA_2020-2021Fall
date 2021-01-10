#include <iostream>
using namespace std;
#define MOD 1000000007

int main()
{
	int T;
	cin >> T;
	for (int i = 0; i < T; i++)
	{
		int n;
		cin >> n;
		long long result;
		if (n == 1)
		{
			cout << 2 << endl;
		}
		else if (n == 2)
		{
			cout << 8 << endl;
		}
		else
		{
			result = 8;
			for (int j = 3; j <= n; j++)
			{
				result = ((3 * result) % MOD + 2)%MOD;
			}
			cout << result << endl;
		}
	}
	return 0;
}