#include<bits/stdc++.h>
using namespace std;
/*
    Lucas定理:
    Lucas(a,b,p)=C_n^m          (mod p)
    Lucas(a,b,p)=C_(n%p)^(m%p)*Lucas(n/p,m/p,p)     (mod p)
    证明：二项式定理即可
*/
typedef  long long ll;
const int p;
int qpow(int a,int b);
int getc(int n,int m){
    if(n<m)return 0;
    if(m>n-m)m=n-m;
    ll s1=1,s2=1;
    for(int i=0;i<m;i++){
        s1=s1*(n-i);
        s2=s2*(i+1);
    }
    return s1*qpow(s2,p-2);
}
int Lucas(int a,int b){
    if(b==0)return 1;
    return getc(a%p,b%p)*Lucas(a/p,b/p);
}
int main(){
    return 0;
}