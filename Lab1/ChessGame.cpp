#include <iostream>
using namespace std;

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		int n, m;
		cin >> n >> m;
		if (n == 1 && m == 1)
		{
			cout << "Bob" << endl;
		}
		else
		{
			cout << "Alice" << endl;
		}
	}
	return 0;
}