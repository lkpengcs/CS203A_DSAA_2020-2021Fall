#include <iostream>
using namespace std;

struct node
{
	char context;
	node* next;
	node* pre;
};

int main()
{
	int T, n;
	cin >> T;
	while (T > 0)
	{
		T--;
		cin >> n;
		node* head = new node;
		node* tail = new node;
		head->next = tail;	head->pre = NULL;
		tail->next = NULL;	tail->pre = head;
		node* p = tail;
		string str;
		cin >> str;
		for (int i = 0; i < n; i++)
		{
			if (str[i] == 'r')
			{
				if (i + 1 < n)
				{
					if (str[i + 1] != 'r' && str[i + 1] != 'I' && str[i + 1] != 'H' && str[i + 1] != 'L' && str[i + 1] != 'x')
					{
						if (p != tail)
						{
							p->context = str[i + 1];
						}
						else
						{
							node* tmp = new node;
							tmp->context = str[i + 1];
							p->pre->next = tmp;
							tmp->pre = p->pre;
							tmp->next = p;
							p->pre = tmp;
							p = tmp;
						}
						i++;
					}
				}
			}
			else if (str[i] == 'I')
			{
				while (p->pre != NULL && p->pre != head)
				{
					p = p->pre;
				}
			}
			else if (str[i] == 'H')
			{
				if (p->pre != head && p->pre != NULL)
				{
					p = p->pre;
				}
			}
			else if (str[i] == 'L')
			{
				if (p->next != NULL)
				{
					p = p->next;
				}
			}
			else if (str[i] == 'x')
			{
				if (p != tail)
				{
					if (p->pre != NULL && p->next != NULL)
					{
						p->pre->next = p->next;
						p->next->pre = p->pre;
						p = p->next;
					}
				}
			}
			else
			{
				node* tmp = new node;
				tmp->context = str[i];
				node* listtmp = p->pre;
				tmp->next = p;
				p->pre = tmp;
				tmp->pre = listtmp;
				listtmp->next = tmp;
			}
		}
		p = head->next;
		while (p->next != NULL)
		{
			cout << p->context;
			p = p->next;
		}
		cout << endl;
		delete head;
		delete tail;
	}
}