#include <iostream>
#include <algorithm>
using namespace std;

struct node
{
	int coefficient;
	int exponent;
};

node a[1000 + 10];
node b[1000 + 10];
node arr[1000 + 10];
node brr[1000 + 10];

int count1 = 1;
int count2 = 1;
bool allFlag = false;

void print(int coefficient, int exponent)
{
	if (coefficient != 0)
	{
		if (coefficient > 0 && allFlag)
		{
			cout << '+';
		}
		if (exponent == 0)
		{
			cout << coefficient;
			allFlag = true;
		}
		else if (exponent == 1)
		{
			if (coefficient == 1)
			{
				cout << 'x';
			}
			else if (coefficient == -1)
			{
				cout << "-x";
			}
			else
			{
				cout << coefficient << 'x';
			}
			allFlag = true;
		}
		else if (coefficient == 1)
		{
			cout << 'x' << '^' << exponent;
			allFlag = true;
		}
		else if (coefficient == -1)
		{
			cout << "-x" << '^' << exponent;
			allFlag = true;
		}
		else
		{
			cout << coefficient << 'x' << '^' << exponent;
			allFlag = true;
		}
	}
}

int main()
{
	int T, n, m;
	cin >> T;
	while (T > 0)
	{
		T--;
		allFlag = false;
		int po1 = 0;int po2 = 0;
		a[0].exponent = -1;	a[0].coefficient = 0; b[0].exponent = -1; b[0].coefficient = 0;
		cin >> n;
		for (int i = 1; i <= n; i++)
		{
			cin >> arr[i].coefficient >> arr[i].exponent;
		}
		for (int i = 1; i <= n; i++)
		{
			int c = arr[i].coefficient;
			int e = arr[i].exponent;
			if (e == a[po1].exponent)
			{
				a[po1].coefficient += c;
			}
			else
			{
				po1++;
				a[po1].exponent = e;
				a[po1].coefficient = c;
			}
		}
		cin >> m;
		for (int i = 1; i <= m; i++)
		{
			cin >> brr[i].coefficient >> brr[i].exponent;
		}
		for (int i = 1; i <= m; i++)
		{
			int c = brr[i].coefficient;
			int e = brr[i].exponent;
			if (e == b[po2].exponent)
			{
				b[po2].coefficient += c;
			}
			else
			{
				po2++;
				b[po2].exponent = e;
				b[po2].coefficient = c;
			}
		}
		count1 = 1;count2 = 1;
		while (count1 <= n && count2 <= m)
		{
			if (a[count1].exponent < b[count2].exponent)
			{
				print(a[count1].coefficient, a[count1].exponent);
				count1++;
			}
			else if (a[count1].exponent > b[count2].exponent)
			{
				print(b[count2].coefficient, b[count2].exponent);
				count2++;
			}
			else
			{
				int c = a[count1].coefficient + b[count2].coefficient;
				if (c != 0)
				{
					print(c, a[count1].exponent);
				}				
				count1++;
				count2++;
			}
		}
		while (count1 <= n)
		{
			print(a[count1].coefficient, a[count1].exponent);
			count1++;
		}
		while (count2 <= m)
		{
			print(b[count2].coefficient, b[count2].exponent);
			count2++;
		}
		if (!allFlag)
		{
			cout << '0';
		}
		cout << endl;
	}
	return 0;
}