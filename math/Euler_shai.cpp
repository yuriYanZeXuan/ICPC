#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int isNotPrime[maxn],prime[maxn];
int PrimeNum=0;
void shai(){
    for(int i=2;i<maxn;i++){
        if(!isNotPrime[i]){
            prime[PrimeNum++]=i;
        }
        for(int j=0;j<PrimeNum&&prime[j]*i<maxn;j++){
            isNotPrime[i*prime[j]]=1;
            if(i%prime[j]==0)break;//一个合数只能被最小的质因数筛除

        }
    }
}
int main(){
    shai();
    for(int i=0;i<50;i++){
        cout<<prime[i]<<endl;
    }
    return 0;
}