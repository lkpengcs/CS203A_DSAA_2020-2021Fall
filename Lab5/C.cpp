#include <iostream>
#include <stdio.h>
using namespace std;

int n, q;

struct node
{
	node* pre;
	node* next;
	int val;
};

node* a[100000 + 10][3];

int main()
{
	while (scanf("%d%d", &n, &q)==2)
	{
		for (int i = 1; i <= n; i++)
		{
			node* head = new node;
			node* tail = new node;
			head->next = tail, head->pre = NULL, tail->pre = head, tail->next = NULL;
			a[i][0] = head, a[i][1] = tail;
		}
		int op, u, v, w, val;
		for (int i = 1; i <= q; i++)
		{
			scanf("%d", &op);
			if (op == 1)
			{
				scanf("%d%d%d", &u, &w, &val);
				if (w == 0)
				{
					node* tmphead = a[u][0];
					node* tmp = new node;
					tmp->val = val;
					tmp->next = tmphead->next;
					tmphead->next->pre = tmp;
					tmphead->next = tmp;
					tmp->pre = tmphead;
				}
				else
				{
					node* tmptail = a[u][1];
					node* tmp = new node;
					tmp->val = val;
					tmp->next = tmptail;
					tmptail->pre->next = tmp;
					tmp->pre = tmptail->pre;
					tmptail->pre = tmp;
				}
			}
			else if (op == 2)
			{
				scanf("%d%d", &u, &w);
				if (a[u][0]->next == a[u][1])
				{
					printf("-1\n");
				}
				else if (w == 0)
				{
					printf("%d\n", a[u][0]->next->val);
					node* tmp = a[u][0]->next;
					a[u][0]->next = tmp->next;
					tmp->next->pre = a[u][0];
					tmp->next = NULL;
					tmp->pre = NULL;
				}
				else
				{
					printf("%d\n", a[u][1]->pre->val);
					node* tmp = a[u][1]->pre;
					a[u][1]->pre = tmp->pre;
					tmp->pre->next = a[u][1];
					tmp->next = NULL;
					tmp->pre = NULL;
				}
			}
			else
			{
				scanf("%d%d%d", &u, &v, &w);
				if (w == 0)
				{
					node* tailu = a[u][1];
					node* headv = a[v][0];
					node* tailv = a[v][1];
					tailu->pre->next = headv->next;
					headv->next->pre = tailu->pre;
					tailv->pre->next = tailu;
					tailu->pre = tailv->pre;
					headv->next = tailv;
					tailv->pre = headv;
				}
				else
				{
					node* tailupre = a[u][1]->pre;
					node* p = tailupre;
					node* tailvpre = a[v][1]->pre;
					while (tailvpre != a[v][0])
					{
						p->next = tailvpre;
						tailvpre = tailvpre->pre;
						tailvpre->next->pre = p;
						p = p->next;
					}
					p->next = a[u][1];
					a[u][1]->pre = p;
					a[v][0]->next = a[v][1];
					a[v][1]->pre = a[v][0];
				}
			}
		}
		for (int i = 1; i <= n; i++)
		{
			delete a[i][0], a[i][1];
		}
	}
	return 0;
}