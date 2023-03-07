#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=1e5+10;
int n;
LL m;
int w[N],q[N];
LL f[N];
multiset<LL> S;
void remove(LL x){
    auto it=S.find(x);
    S.erase(it);
    /*直接写S.erase(x)会将所有x删除*/
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        cin>>w[i];
        if(w[i]>m){
            puts("-1");
            return 0;
        }
    }
    int hh=0,tt=-1;
    LL sum=0;
    /*双指针*/
    for(int i=1,j=1;i<=n;i++){
        sum+=w[i];
        while(sum>m){
            sum-=w[j++];
            if(hh<=tt&&q[hh]<j){
                if(hh<tt)remove(f[q[hh]]+w[q[hh+1]]);
                hh++;//有值时出队
            }
        }

        while(hh<=tt&&w[q[tt]]<=w[i]){
            if(hh<tt)remove(f[q[tt-1]]+w[q[tt]]);
            tt--;
        }
        
        q[++tt]=i;
        if(hh<tt)S.insert(f[q[tt-1]]+w[q[tt]]);
        f[i]=f[j-1]+w[q[hh]];
        if(S.size())f[i]=min(f[i],*S.begin());
    }
    cout<<f[n]<<endl;
    return 0;
}