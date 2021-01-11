#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int T;
	long long n;
	scanf("%d", &T);
	while (T > 0)
	{
		T--;
		scanf("%lld", &n);
		long long x = (long long)(log(n) / log(2));
		printf("%lld\n", x + 1);
	}
	return 0;
}