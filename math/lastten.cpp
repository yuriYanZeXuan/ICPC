#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5;
int vis[maxn],prime[maxn];
int cnt=0;
const long long mod=1e10;
//输入C_n^r,输出末十位,不足就补前导零
int getexp(int p,int A){
    //p在A!中的重数
    int ans=0;
    while(A){
        ans+=A/p;
        A/=p;
    }
    return ans;
}
void Euler(){
    // prime[0]=2;
    for(int i=2;i<=maxn;i++){
        if(!vis[i]){
            prime[cnt++]=i;
        }
        for(int j=0;j<cnt&&prime[j]*i<maxn;j++){
            vis[prime[j]*i]=1;
            if(i%prime[j]==0)break;
        }
    }
}
long long quick_pow(int a,int b){
    long long ans=1;
    while(b){
        if(b&1)ans=ans*a%mod;
        b>>=1;
        a=a*a%mod;
    }
    return  ans;
}
long long calc(int n,int r){
    //C_n^r=n!/(r!*(n-r)!)
    int exp[maxn]={0};
    long long ans=1;
    for(int i=0;prime[i]<=n;i++){
        exp[i]+=getexp(prime[i],n);
        exp[i]-=getexp(prime[i],r);
        exp[i]-=getexp(prime[i],n-r);
        if(exp[i]){
            // cout<<"p="<<prime[i]<<"exp="<<exp[i]<<endl;
            ans=ans*quick_pow(prime[i],exp[i])%mod;
        }
    }
    return ans;
}
int main(){
    int n,r;
    cin>>n>>r;
    Euler();
    // cout<<getexp(3,1000)<<endl;
    long long ans;
    // cout<<calc(29999,27381)<<endl;
    ans=calc(n,r);
    string out;
    for(int i=0;i<10;i++){
        // out.insert()
        out.insert(0,1,char(((int)(ans%10))+'0'));
        ans/=10;
    }
    cout<<out<<endl;
    return 0;
}