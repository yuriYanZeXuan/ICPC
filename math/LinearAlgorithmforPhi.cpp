#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int n,tot;
int phi[maxn],prime[maxn];
bool vis[maxn];
void getphi(){//Euler函数的线性筛,求单独某个数的Euler函数见Euler_shai.cpp
    int i,j;
    phi[1]=1;
    for(i=2;i<=maxn;i++){
        if(!vis[i]){
            prime[tot++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<tot;j++){
            if(i*prime[j]>maxn)break;
            vis[i*prime[j]]=1;
            if(i%prime[j]==0){
                // prime[j]不是i*prime[j]的"唯一"质因数，phi(p*i)=p*phi(i)
                phi[i*prime[j]]=prime[j]*phi[i];
                break;
            }else{
                //prime[j]是i*prime[j]的"唯一质因数",phi(p*i)=(p-1)*phi(i)
                phi[i*prime[j]]=(prime[j]-1)*phi[i];
            }
        }
    }
}
int main(){
    getphi();
    for(int i=1;i<50;i++){
        cout<<phi[i]<<endl;
    }
    return 0;
}