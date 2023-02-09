#include<bits/stdc++.h>
using namespace std;
/*
莫比乌斯反演公式：
    f(n)=\sum_(d|n){\mu(d)*F(n/d)}
    \mu(d)函数定义:
        (1)d=1时\mu(d)=1
        (2)d=p1*p2*...*pk时且p1,p2...pk为互不相同的素数，\mu(d)=(-1)^k
    常见性质:
        对于任意正整数n,\sum_(d|n){\mu(d)}=      1(n=1)
                                                0(n!=1)
            证明:将d写成p1*...*pk的形式后用二项式定理即可
        对任意正整数n,\sum_(d|n){\mu(d)/d}=\phi(d)/n
            证明:左边用展开式，右边用phi的变形:phi(n)=(p1-1/p1)*(p2-1/p2)*...*(pk-1/pk)*n,做比较即可
*/
const int maxn=1e6;
int vis[maxn],mu[maxn],prime[maxn];
int cnt;
void init(){
    //用线性筛求莫比乌斯反演函数
    memset(vis,0,sizeof(vis));
    mu[1]=1;
    cnt=0;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prime[cnt++]=i;
            mu[i]=-1;
        }
        for(int j=0;j<cnt&&i*prime[j]<maxn;j++){
            vis[i*prime[j]]=1;
            if(i%prime[j])mu[i*prime[j]]=-mu[i];
            else{
                mu[i*prime[j]]=-1;
                break;
            }
        }
    }
}
int main(){
    return 0;
}