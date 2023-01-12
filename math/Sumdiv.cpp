#include<bits/stdc++.h>
using namespace std;
long long mod=9901;
long long qmi(long long q,long long p)
{
    if(p==0)return 1;
    if(p==1)return q%mod;
    long long res=qmi(q,p/2);
    res=p%2?res*res*q%mod:res*res%mod;
    return res;
}
long long sum(long long p,int n){//calculate 1+p+p^2+...+p^n
    long long res=p;
    if(n==0)return 1;
    if(n%2){//n是奇数
        // S=(1+p^(n/2+1)*sum(p,n/2)
        res=(1+qmi(p,n/2+1))*sum(p,n/2)%mod;
    }else{//n是偶数
        //S=p^(n/2)+(1+p^(n/2+1))*sum(p,n/2-1)
        // cout<<qmi(p,n/2)<<" "<<(1+qmi(p,n/2+1))<<" "<<sum(p,n/2-1)<<"sda"<<endl;
        res=qmi(p,n/2)+(1+qmi(p,n/2+1))*sum(p,n/2-1)%mod;
    }
    // cout<<"1+...+p^"<<n<<"="<<res<<endl;
    return res%mod;
}
const int maxn=5e7;
int T[maxn],cnt[maxn];
int main(){
    long long A,B;
    // cout<<qmi(2,3);
    cin>>A>>B;
    int k=0;
    for(int i=2;i*i<A;){
        if(!(A%i)){
            T[k++]=i;
            while(!(A%i)){
                cnt[T[k-1]]++;
                A/=i;
            }
        }
        if(i==2)i++;
        else i+=2;
    }
    if(A>1){
        T[k++]=A;
        cnt[T[k-1]]=1;
    }
    long long res=1;
    for(int i=0;i<k;i++){
        res=res*sum(T[i],cnt[T[i]]*B)%mod;
    }
    cout<<res<<endl;
    return 0;
}