#include <iostream>
using namespace std;

char s[200][200];

void printFront(int length, int width, int height)
{
	int first = width * 2;
	int newHeight = height * 2;
	int newLength = length * 2;
	for (int k = 0; k < newHeight; k += 2)
	{
		for (int i = 0; i < newLength; i += 2)
		{
			s[first + k][i] = '+';
			s[first + k][i + 1] = '-';
		}
		for (int i = 0; i < newLength; i += 2)
		{
			s[first + k + 1][i] = '|';
			s[first + k + 1][i + 1] = '.';
		}
	}
	for (int i = 0; i < newLength; i+=2)
	{
		s[first + newHeight][i] = '+';
		s[first + newHeight][i + 1] = '-';
	}
	s[first + newHeight][newLength] = '+';
}

void printUp(int length, int width, int height)
{
	int dotNumber = width * 2;
	int newLength = length * 2;
	while (dotNumber > -1)
	{
		int lineNumber = width * 2 - dotNumber;
		for (int i = dotNumber-1; i > -1; i--)
		{
			s[lineNumber][i] = '.';
		}
		if (lineNumber % 2 == 0)
		{
			for (int i = 0; i <= newLength; i += 2)
			{
				s[lineNumber][dotNumber + i] = '+';
				s[lineNumber][dotNumber + i + 1] = '-';
			}
		}
		else
		{
			for (int i = 0; i < newLength; i += 2)
			{
				s[lineNumber][dotNumber + i] = '/';
				s[lineNumber][dotNumber + i + 1] = '.';
			}
		}
		dotNumber--;
	}
}

void printSide(int length, int width, int height)
{
	int newLength = (length + width) * 2;
	int newHeight = height * 2;
	int limit = length * 2;
	int lineNumber = 0;
	for (int i = newLength; i >= limit; i--)
	{
		if (lineNumber % 2 == 0)
		{
			for (int j = lineNumber; j < lineNumber + newHeight; j += 2)
			{
				s[j][i] = '+';
				s[j + 1][i] = '|';
			}
			s[newHeight + lineNumber][i] = '+';
			int top = newHeight + lineNumber + 1;
			int bottom = newHeight + width * 2;
			for (int k = top; k <= bottom; k++)
			{
				s[k][i] = '.';
			}
		}
		else
		{
			for (int j = lineNumber; j < lineNumber + newHeight; j += 2)
			{
				s[j][i] = '/';
				s[j + 1][i] = '.';
			}
			s[newHeight + lineNumber][i] = '/';
			int top = newHeight + lineNumber + 1;
			int bottom = newHeight + width * 2;
			for (int k = top; k <= bottom; k++)
			{
				s[k][i] = '.';
			}
		}
		lineNumber++;
	}
}

int main()
{
	int T;
	cin >> T;
	while (T > 0)
	{
		T--;
		int a, b, c;
		cin >> a >> b >> c;
		int x = (a + b) * 2;
		int y = (b + c) * 2;
		for (int i = 0; i <= y; i++)
		{
			for (int j = 0; j <= x; j++)
			{
				s[i][j]=' ';
			}
		}
		printFront(a, b, c);
		printUp(a, b, c);
		printSide(a, b, c);
		for (int i = 0; i <= y; i++)
		{
			for (int j = 0; j <= x; j++)
			{
				cout << s[i][j];
			}
			cout << endl;
		}
	}
	return 0;
}