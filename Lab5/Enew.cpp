#include <iostream>
using namespace std;

const int N = 100000 + 10;

struct node
{
	node* next;
	node* pre;
	int value;
};

node* a[N][3];
int f[100000 + 10];

int main()
{
	for (int i = 1; i <= N - 1; i++)
	{
		node* head = new node;
		node* tail = new node;
		head->next = tail;
		head->pre = NULL;
		tail->pre = head;
		tail->next = NULL;
		a[i][0] = head;
		a[i][1] = tail;
	}
	char str[10];
	int color;
	int maxf = -1;
	int total = 0;
	for (int i = 1; i <= 100000; i++)
	{
		f[i] = 0;
	}
	while (true)
	{
		scanf("%s", str);
		if (str[0] == 'n')
		{
			break;
		}
		else if (str[0] == 'p')
		{
			scanf("%d", &color);
			f[color]++;
			total++;
			maxf = max(f[color], maxf);
			node* last = a[f[color]][1];
			node* lastpre = last->pre;
			node* tmp = new node;
			tmp->value = color;
			tmp->next = last;
			last->pre = tmp;
			tmp->pre = lastpre;
			lastpre->next = tmp;
		}
		else
		{
			if (total == 0)
			{
				printf("pa\n");
			}
			else
			{
				total--;
				node* tmp = a[maxf][1]->pre;
				printf("%d\n", tmp->value);
				a[maxf][1]->pre = tmp->pre;
				tmp->pre->next = a[maxf][1];
				f[tmp->value]--;
				if (a[maxf][1]->pre == a[maxf][0])
				{
					maxf--;
				}
			}
		}
	}
	for(int i = 1; i <= N - 1; i++)
	{
		delete a[i][0];
		delete a[i][1];
	}
	return 0;
}