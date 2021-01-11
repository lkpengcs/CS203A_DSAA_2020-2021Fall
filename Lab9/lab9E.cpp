#include <iostream>
#include <vector>
#include <cstring>

#define maxn 1005
#define ll long long
using namespace std;
ll block[maxn],a,b,n,m,p[maxn];
vector<ll> G[maxn];
struct Node{
    int stage;
    int index;
    ll sum;
}nodes[maxn];

void solve(ll here,ll pa,ll except0,ll except1){
    ll i,j,to;
    nodes[here].stage=1;
    p[here]=pa;
    if ((here==except0)||(here==except1)){
        return;
    }
    block[pa]++;
    for(i=0;i<G[here].size();i++){
        to=G[here][i];
        if (to!=except0&&to!=except1){
            if (nodes[to].stage!=1){
                solve(to,pa,except0,except1);
            }
        }
    }
}
ll cal(){
    ll i,sum=0;
    for(i=1;i<=n;i++){
        sum+=block[i]*(block[i]-1);
    }
    return sum;
}
int main() {
    ll i,j,k,u,v,result_aOrb=0,resultA=0,resultB=0,aCanGet,bCanGet;

    ios::sync_with_stdio(false);
    cin.tie(0);
    cin>>n>>m>>a>>b;

    if(a==b){
        while (true){
            a++;
            nodes[a].stage=9;
        }
    }
    for(i=1;i<=m;i++){
        cin>>u>>v;
        G[u].push_back(v);
        G[v].push_back(u);
    }
    memset(block,0,sizeof(block));
    for(i=1;i<=n;i++){
        nodes[i].stage=0;
        nodes[i].index=i;
    }
    for(i=1;i<=n;i++){
        if (!nodes[i].stage){
            solve(i,i,a,b);
        }
    }
    result_aOrb=cal();
    memset(block,0,sizeof(block));
    for(i=1;i<=n;i++){
        nodes[i].stage=0;
    }
    for(i=1;i<=n;i++){
        if (!nodes[i].stage){
            solve(i,i,a,0);
        }
    }

    resultA=cal();
    bCanGet=block[p[b]];
    memset(block,0,sizeof(block));
    for(i=1;i<=n;i++){
        nodes[i].stage=0;
    }
    for(i=1;i<=n;i++){
        if (!nodes[i].stage){
            solve(i,i,0,b);
        }
    }
    resultB=cal();
    aCanGet=block[p[a]];
    result_aOrb=resultA+resultB-result_aOrb+2*(n-aCanGet)+2*(n-bCanGet)-2;
    result_aOrb=n*(n-1)-result_aOrb;
    printf("%lld\n",result_aOrb/2);
    return 0;
}
