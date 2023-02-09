#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const long long mod=1e9+7;
const int maxn=1e6;
ll inv[maxn];
ll _S[1001][1001];
ll exgcd(ll a,ll b, ll& x,ll& y){
    if(b==0){
        x=1,y=0;
        return a;
    }
    ll res=exgcd(b,a%b,x,y);
    ll tmp=x;
    x=y;
    y=tmp-(a/b)*y;
    return res;
}
long long quick_pow(long long a,long long b){
    long long res=1;
    while(b){
        if(b&1)res=1ll*res*a%mod;
        a=1ll*a*a%mod; 
        b>>=1;
    }
    return res;
}
ll getinv(ll a){
    if(inv[a])return inv[a];
    else{
        ll x,y;
        exgcd(a,mod,x,y);
        return inv[a]=1ll*(x+mod)%mod;//exgcd结果可能是负数
    }
}
ll C(int a,int b){
    ll res=1;
    if(b==0)return 1ll;
    for(int i=a,j=1;i>=1,j<=b;i--,j++){
        res=res*i%mod;
    }
    for(int i=1;i<=b;i++){
        res=res*getinv(i)%mod;
    }
    return res;
}
ll A(int a,int b){
    ll res=1;
    if(b==0)return 1ll;
    for(int i=a,j=1;i>=1,j<=b;i--,j++){
        res=res*i%mod;
    }
    return res;
}
ll S(ll n,ll k){
    if(_S[n][k])return _S[n][k];
    if(k==1)return _S[n][k]=1;
    if(n<k)return _S[n][k]=0;
    else return _S[n][k]=(S(n-1,k-1)+k*S(n-1,k))%mod;
}
int main(){
    long long k,n;
    cin>>n>>k;
    // cout<<C(3,3)<<endl;
    // cout<<getinv(3ll)<<endl;

    // 以下为n个球放k个盒里，每个盒中最多为1个，盒与球都是区分的
    // if(n>k){
    //     cout<<0<<endl;
    // }else{
    //     cout<<C(k,n)*A(n,n)%mod<<endl;
    // }

    //n->k,可以为空，盒与球都是区分的
    // cout<<quick_pow(k,n)<<endl;

    //n->k,不可以为空，球区分，盒不区分
    cout<<S(n,k)<<endl;
    return 0;
}