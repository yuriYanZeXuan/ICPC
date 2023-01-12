#include<bits/stdc++.h>
using namespace std;
map<int,int> table;
int quick_pow(int a,int b,int p){
    int res=1;
    while(b){//1ll的强制类型转化必不可少！
        if(b&1)res=1ll*res*a%p;
        a=1ll*a*a%p;
        b>>=1;
    }
    return res;
}
/*
    BSGS用于求解a^x_=b(mod p)
    BSGS的精髓在于通过变形式
        a^im=ba^k(mod p)
    其中x=im-k,m=sqrt(p)
    对左右的未知数i,k分别进行枚举
    先枚举k从[0,m)
    再枚举i从[0,[p/m]]
    hash表进行了从ba^k->k的映射
*/
int BSGS(int a,int b,int p){
    int m=ceil(sqrt(p));
    for(int i=0,s=b;i<m;i++,s=1ll*s*a%p)table[s]=i;
    for(int i=0,tmp=quick_pow(a,m,p),s=1;i<=m;i++,s=1ll*s*tmp%p)
        if(table.find(s)!=table.end())
            if(i*m>=table[s])return i*m-table[s];
    return -1;
}
int main(){
    int p,a,n;
    cin>>p>>a>>n;
    long long ans=BSGS(a,n,p);
    ans==-1?puts("no solution"):printf("%lld",ans);
    return 0;
}