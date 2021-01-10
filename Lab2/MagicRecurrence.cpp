#include <iostream>
using namespace std;
int main()
{
	int a[1000000 + 10] = { 0 };
	a[1] = a[2] = a[3] = 1;
	for (int i = 4; i < 1000001; i++)
	{
		a[i] = a[i / 2 - 1] + a[i / 2] + a[i / 2 + 1];
	}
	int T, n;
	cin >> T;
	while (T > 0)
	{
		T--;
		cin >> n;
		cout << a[n] << endl;
	}
	return 0;
}