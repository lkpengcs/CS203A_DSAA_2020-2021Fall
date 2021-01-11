#include <iostream>
#include <stdio.h>
#include <algorithm>
#define MAXN 100010
using namespace std;

struct node
{
	int l, r, val;
}tree[MAXN * 20];

int a[MAXN], b[MAXN], root[MAXN], cnt = 0;
int m, k;

int build(int l, int r)
{
	int k = cnt++;
	if (l == r)
	{
		tree[k].val = 0;
		return k;
	}
	int mid = l + (r - l) / 2;
	tree[k].l = build(l, mid);
	tree[k].r = build(mid + 1, r);
	tree[k].val = tree[tree[k].l].val + tree[tree[k].r].val;
	return k;
}

int update(int x, int l, int r, int p)
{
	int k = cnt++;
	tree[k] = tree[x];
	if (l == p && r == p)
	{
		tree[k].val += 1;
		return k;
	}
	int mid = l + (r - l) / 2;
	if (p <= mid)
	{
		tree[k].l = update(tree[x].l, l, mid, p);
	}
	else
	{
		tree[k].r = update(tree[x].r, mid + 1, r, p);
	}
	tree[k].val = tree[tree[k].l].val + tree[tree[k].r].val;
	return k;
}

int query(int l, int r, int first, int second, int k)
{
	if (l == r)
	{
		return l;
	}
	int mid = l + (r - l) / 2;
	int difference = tree[tree[second].l].val - tree[tree[first].l].val;
	if (k <= difference)
	{
		return query(l, mid, tree[first].l, tree[second].l, k);
	}
	else
	{
		return query(mid + 1, r, tree[first].r, tree[second].r, k - difference);
	}
}

int main()
{
	scanf("%d%d", &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
		b[i] = a[i];
	}
	sort(b + 1, b + m + 1);
	int len = unique(b + 1, b + m + 1) - b;
	root[0] = build(1, len);
	for (int i = 1; i <= m; i++)
	{
		int p = lower_bound(b + 1, b + 1 + len, a[i]) - b;
		root[i] = update(root[i - 1], 1, len, p);
	}
	int n;
	for (int i = 1; i <= m - k + 1; i++)
	{
		scanf("%d", &n);
		int id = query(1, len, root[i - 1], root[i + k - 1], n);
		printf("%d\n", b[id]);
	}
	return 0;
}