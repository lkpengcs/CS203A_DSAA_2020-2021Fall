#include <iostream>
#include <stdio.h>
using namespace std;

struct AVLnode;
typedef AVLnode* AVLtree;
struct AVLnode {
	int data, high;
	int freq, size;
	AVLtree ls, rs;
	AVLnode() : data(0), high(1), freq(1), size(1), ls(NULL), rs(NULL) {}
	AVLnode(int a) : data(a), high(1), freq(1), size(1), ls(NULL), rs(NULL) {}
};
inline int GetSize(AVLtree p) {
	if (p == NULL) return 0;
	return p->size;
}
inline int GetHigh(AVLtree p) {
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
	inline void Insert(AVLtree& p, int x) {
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
	inline void insert(int x) {
		Insert(root, x);
	}
	inline void Erase(AVLtree& p, int x) {
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
	inline void erase(int x) {
		Erase(root, x);
	}
	inline int get_val(AVLtree p, int rank) {
		if (GetSize(p->ls) >= rank) return get_val(p->ls, rank);
		if (GetSize(p->ls) + p->freq >= rank) return p->data;
		return get_val(p->rs, rank - GetSize(p->ls) - p->freq);
	}
	inline int GetVal(int rank) {
		return get_val(root, rank);
	}
	inline int get_rank(AVLtree p, int val) {
		if (p->data == val) return GetSize(p->ls) + 1;
		if (p->data > val) return get_rank(p->ls, val);
		return get_rank(p->rs, val) + GetSize(p->ls) + p->freq;
	}
	inline int GetRank(int val) {
		return get_rank(root, val);
	}
};

int m, k;
int a[100010];
AVL tree;

int main()
{
	scanf("%d%d", &m, &k);
	for (int i = 1; i <= m; i++)
	{
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= k; i++)
	{
		tree.insert(a[i]);
	}
	int tmp;
	for (int i = 1; i <= m - k + 1; i++)
	{
		scanf("%d", &tmp);
		int value = tree.GetVal(tmp);
		printf("%d\n", value);
		tree.erase(a[i]);
		tree.insert(a[i + k]);
	}
	return 0;
}