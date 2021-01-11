#pragma GCC optimize(3, "Ofast", "inline")

#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <cmath>
using namespace std;

inline long long read() {
	char ch = getchar();
	long long x = 0;
	while (ch < '0' || ch > '9') {
		ch = getchar();
	}
	while ('0' <= ch && ch <= '9') {
		x = x * 10 + ch - '0';
		ch = getchar();
	}
	return x;
}


long long n;
vector<long long>pet, adopter;

int main()
{
	n = read();
	long long a, b;
	long long sum = 0;
	for (int t = 1; t <= n; t++)
	{
		a = read();
		b = read();
		if (a == 0)
		{
			if (pet.size() == 0)
			{
				if (adopter.size() != 0)
				{
					int p = lower_bound(adopter.begin(), adopter.end(), b) - adopter.begin();
					p = p >= adopter.size() ? adopter.size() - 1 : p;
					if (p == 0)
					{
						sum += abs(adopter[p] - b);
						adopter.erase(adopter.begin());
					}
					else
					{
						long long tmp1 = abs(adopter[p - 1] - b);
						long long tmp2 = abs(adopter[p] - b);
						if (tmp1 <= tmp2)
						{
							sum += tmp1;
							adopter.erase(adopter.begin() + p - 1);
						}
						else
						{
							sum += tmp2;
							adopter.erase(adopter.begin() + p);
						}
					}
				}
				else
				{
					pet.push_back(b);
				}
			}
			else
			{
				int p = lower_bound(pet.begin(), pet.end(), b) - pet.begin();
				p = p >= pet.size() ? pet.size(): p;
				pet.insert(pet.begin() + p, b);
			}			
		}
		else
		{
			if (pet.size() == 0)
			{
				int p = lower_bound(adopter.begin(), adopter.end(), b) - adopter.begin();
				p = p >= adopter.size() ? adopter.size() : p;
				adopter.insert(adopter.begin() + p, b);
			}
			else
			{
				int p = lower_bound(pet.begin(), pet.end(), b) - pet.begin();
				p = p >= pet.size() ? pet.size() - 1: p;
				if (p == 0)
				{
					sum += abs(pet[p] - b);
					pet.erase(pet.begin());
				}
				else
				{
					long long tmp1 = abs(pet[p - 1] - b);
					long long tmp2 = abs(pet[p] - b);
					if (tmp1 <= tmp2)
					{
						sum += tmp1;
						pet.erase(pet.begin() + p - 1);
					}
					else
					{
						sum += tmp2;
						pet.erase(pet.begin() + p);
					}
				}
			}
		}
	}
	printf("%lld", sum);
	return 0;
}