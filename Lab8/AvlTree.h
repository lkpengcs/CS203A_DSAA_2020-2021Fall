#pragma once
#include <iostream>
#include <stdio.h>
using namespace std;

struct AVLnode;
typedef AVLnode* AVLtree;
struct AVLnode {
	int data, high;//权值，树高
	int freq, size;//频数，大小
	AVLtree ls, rs;//左子，右子
	AVLnode() : data(0), high(1), freq(1), size(1), ls(NULL), rs(NULL) {}
	AVLnode(int a) : data(a), high(1), freq(1), size(1), ls(NULL), rs(NULL) {}//初始化
}; 
AVLtree root;
inline int GetSize(AVLtree p) {//获取大小
	if (p == NULL) return 0;
	return p->size;
}
inline int GetHigh(AVLtree p) {//获取树高
	if (p == NULL) return 0;
	return p->high;
}
inline void update(AVLtree& p) {//更新节点
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
inline void LeftRight(AVLtree& p) {//左右
	RightPlus(p->ls);
	LeftPlus(p);
}
inline void RightLeft(AVLtree& p) {//右左
	LeftPlus(p->rs);
	RightPlus(p);
}
inline void Insert(AVLtree& p, int x) {
	if (p == NULL) {
		p = new AVLnode(x);//没有这个节点，直接插入一个
		return;
	}
	if (p->data == x) {//如果已经有这个树了，直接增加这个数的频率，更新这个节点即可
		++(p->freq);
		update(p);
		return;
	}
	if (p->data > x) {//往左子树插入，左子树可能偏高
		Insert(p->ls, x), update(p);
		if (GetHigh(p->ls) - GetHigh(p->rs) == 2) {
			if (x < p->ls->data)
				LeftPlus(p);//左左
			else
				LeftRight(p);//左右
		}
	}
	else {//往右子树插入，右子树可能偏高
		Insert(p->rs, x), update(p);
		if (GetHigh(p->rs) - GetHigh(p->ls) == 2) {
			if (x > p->rs->data)
				RightPlus(p);//右右
			else
				RightLeft(p);//右左
		}
	}
	update(p);//别忘记更新
}
inline void insert(int x) {
	Insert(root, x);
}
inline void Erase(AVLtree& p, int x) {
	if (p == NULL) return;//找不到这个树，直接返回
	if (p->data > x) {//删左子树的数，右子树可能偏高
		Erase(p->ls, x), update(p);
		if (GetHigh(p->rs) - GetHigh(p->ls) == 2) {
			if (GetHigh(p->rs->rs) >= GetHigh(p->rs->ls))//一定要加等号，同下，就是因为这个，本蒟蒻92分调了55分钟！
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
		if (p->freq > 1) {//如果这个数的频率大于1，那么直接减去一个就可以了
			--(p->freq);
			update(p);
			return;
		}
		if (p->ls && p->rs) {//左右子树都有
			AVLtree q = p->rs;//找这个数的后继
			while (q->ls) q = q->ls;
			p->freq = q->freq;
			p->data = q->data, q->freq = 1;//把q节点提上来
			Erase(p->rs, q->data);//这个节点肯定少于2个子树了，直接删除
			update(p);//别忘记更新
			if (GetHigh(p->ls) - GetHigh(p->rs) == 2) {
				if (GetHigh(p->ls->ls) >= GetHigh(p->ls->rs))
					LeftPlus(p);
				else
					LeftRight(p);
			}
		}
		else {//如果只有一个子树，直接把这个节点的子树提上来即可，不需要更新
			AVLtree q = p;
			if (p->ls) p = p->ls;
			else if (p->rs) p = p->rs;
			else p = NULL;
			delete q;
			q = NULL;
		}
	}
	if (p == NULL) return;//注意这里还要判断，否则可能会RE
	update(p);//最后更新一下
}
inline void erase(int x) {
	Erase(root, x);
}
inline int get_rank(AVLtree p, int val) {
	if (p->data == val) return GetSize(p->ls) + 1;//如果这个节点就是要找的数字，返回左子树的大小加1
	if (p->data > val) return get_rank(p->ls, val);//如果这个节点大于要找的数字，往左找
	return get_rank(p->rs, val) + GetSize(p->ls) + p->freq;//往右找，返回值要加上左子树的大小和这个节点数出现的频数
}
inline int GetRank(int val) {
	return get_rank(root, val);
}
inline int get_val(AVLtree p, int rank) {
	if (GetSize(p->ls) >= rank) return get_val(p->ls, rank);//如果左子树的大小不小于排名，往左找
	if (GetSize(p->ls) + p->freq >= rank) return p->data;//如果左子树的大小加上这个节点数值出现的频数不小于排名，返回这个数值
	return get_val(p->rs, rank - GetSize(p->ls) - p->freq);//往右找，主要排名要减去左子树的大小和这个节点数值出现的频数
}
inline int GetVal(int rank) {
	return get_val(root, rank);
}
inline int GetPrev(int val) {//找前驱
	AVLtree ans = new AVLnode(-1LL << 42), p = root;//从根节点开始找，初始答案赋最小值
	while (p) {//如果p节点不为空，则一直找
		if (p->data == val) {
			if (p->ls) {//如果找到这个数了，先找这个数的左子树，再一直往右找
				p = p->ls;
				while (p->rs)
					p = p->rs;
				ans = p;
			}
			break;
		}
		if (p->data < val && p->data > ans->data) ans = p;//如果遇到一个比这个值小但大于当前答案的值的话，把答案赋给ans
		p = p->data < val ? p->rs : p->ls;
	}
	return ans->data;
}
inline int GetNext(int val) {//找后继，与找前驱类似
	AVLtree ans = new AVLnode(1LL << 42), p = root;
	while (p) {
		if (p->data == val) {
			if (p->rs) {
				p = p->rs;
				while (p->ls)
					p = p->ls;
				ans = p;
			}
			break;
		}
		if (p->data > val && p->data < ans->data) ans = p;
		p = p->data < val ? p->rs : p->ls;
	}
	return ans->data;
}

/*
手撕
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
	inline void OutPut(AVLtree p) {
		if (p == NULL) return;
		OutPut(p->ls);
		for (int i = 1; i <= p->freq; ++i)
			write(p->data), putchar(32);
		OutPut(p->rs);
	}
	inline void output() {
		OutPut(root);
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
inline int GetPrev(int val) {
	AVLtree ans = new AVLnode(-1LL << 42), p = root;
	while (p) {
		if (p->data == val) {
			if (p->ls) {
				p = p->ls;
				while (p->rs)
					p = p->rs;
				ans = p;
			}
			break;
		}
		if (p->data < val && p->data > ans->data) ans = p;
		p = p->data < val ? p->rs : p->ls;
	}
	return ans->data;
}
inline int GetNext(int val) {
	AVLtree ans = new AVLnode(1LL << 42), p = root;
	while (p) {
		if (p->data == val) {
			if (p->rs) {
				p = p->rs;
				while (p->ls)
					p = p->ls;
				ans = p;
			}
			break;
		}
		if (p->data > val && p->data < ans->data) ans = p;
		p = p->data < val ? p->rs : p->ls;
	}
	return ans->data;
}
};
*/

/*
struct avlnode;
typedef avlnode* avltree;
struct avlnode
{
	int size, freq;
	int data, high;
	avltree ls, rs;
	avlnode() : data(0), high(0), size(1), freq(1), ls(NULL), rs(NULL) {}
	avlnode(int a) :data(a), high(0), size(1), freq(1), ls(NULL), rs(NULL) {}
};
inline int getsize(avltree p)
{
	if (p == NULL)
		return 0;
	else
		return p->size;
}
inline int gethigh(avltree p)
{
	if (p == NULL)
		return 0;
	else
		return p->high;
}
struct avl
{
	avltree root;
	inline void update(avltree& p)
	{
		p->size = getsize(p->ls) + getsize(p->rs) + p->freq;
		p->high = max(gethigh(p->ls), gethigh(p->rs)) + 1;
	}
	inline void leftplus(avltree& p)
	{
		avltree q = p->ls;
		p->ls = q->rs;
		q->rs = p;
		update(p);
		update(q);
		p = q;
	}
	inline void rightplus(avltree& p)
	{
		avltree q = p->rs;
		p->rs = q->ls;
		q->ls = p;
		update(p);
		update(q);
		p = q;
	}
	inline void leftright(avltree& p)
	{
		rightplus(p->ls);
		leftplus(p);
	}
	inline void rightleft(avltree& p)
	{
		leftplus(p->rs);
		rightplus(p);
	}
	inline void Insert(avltree& p, int x)
	{
		if (p == NULL)
		{
			p = new avlnode(x);
			return;
		}
		if (p->data == x)
		{
			p->freq = p->freq + 1;
			update(p);
			return;
		}
		if (p->data > x)
		{
			Insert(p->ls, x);
			update(p);
			if (gethigh(p->ls) - gethigh(p->rs) == 2)
			{
				if (x < p->ls->data)
				{
					leftplus(p);
				}
				else
				{
					leftright(p);
				}
			}
		}
		else
		{
			Insert(p->rs, x);
			update(p);
			if (gethigh(p->rs) - gethigh(p->ls) == 2)
			{
				if (x < p->rs->data)
				{
					rightleft(p);
				}
				else
				{
					rightplus(p);
				}
			}
		}
		update(p);
	}
	inline void insert(int x)
	{
		Insert(root, x);
	}
	inline void Erase(avltree& p, int x)
	{
		if (p == NULL)
		{
			return;
		}
		if (p->data > x)
		{
			Erase(p->ls, x);
			update(p);
			if (gethigh(p->rs) - gethigh(p->ls) == 2)
			{
				if (gethigh(p->rs->rs) >= gethigh(p->rs->ls))
				{
					rightplus(p);
				}
				else
				{
					rightleft(p);
				}
			}
		}
		else if (p->data < x)
		{
			Erase(p->rs, x);
			update(p);
			if (gethigh(p->ls) - gethigh(p->rs) == 2)
			{
				if (gethigh(p->ls->ls) >= gethigh(p->ls->rs))
				{
					leftplus(p);
				}
				else
				{
					leftright(p);
				}
			}
		}
		else
		{
			if (p->freq > 1)
			{
				p->freq = p->freq - 1;
				update(p);
				return;
			}
			if (p->ls && p->rs)
			{
				avltree q = p->rs;
				while (q->ls)
				{
					q = q->ls;
				}
				p->freq = q->freq, p->data = q->data, q->freq = 1;
				Erase(p->rs, p->data);
				update(p);
				if (gethigh(p->ls) - gethigh(p->rs) == 2)
				{
					if (gethigh(p->ls->ls) >= gethigh(p->ls->rs))
					{
						leftplus(p);
					}
					else
					{
						leftright(p);
					}
				}
			}
			else
			{
				avltree q = p;
				if (p->ls)
				{
					p = p->ls;
				}
				else if (p->rs)
				{
					p = p->rs;
				}
				else
				{
					p = NULL;
				}
				delete q;
				q = NULL;
			}
		}
		if (p == NULL)
		{
			return;
		}
		update(p);
	}
	inline void erase(int x)
	{
		Erase(root, x);
	}
	inline int get_rank(avltree& p, int val)
	{
		if (p->data == val)
			return getsize(p->ls) + 1;
		if (p->data > val)
			return get_rank(p->ls, val);
		return get_rank(p->rs, val) + getsize(p->ls) + p->freq;
	}
	inline int getrank(int val)
	{
		return get_rank(root, val);
	}
	inline int get_val(avltree& p, int rank)
	{
		if (getsize(p->ls) >= rank)
			return get_val(p->ls, rank);
		if (getsize(p->ls) + p->freq >= rank)
			return p->data;
		return get_val(p->rs, rank - getsize(p->ls) - p->freq);
	}
	inline int getval(int rank)
	{
		return get_val(root, rank);
	}
	inline int getprev(int val)
	{
		avltree ans = new avlnode(-1LL << 42), p = root;
		while (p)
		{
			if (p->data == val)
			{
				if (p->ls)
				{
					p = p->ls;
					while(p->rs)
					{
						p = p->rs;
					}
					ans = p;
				}
				break;
			}
			if (p->data<val && p->data>ans->data)
			{
				ans = p;
			}
			p = p->data < val ? p->rs : p->ls;
		}
	}
	inline int getnext(int val)
	{
		avltree ans = new avlnode(1LL << 42), p = root;
		while (p)
		{
			if (p->data == val)
			{
				if (p->rs)
				{
					p = p->rs;
					while (p->ls)
					{
						p = p->ls;
					}
					ans = p;
				}
				break;
			}
			if (p->data > val && p->data < ans->data)
			{
				ans = p;
			}
			p = p->data < val ? p->rs : p->ls;
		}
	}
};

*/