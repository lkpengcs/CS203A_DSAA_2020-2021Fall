#include <iostream>
using namespace std;

struct node
{
	int value;
	node* next;
};

int main()
{
	int T, n, k;
	cin >> T;
	while (T > 0)
	{
		T--;
		cin >> n >> k;
		node* head = new node;
		head->next = NULL;
		node* p = head;
		for (int i = 1; i <= n; i++)
		{
			node* tmp = new node;
			tmp->value = i;
			p->next = tmp;
			p = tmp;
		}
		p->next = head->next;
		p = head;
		int number = n;
		while (number > 0)
		{
			number--;
			for (int i = 0; i < k - 1; i++)
			{
				p = p->next;
			}
			node* tmp = p->next;
			p->next = tmp->next;
			cout << tmp->value << ' ';
		}
		delete head;
		cout << endl;
	}
	return 0;
}