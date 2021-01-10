#include <iostream>
using namespace std;

int n, p, q;

struct node
{
	long long atkNum;
	long long hpNum;
	long long up;
};

node x[200000 + 10];
node b[200000 + 10];

void merge(node a[], int l, int mid, int r)
{
	int left = l, right = mid + 1;
	int count = 0;
	while (left <= mid && right <= r)
	{
		if (a[left].up >= a[right].up)
		{
			b[count] = a[left];
			left++;
		}
		else
		{
			b[count] = a[right];
			right++;
		}
		count++;
	}
	while (left <= mid)
	{
		b[count] = a[left];
		left++;
		count++;
	}
	while (right <= r)
	{
		b[count] = a[right];
		right++;
		count++;
	}
	int length = r - l + 1;
	for (int i = 0; i < length; i++)
	{
		a[l + i] = b[i];
	}
}

void mergesort(node a[], int l, int r)
{
	if (l == r)
	{
		return;
	}
	else
	{
		int mid = l + (r - l) / 2;
		mergesort(a, l, mid);
		mergesort(a, mid + 1, r);
		merge(a, l, mid, r);
	}
}

long long power(int v)
{
	long long result = 1;
	for (int i = 0; i < v; i++)
	{
		result = result * 2;
	}
	return result;
}

int main()
{
	cin >> n >> p >> q;
	for (int i = 1; i <= n; i++)
	{
		cin>> x[i].hpNum>> x[i].atkNum;
		x[i].up = x[i].hpNum-x[i].atkNum;
	}
	mergesort(x, 1, n);
	long long benefit = power(p);
	long long ans = 0;
	for (int i = 1; i <= q; i++)
	{
		ans += max(x[i].hpNum, x[i].atkNum);
	}
	for (int i = q + 1; i <= n; i++)
	{
		if (i <= n)
		{
			ans += x[i].atkNum;
		}
	}
	long long sum = ans;
	for (int i = 1; i <= q; i++)
	{
		ans = max(ans, sum - max(x[i].atkNum, x[i].hpNum) + x[i].hpNum * benefit);
	}
	sum = sum - max(x[q].atkNum, x[q].hpNum) + x[q].atkNum;
	for (int i = q + 1; i <= n && q; i++)
	{
		ans = max(ans, sum - x[i].atkNum + x[i].hpNum * benefit);
	}
	/*long long sum = ans;
	for (int i = 0; i < n; i++)
	{
		long long tmp = sum;
		if (i < q)
		{
			tmp -= max(x[i].hpNum, x[i].atkNum);
			tmp += max(x[i].atkNum, x[i].hpNum * benefit);
			ans = max(ans, tmp);
		}
		else
		{
			tmp -= x[i].atkNum;
			tmp += max(x[i].atkNum, x[i].hpNum * benefit);
			tmp -= max(x[q - 1].atkNum, x[q - 1].hpNum);
			tmp += x[q - 1].atkNum;
			ans = max(ans, tmp);
		}
	}*/

	cout << ans << endl;
	return 0;
}