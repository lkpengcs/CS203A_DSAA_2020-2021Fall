#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;

int T, n;
int deadl[100010];

struct node
{
    int ddl;
    long long power;
} a[100010], heap[100010];

void insert(int p)
{
    while (p > 1)
    {
        if (heap[p].power < heap[p / 2].power)
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

void minmodify(int st, int en)
{
    int tmp = st * 2;
    while (tmp <= en)
    {
        if (tmp < en && heap[tmp].power > heap[tmp + 1].power)
        {
            tmp++;
        }
        if (heap[st].power > heap[tmp].power)
        {
            swap(heap[st], heap[tmp]);
            st = tmp;
            tmp = st * 2;
        }
        else
        {
            break;
        }
    }
}

bool cmp1(node x, node y)
{
    if (x.ddl == y.ddl)
    {
        return x.power > y.power;
    }
    else
    {
        return x.ddl < y.ddl;
    }
}

int main()
{
    scanf("%d", &T);
    while (T > 0)
    {
        T--;
        long long sum = 0;
        int maxd = -1, cnt = 0;
        scanf("%d", &n);
        for (int i = 1; i <= n; i++)
        {
            scanf("%lld", &a[i].power);
        }
        for (int i = 1; i <= n; i++)
        {
            scanf("%d", &a[i].ddl);
            maxd = max(maxd, a[i].ddl);
        }
        sort(a + 1, a + n + 1, cmp1);
        int p = 1;
        for (int i = 1; i <= maxd; i++)
        {
            while (i <= maxd && i < a[p].ddl)
            {
                sum += a[p].power;
                cnt++;
                heap[cnt] = a[p];
                insert(cnt);
                p++, i++;
            }
            if (i == a[p].ddl)
            {
                sum += a[p].power;
                cnt++;
                heap[cnt] = a[p];
                insert(cnt);
                p++;
                while (i == a[p].ddl && a[p].power > heap[1].power)
                {
                    sum = sum - heap[1].power + a[p].power;
                    heap[1] = a[p];
                    minmodify(1, cnt);
                    p++;
                }
                while (i == a[p].ddl)
                {
                    p++;
                }
            }
        }
        printf("%lld\n", sum);
    }
    return 0;
}