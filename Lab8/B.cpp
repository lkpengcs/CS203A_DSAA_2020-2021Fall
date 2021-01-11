#include <iostream>
#include <stdio.h>
#include <cmath>
using namespace std;

int T, n;

struct node
{
    int value;
    int index;
} heap[100010];

void insert(int p)
{
    while (p > 1)
    {
        if (heap[p].value > heap[p / 2].value)
        {
            swap(heap[p], heap[p / 2]);
            p = p / 2;
        }
        else
        {
            break;
        }
    }
}

int main()
{
    scanf("%d", &T);
    while (T > 0)
    {
        T--;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &heap[i].value);
            heap[i].index = i;
        }
        for (int i = 2; i <= n; i++)
        {
            insert(i);
        }
        int id, po;
        scanf("%d", &id);
        for (int i = 1; i <= n; i++)
        {
            if (heap[i].index == id)
            {
                po = i;
                break;
            }
        }
        long long x = log(po) / log(2) + 1;
        long long y = po - pow((double)2, (double)(x - 1)) + 1;
        printf("%d %d\n", x, y);
    }
    return 0;
}