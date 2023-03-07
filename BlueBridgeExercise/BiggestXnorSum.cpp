#include<bits/stdc++.h>
using namespace std;
const int N=3100010;
int n,m;
int tr[N][2],cnt[N],idx;
int s[N];

void insert(int x,int v){
    int p=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(!tr[p][u])tr[p][u]=++idx;
        p=tr[p][u];
        cnt[p]+=v;
    }
}
int query(int x){//查询Trie中与x异或和的最大值
    int res=0,p=0;
    for(int i=30;i>=0;i--){
        int u=x>>i&1;
        if(cnt[tr[p][!u]])p=tr[p][!u],res=res*2+1;
        else p=tr[p][u],res*=2;
    }
    return res;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int x;
        cin>>x;
        s[i]=s[i-1]^x;
    }
    int res=0;
    insert(s[0],1);
    for(int i=1;i<=n;i++){
        if(i-m-1>=0)insert(s[i-m-1],-1);//限制连续长度为m
        res=max(res,query(s[i]));
        insert(s[i],1);
    }
    cout<<res<<endl;
    return 0;
}