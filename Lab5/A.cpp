#include <iostream>
#include <stdio.h>
#define N 30000+10
using namespace std;

char op[N];
char tmp[N];
int top = -1;
int n, T;

void push(char c)
{
	if (top < n - 1)
	{
		top++;
		op[top] = c;
	}
}

char peek()
{
	if (top != -1)
	{
		return op[top];
	}	
}

void pop()
{
	if (top >= 0)
	{
		top--;
	}
}

int main()
{
	scanf("%d", &T);
	while (T > 0)
	{
		T--;
		top = -1;
		scanf("%d", &n);
		scanf("%s", &tmp);
		//char tmp;
		//scanf("%c", &tmp);
		bool flag = true;
		for (int i = 0; i < n; i++)
		{
			//scanf("%c", &tmp);
			if (tmp[i] == '(' || tmp[i] == '{' || tmp[i] == '[')
			{
				push(tmp[i]);
			}
			else if (tmp[i] == ')')
			{
				if (peek() != '(')
				{
					flag = false;
					break;
				}
				else
				{
					pop();
				}
			}
			else if (tmp[i] == ']')
			{
				if (peek() != '[')
				{
					flag = false;
					break;
				}
				else
				{
					pop();
				}
			}
			else if (tmp[i] == '}')
			{
				if (peek() != '{')
				{
					flag = false;
					break;
				}
				else
				{
					pop();
				}
			}
		}
		if (flag && top == -1)
		{
			printf("YES\n");
		}
		else
		{
			printf("NO\n");
		}
		//scanf("%c", &tmp);
	}
	
	return 0;
}