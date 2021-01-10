#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		int n;
		int a[200000 + 10] = { 0 };
		int maxArr[200000 + 10] = { 0 };
		cin >> n;
		for (int i = 0; i < n; i++)
		{
			cin >> a[i];
		}
		maxArr[0] = a[0];
		int maxx = -1;
		for (int i = 1; i < n; i++)
		{
			maxArr[i] = max(maxArr[i - 1], a[i]);
			maxx = max(maxArr[i - 1] - a[i], maxx);
		}
		cout << maxx << endl;
	}
	return 0;
}