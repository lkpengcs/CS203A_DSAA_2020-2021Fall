#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int main()
{
	int T;
	long long n, k;
	scanf("%d", &T);
	while (T > 0)
	{
		T--;
		scanf("%lld%lld", &n, &k);
		long long x = (long long)(log(n * (k - 1) + 1) / log(k));
		long long have = ((long long)pow((double)k, (double)x) - 1) / (k - 1);
		long long leaf = n - have;
		long long leafp = (((long long)pow((double)k, (double)(x + 1)) - 1) / (k - 1) - n) / k;
		printf("%lld\n", leaf + leafp);
	}
	return 0;
}