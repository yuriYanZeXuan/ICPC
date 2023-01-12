#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int t;
ll max_factor,n;
ll gcd(ll a,ll b){
    if(b==0)return a;
    return gcd(b,a%b);
}
ll quick_pow(ll x, ll p, ll mod){
    ll ans=1;
    while(p){
        if(p&1)ans=(__int128_t)ans*x%mod;
        x=(__int128_t)x*x%mod;
        p>>=1;
    }
    return ans;
}
bool Miller_Rabin(ll p){
    if(p<2)return 0;
    if(p==2)return 1;
    if(p==3)return 1;
    ll d=p-1,r=0;
    while(!(d&1))++r,d>>=1;//将d处理成奇数
    for(ll k=0;k<10;k++){
        ll a=rand()%(p-2)+2;
        ll x =quick_pow(a,d,p);
        if(x==1||x==p-1)continue;
        for(int i=0;i<r-1;i++){
            x=(__int128_t)x*x%p;
            if(x==p-1)break;
        }
        if(x!=p-1)return 0;
    }
    return 1;
}
ll Pollar_Rho(ll x){
    ll s=0,t=0;
    ll c=rand()%(x-1)+1;
    int step=0,goal=1;
    ll val=1;
    for(goal =1;;goal*=2,s=t,val=1){//倍增优化
        for(step=1;step<=goal;++step){
            t=((__int128_t)t*t+c)%x;
            val=(__int128_t)val*abs(t-s)%x;
            if(step%127==0){
                ll d=gcd(val,x);
                if(d>1)return d;
            }
        }
        ll d=gcd(val,x);
        if(d>1)return d;
    }
}
void fac(ll x){
    if(x<=max_factor||x<2)return;
    if(Miller_Rabin(x)){//如果x为质数
        max_factor=max(max_factor,x);//更新答案
        return;
    }
    ll p=x;
    while(p>=x)p=Pollar_Rho(x);//使用PR算法分解
    while(x%p==0)x/=p;
    fac(x);fac(p);//继续向下分解
}
int main(){
    scanf("%d", &t);
  while (t--) {
    srand((unsigned)time(NULL));
    max_factor = 0;
    scanf("%lld", &n);
    fac(n);
    if (max_factor == n)  // 最大的质因数即自己
      printf("Prime\n");
    else
      printf("%lld\n", max_factor);
  }
    return 0;
}