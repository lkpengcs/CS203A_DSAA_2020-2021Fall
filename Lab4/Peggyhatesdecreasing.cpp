#include <iostream>
using namespace std;

struct node
{
	node* pre;
	node* next;
	int value;
};

bool check(node* x)
{
	if (x->pre != head)
	{
		if (x->pre->value > x->value)
		{
			return false;
		}
	}
	if (x->next != tail)
	{
		if (x->next->value < x->value)
		{
			return false;
		}
	}
	return true;
}

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		int n;
		cin >> n;
		node* head = new node;
		node* tail = new node;
		head->value = 0; head->pre = NULL; head->next = tail;
		tail->value = 100010; tail->next = NULL; tail->pre = head;
		node* p = head;
		for (int i = 1; i <= n; i++)
		{
			node* tmp = new node;
			cin >> tmp->value;
			p->next = tmp;
			tmp->pre = p;
			tmp->next = tail;
			tail->pre = tmp;
			p = tmp;
		}
		p = head->next->next;
		while (true)
		{
			bool flag = true;
			node* tmp = p;
			while (!check(p))
			{
				flag = false;
				p = p->next;
			}
			if (flag)
			{
				break;
			}
			tmp->next = p;
			p->pre = tmp;
			p = p->next;
		}
		p = head->next;
		while (p->next != NULL)
		{
			cout << p->value << ' ';
			p = p->next;
		}
		cout << endl;
		delete head; delete tail;
	}
	return 0;
}