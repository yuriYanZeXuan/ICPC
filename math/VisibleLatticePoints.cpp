#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int vis[maxn],prime[maxn],phi[maxn];
int prime_num;
void getphi(){
    phi[1]=1;
    for(int i=2;i<maxn;i++){
        if(!vis[i]){
            prime[prime_num++]=i;
            phi[i]=i-1;
        }
        for(int j=0;j<prime_num,prime[j]*i<maxn;j++)
        {
            vis[prime[j]*i]=1;
            if(i%prime[j]==0){
                phi[i*prime[j]]=prime[j]*phi[i];
                break;
            }else{
                phi[i*prime[j]]=(prime[j]-1)*phi[i];
            }
        }
    }
}
int main(){
    getphi();
    // for(int i=1;i<50;i++){//检验欧拉函数筛正常工作
    //     cout<<phi[i]<<endl;
    // }
    int C,N;
    cin>>C;
    for(int i=1;i<=C;i++){
        cin>>N;
        int res=0;
        for(int i=1;i<=N;i++){
            res+=phi[i];
        }
        printf("%d %d %d\n",i,N,2*res+1);
    }
    return 0;
}