#include <iostream>
#define ll int
#define maxn 3006
using namespace std;
struct Store{
    ll value,index;
};
int main() {
    ios::sync_with_stdio(false);
    cin.tie(0);
    ll k,n,i,maxL,maxTail,maxHead,minTail,minHead,l;
    Store here,maxQueue[maxn],minQueue[maxn];
    cin>>k>>n;
    minHead=maxHead=maxn-1;
    minTail=maxTail=maxn-2;
    maxL=0;
    l=0;
    for(i=0;i<n;i++){
        cin>>here.value;
        here.index=i;
        while (maxHead-maxTail>1&&maxQueue[maxTail+1].value<=here.value){
            maxTail++;
        }
        maxQueue[maxTail]=here;
        maxTail--;
        while (minHead-minTail>1&&minQueue[minTail+1].value>=here.value){
            minTail++;
        }
        minQueue[minTail]=here;
        minTail--;
        while (maxQueue[maxHead-1].value-minQueue[minHead-1].value>k){
            l++;
            while (maxQueue[maxHead-1].index<l){
                maxHead--;
            }
            while (minQueue[minHead-1].index<l){
                minHead--;
            }
        }
        maxL=max(maxL,i-l+1);
    }
    cout<<maxL<<endl;
    return 0;
}
