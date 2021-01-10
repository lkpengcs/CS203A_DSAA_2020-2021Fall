#include <iostream>
using namespace std;

struct node
{
	int value;
	node* next;
	node* pre;
};

void insert(int p, int x, node* now)
{
	int count = 0;
	while (count < p && now->next != NULL)
	{
		now = now->next;
		count++;
	}
	node* tmp = new node;
	tmp->value = x;
	tmp->pre = now->pre;
	now->pre->next = tmp;
	tmp->next = now;
	now->pre = tmp;
}

void remove(int p, node* now)
{
	int count = 0;
	while (count < p && now->next != NULL)
	{
		now = now->next;
		count++;
	}
	now->pre->next = now->next;
	if (now->next != NULL)
	{
		now->next->pre = now->pre;
	}
	now->next = NULL;
	now->pre = NULL;
}

void query(int p, node* now)
{
	int count = 0;
	while (count < p && now->next != NULL)
	{
		now = now->next;
		count++;
	}
	cout << now->value << endl;
}

int main()
{
	node* head = new node;
	node* p = head;
	int n, m;
	cin >> n >> m;
	for (int t = 0; t < n; t++)
	{
		node* tmp = new node;
		cin >> tmp->value;
		p->next = tmp;
		tmp->pre = p;
		p = tmp;
	}
	for (int t = 0; t < m; t++)
	{
		p = head;
		char c;
		cin >> c;
		switch (c)
		{
		case 'i':
		{
			int v, x;
			cin >> x >> v;
			insert(x, v, p);
			break;
		}
		case 'q':
		{
			int x;
			cin >> x;
			query(x, p);
			break;
		}
		case 'r':
		{
			int x;
			cin >> x;
			remove(x, p);
			break;
		}
		}
	}
	delete head;
	return 0;
}