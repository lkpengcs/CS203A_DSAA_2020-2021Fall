#include <iostream>
#include <cmath>
using namespace std;

long long xr, yr, xc, yc;
int N;
char ins[100000 + 10];
int dx[4] = { -1,1,0,0 };
int dy[4] = { 0,0,-1,1 };

int operation(char c)
{
	switch (c) 
	{
	case 'U':
		return 3;
	case 'D':
		return 2;
	case 'L':
		return 0;
	case 'R':
		return 1;
	}
	return 0;
}

int main()
{
	cin >> xr >> yr >> xc >> yc;
	cin >> N;
	long long cycleX = 0;
	long long cycleY = 0;
	for (int i = 0; i < N; i++)
	{
		cin >> ins[i];
		cycleX += (long long)dx[operation(ins[i])];
		cycleY += (long long)dy[operation(ins[i])];
	}
	long long l = 0;
	long long r = (long long)1e18;
	bool judge = false;
	while (l < r)
	{
		long long mid = (l + r) / 2 + 1;
		long long cycle = mid / (long long )N;
		int re = (int)(mid % (long long)N);
		long long tmpx = xr + cycleX * cycle;
		long long tmpy = yr + cycleY * cycle;
		for (int i = 0; i < re; i++)
		{
			tmpx += (long long)dx[operation(ins[i])];
			tmpy += (long long)dy[operation(ins[i])];
		}
		long long di = abs(tmpx - xc) + abs(tmpy - yc);
		if (mid >= di)
		{
			if (re == 0)
			{
				re = N;
			}
			tmpx -= (long long)dx[operation(ins[re - 1])];
			tmpy -= (long long)dy[operation(ins[re - 1])];
			if (mid - 1 >= abs(tmpx - xc) + abs(tmpy - yc))
			{
				r = mid - 1;
				judge = true;
			}
			else
			{
				r = mid;
				judge = true;
				break;
			}
		}
		else
		{
			l = mid + 1;
		}
	}
	if (!judge)
	{
		cout << "-1";
	}
	else
	{
		cout << r;
	}
	return 0;
}