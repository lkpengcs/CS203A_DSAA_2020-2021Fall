#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

struct AVLnode;
typedef AVLnode* AVLtree;
struct AVLnode {
	long long data, high;
	long long freq, size;
	AVLtree ls, rs;
	AVLnode() : data(0), high(1), freq(1), size(1), ls(NULL), rs(NULL) {}
	AVLnode(long long a) : data(a), high(1), freq(1), size(1), ls(NULL), rs(NULL) {}
};
inline long long GetSize(AVLtree p) {
	if (p == NULL) return 0;
	return p->size;
}
inline long long GetHigh(AVLtree p) {
	if (p == NULL) return 0;
	return p->high;
}
struct AVL {
	AVLtree root;
	inline void update(AVLtree& p) {
		p->size = GetSize(p->ls) + GetSize(p->rs) + p->freq;
		p->high = max(GetHigh(p->ls), GetHigh(p->rs)) + 1;
	}
	inline void LeftPlus(AVLtree& p) {
		AVLtree q;
		q = p->ls;
		p->ls = q->rs;
		q->rs = p;
		update(p);
		update(q);
		p = q;
	}
	inline void RightPlus(AVLtree& p) {
		AVLtree q;
		q = p->rs;
		p->rs = q->ls;
		q->ls = p;
		update(p);
		update(q);
		p = q;
	}
	inline void LeftRight(AVLtree& p) {
		RightPlus(p->ls);
		LeftPlus(p);
	}
	inline void RightLeft(AVLtree& p) {
		LeftPlus(p->rs);
		RightPlus(p);
	}
	inline void Insert(AVLtree& p, long long x) {
		if (p == NULL) {
			p = new AVLnode(x);
			return;
		}
		if (p->data == x) {
			++(p->freq);
			update(p);
			return;
		}
		if (p->data > x) {
			Insert(p->ls, x), update(p);
			if (GetHigh(p->ls) - GetHigh(p->rs) == 2) {
				if (x < p->ls->data)
					LeftPlus(p);
				else
					LeftRight(p);
			}
		}
		else {
			Insert(p->rs, x), update(p);
			if (GetHigh(p->rs) - GetHigh(p->ls) == 2) {
				if (x > p->rs->data)
					RightPlus(p);
				else
					RightLeft(p);
			}
		}
		update(p);
	}
	inline void insert(long long x) {
		Insert(root, x);
	}
	inline void Erase(AVLtree& p, long long x) {
		if (p == NULL) return;
		if (p->data > x) {
			Erase(p->ls, x), update(p);
			if (GetHigh(p->rs) - GetHigh(p->ls) == 2) {
				if (GetHigh(p->rs->rs) >= GetHigh(p->rs->ls))
					RightPlus(p);
				else
					RightLeft(p);
			}
		}
		else if (p->data < x) {
			Erase(p->rs, x), update(p);
			if (GetHigh(p->ls) - GetHigh(p->rs) == 2) {
				if (GetHigh(p->ls->ls) >= GetHigh(p->ls->rs))
					LeftPlus(p);
				else
					LeftRight(p);
			}
		}
		else {
			if (p->freq > 1) {
				--(p->freq);
				update(p);
				return;
			}
			if (p->ls && p->rs) {
				AVLtree q = p->rs;
				while (q->ls) q = q->ls;
				p->freq = q->freq;
				p->data = q->data, q->freq = 1;
				Erase(p->rs, q->data);
				update(p);
				if (GetHigh(p->ls) - GetHigh(p->rs) == 2) {
					if (GetHigh(p->ls->ls) >= GetHigh(p->ls->rs))
						LeftPlus(p);
					else
						LeftRight(p);
				}
			}
			else {
				AVLtree q = p;
				if (p->ls) p = p->ls;
				else if (p->rs) p = p->rs;
				else p = NULL;
				delete q;
				q = NULL;
			}
		}
		if (p == NULL) return;
		update(p);
	}
	inline void erase(long long x) {
		Erase(root, x);
	}
	inline long long GetPrev(long long val) {
		AVLtree ans = new AVLnode(-1LL << 42), p = root;
		while (p) {
			if (p->data == val) {
				ans = p;
				break;
			}
			if (p->data < val && p->data > ans->data) ans = p;
			p = p->data < val ? p->rs : p->ls;
		}
		return ans->data;
	}
	inline long long GetNext(long long val) {
		AVLtree ans = new AVLnode(1LL << 42), p = root;
		while (p) {
			if (p->data == val) {
				ans = p;
				break;
			}
			if (p->data > val && p->data < ans->data) ans = p;
			p = p->data < val ? p->rs : p->ls;
		}
		return ans->data;
	}
};

int n;
long long sum = 0;
AVL pet, adopter;

int main()
{
	scanf("%d", &n);
	for (int i = 1; i <= n; i++)
	{
		long long type, value;
		scanf("%lld%lld", &type, &value);
		if (type == 0)
		{
			if (adopter.root)
			{
				long long prev = adopter.GetPrev(value);
				long long nxt = adopter.GetNext(value);
				long long dif1 = abs(value - prev);
				long long dif2 = abs(value - nxt);
				if (dif1 <= dif2)
				{
					sum += dif1;
					adopter.erase(prev);
				}
				else
				{
					sum += dif2;
					adopter.erase(nxt);
				}
			}
			else
			{
				pet.insert(value);
			}
		}
		else
		{
			if (pet.root)
			{
				long long prev = pet.GetPrev(value);
				long long nxt = pet.GetNext(value);
				long long dif1 = abs(value - prev);
				long long dif2 = abs(value - nxt);
				if (dif1 <= dif2)
				{
					sum += dif1;
					pet.erase(prev);
				}
				else
				{
					sum += dif2;
					pet.erase(nxt);
				}
			}
			else
			{
				adopter.insert(value);
			}
		}
	}
	printf("%lld", sum);
	return 0;
}