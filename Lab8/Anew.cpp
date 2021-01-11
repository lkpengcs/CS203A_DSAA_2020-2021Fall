#include <iostream>
#include <stdio.h>
#include <queue>
#define MAXN 100010
using namespace std;

int T,n;
int a[MAXN], num[MAXN], vis[MAXN];

struct node
{
    int l,r;
}tree[MAXN];

queue<node> q;

bool check(node x)
{
    q.push(x);
    bool isleaf=false;
    while(!q.empty())
    {
        node tmp=q.front();
        if(tmp.l==0&&tmp.r!=0)
        {
            return false;
        }
        if(isleaf&&(tmp.l!=0||tmp.r!=0))
        {
            return false;
        }
        if(tmp.l!=0)
        {
            q.push(tree[tmp.l]);
        }
        if(tmp.r!=0)
        {
            q.push(tree[tmp.r]);
        }
        else
        {
            isleaf=true;
        }
        q.pop();
    }
    return true;
}

int main()
{
    scanf("%d",&T);
    for(int t=1;t<=T;t++)
    {
        scanf("%d",&n);
        for(int i=1;i<=n;i++)
        {
            scanf("%d",&a[i]);
            num[i]=0,vis[i]=0;
            tree[i].l=0,tree[i].r=0;
        }
        int p,c;
        int cnt1=0,cnt2=0, root=0;
        bool flag=true;
        for(int i=1;i<n;i++)
        {
            scanf("%d%d",&p,&c);
            num[p]++,vis[c]=1;
            if(a[p]>=a[c])
            {
                cnt1++;
            }
            if(a[p]<=a[c])
            {
                cnt2++;
            }
            if(num[p]>2)
            {
                flag=false;
            }
            if(num[p]==1)
            {
                tree[p].l=c;
            }
            if(num[p]==2)
            {
                tree[p].r=c;
            }
        }
        for(int i=1;i<=n;i++)
        {
            if(!vis[i])
            {
                root=i;
                break;
            }
        }
        if(!flag)
        {
            printf("Case #%d: NO\n",t);
        }
        else if(!(cnt1==n-1||cnt2==n-1))
        {
            printf("Case #%d: NO\n",t);
        }
        else
        {
            if(check(tree[root]))
            {
                printf("Case #%d: YES\n",t);
            }
            else
            {
                printf("Case #%d: NO\n",t);
            }
        }
        while(!q.empty())
        {
            q.pop();
        }
    }
    return 0;
}