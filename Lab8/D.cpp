#include <iostream>
#include <stdio.h>
#include <queue>
#include <stack>
using namespace std;

long long t, k, s;

priority_queue<long long, vector<long long>, greater<long long> > q;

int main()
{
	scanf("%lld%lld%lld", &t, &k, &s);
	for (long long i = 1; i <= t; i++)
	{
		long long tmp = i + s;
		long long sum = tmp;
		while (tmp)
		{
			sum = sum + (tmp % 10);
			tmp /= 10;
		}
		q.push(sum);
		if (q.size() > k)
		{
			q.pop();
		}
		if (i % 100 == 0)
		{
			printf("%lld ", q.top());
			s = q.top();
		}
	}
	return 0;
}