#include <iostream>
using namespace std;

int d[100000 + 10] = { 0 };
int e[100000 + 10] = { 0 };

int binarySearch(int x,int L, int R)
{
	if (L == R)
	{
		return x - d[L];
	}
	else
	{
		int mid = (L + R) / 2 + 1;
		if (x == d[mid])
		{
			return 0;
		}
		else if (x > d[mid])
		{
			binarySearch(x, mid, R);
		}
		else
		{
			binarySearch(x, L, mid - 1);
		}
	}
}

int main()
{
	int T, N;
	cin >> N >> T;
	for (int i = 0; i < N; i++)
	{
		cin >> d[i];
	}
	for (int i = 0; i < T; i++)
	{
		cin >> e[i];
		int result = binarySearch(e[i], 0, N - 1);
		if (result == 0)
		{
			cout << "Accept" << endl;
		}
		else
		{
			cout << result << endl;
		}
	}
	return 0;
}