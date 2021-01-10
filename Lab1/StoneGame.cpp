#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		int a[100000 + 10] = { 0 };
		int n;
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		int sum = a[0];
		for (int i = 1; i < n; i++)
		{
			sum = sum ^ a[i];
		}
		int count = 0;
		for (int i = 0; i < n; i++)
		{
			if (a[i] > (sum ^ a[i]))
			{
				count++;
			}
		}
		cout << count << endl;
	}
	return 0;
}