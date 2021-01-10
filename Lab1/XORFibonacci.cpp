#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
	int T;
	scanf_s("%d", &T);
	for (int i = 1; i <= T; i++)
	{
		int a, b, n, result = 0;
		scanf_s("%d%d%d", &a, &b, &n);
		if (n % 3 == 0)
		{
			result = a;
		}
		else if (n % 3 == 1)
		{
			result = b;
		}
		else
		{
			result = a ^ b;
		}
		printf("%d\n", result);
	}
	return 0;
}