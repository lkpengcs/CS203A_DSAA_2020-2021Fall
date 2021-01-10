#include <cstdio>
#include <iostream>
#include <cstring>
#include <cmath>
using namespace std;

const int N = 500;
int len[N+100];
int numofl, lenofl, strlength, maxlen;

struct node
{
	char value;
	node* next;
	node* pre;
};

node* a[N+100];

void init(int count)
{
	node* head = new node;
	head->pre = NULL;
	head->next = NULL;
	a[count] = head;
}

void initinsert(node* now, char c)
{
	node* tmp = new node;
	tmp->value = c;
	now->next = tmp;
	tmp->pre = now;
	now = tmp;
}

void split(int rowid)
{
	for (int i = numofl; i > rowid; i--)
	{
		a[i] = a[i - 1];
		len[i] = len[i - 1];
	}
	//delete a[rowid];
	init(rowid);
	len[rowid] = 0;
	numofl++;
}

void deletehead(int length)
{
	for (int i = 0; i < length; i++)
	{
		delete a[i];
	}
}

char find(int x)
{
	int length = 0;
	int row = 0;
	for (int i = 0; i < numofl; i++)
	{
		if (length + len[i] >= x)
		{
			row = i;
			break;
		}
		length += len[i];
	}
	node* tmp = a[row];
	int count = 0;
	x = x - length;
	while (count < x && tmp->next != NULL)
	{
		tmp = tmp->next;
		count++;
	}
	return tmp->value;
}

void insert(char c, int x)
{
	int length = 0;
	int row = 0;
	for (int i = 0; i < numofl; i++)
	{
		if (length + len[i] >= x)
		{
			row = i;
			break;
		}
		if (i == numofl - 1)
		{
			row = i;
			break;
		}
		length += len[i];
	}
	if (len[row] + 1 > maxlen)
	{
		split(row);
	}
	node* now = a[row];
	int count = 0;
	x = x - length;
	while (count < x && now->next != NULL)
	{
		now = now->next;
		count++;
	}
	node* tmp = new node;
	tmp->value = c;
	if (now->pre == NULL)
	{
		now->next = tmp;
		tmp->pre = now;
		tmp->next = NULL;
	}
	else
	{
		now->pre->next = tmp;
		tmp->pre = now->pre;
		tmp->next = now;
		now->pre = tmp;
	}
	len[row]++;
}

int main()
{
	int T;
	std::ios::sync_with_stdio(false);
	std::cin.tie(nullptr);
	std::cout.tie(nullptr);
	cin >> T;
	while (T > 0)
	{
		T--;
		string str;
		cin >> str;
		int n;
		cin >> n;
		strlength = str.length();
		lenofl = (strlength + N - 1) / N;
		numofl = (strlength - 1) / lenofl + 1;
		maxlen = 2 * lenofl;
		for (int i = 0; i < numofl; i++)
		{
			len[i] = lenofl;
			init(i);
		}
		len[numofl - 1] = (strlength - 1) % lenofl + 1;
		int count = 0;
		node* p = a[count];
		for (int i = 0; i < strlength; i++)
		{
			if (i / lenofl != count)
			{
				count++;
				p = a[count];
			}
			initinsert(p, str[i]);
		}
		while (n > 0)
		{
			n--;
			int operate;
			cin >> operate;
			if (operate == 1)
			{
				char c;
				cin >> c;
				int pos;
				cin >> pos;
				insert(c, pos);
			}
			else
			{
				int pos;
				cin >> pos;
				cout << find(pos) << endl;
			}
		}
		deletehead(numofl);
	}
	return 0;
}