#include <iostream>
#include <stdio.h>
using namespace std;

int pre[1010];
int in[1010];

struct node
{
	int id;
	node* l = NULL;
	node* r = NULL;
};

node* build(int l1, int r1, int l2, int r2)
{
	if (l1 > r1)
	{
		return NULL;
	}
	int i = l1;
	while (in[i] != pre[l2])
	{
		i++;
	}
	node* tmp = new node();
	tmp->id = pre[l2];
	int count = i - l1;
	tmp->l = build(l1, i - 1, l2 + 1, l2 + count);
	tmp->r = build(i + 1, r1, l2 + count + 1, r2);
	return tmp;
}

void print(node* root)
{
	if (root->l != NULL)
	{
		print(root->l);
	}
	if (root->r != NULL)
	{
		print(root->r);
	}
	printf("%d ", root->id);
	return;
}

int main()
{
	int T, n;
	scanf("%d", &T);
	while (T > 0)
	{
		T--;
		scanf("%d", &n);
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &pre[i]);
		}
		for (int i = 1; i <= n; i++)
		{
			scanf("%d", &in[i]);
		}
		node* root = build(1, n, 1, n);
		print(root);
		printf("\n");
	}
	return 0;
}