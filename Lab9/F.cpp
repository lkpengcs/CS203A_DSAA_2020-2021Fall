#include <iostream>
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

typedef pair<long long, int> p;

const int N = 500010;

long long ans[N];
int query[N];

struct node
{
	int u, id;
    long long len;
    node(long long _len = 0, int _u = 0, int _id = 0) 
    {
        len = _len, u = _u, id = _id;
    }
    bool operator < (const node& b) const 
    {
        return len > b.len;
    }
};

int T, n, m, k;

vector<p>g[N];
priority_queue<node>q;

int main()
{
    scanf("%d", &T);
    while (T--)
    {
        scanf("%d%d%d", &n, &m, &k);
        for (int i = 1; i <= n; i++)
        {
            g[i].clear();
        }
        while (!q.empty())
        {
            q.pop();
        }
        for (int i = 1; i <= m; i++)
        {
            int u, v;
            long long w;
            scanf("%d%d%lld", &u, &v, &w);
            g[u].push_back(make_pair(w, v));
        }
        for (int i = 1; i <= n; i++)
        {
            if (g[i].size())
            {
                sort(g[i].begin(), g[i].end());
            }
        }
        int maxk = -1;
        for (int i = 1; i <= k; i++)
        {
            scanf("%d", &query[i]);
            maxk = max(maxk, query[i]);
        }
        for (int i = 1; i <= n; i++)
        {
            if (g[i].size())
            {
                q.push(node(g[i][0].first, i, 0));
            }
        }
        int cnt = 0;
        while (!q.empty())
        {
            node tmp = q.top();
            q.pop();
            int u = tmp.u, id = tmp.id;
            long long len = tmp.len;
            ans[++cnt] = len;
            if (cnt == maxk)
            {
                break;
            }
            if (id < (int)g[u].size() - 1)
            {
                q.push(node(len - g[u][id].first + g[u][id + 1].first, u, id + 1));
            }
            int v = g[u][id].second;
            if (g[v].size())
            {
                q.push(node(len + g[v][0].first, v, 0));
            }
        }
        for (int i = 1; i <= k; i++)
        {
            printf("%lld\n", ans[query[i]]);
        }
    }
	return 0;
}