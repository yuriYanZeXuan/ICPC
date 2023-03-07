#include<bits/stdc++.h>
using namespace std;
const int maxn=1<<13;
long long f[13][maxn];//f[i][j]表示第i列j状态的方案数,j[k]=0表示第k行向右横放，其余都为竖放
bool ok[maxn];
int main(){
    int N,M;
    while(cin>>N>>M&&N&&M){
        for(int i=0;i<1<<N;i++){
            bool f=true;
            for(int j=0;j<N;j++){
                if(i&(1<<j)){
                    int cnt=0;
                    while(i&(1<<j)&&j<N){
                        j++;
                        cnt++;
                    }
                    if(cnt&1){//奇数
                        f=false;
                        break;
                    }
                }
            }
            ok[i]=f;
        }
        // for(int i=0;i<20;i++){
        //     cout<<i<<"--"<<ok[i]<<endl;
        // }
        memset(f,0,sizeof(f));
        f[0][(1<<N)-1]=1;
        int sum=0;

        for(int i=1;i<=M;i++){
            for(int j=0;j<1<<N;j++){//枚举第i列状态j        
                for(int k=0;k<1<<N;k++){
                    if((j|k)==(1<<N)-1&&ok[(~(j^k))&((1<<N)-1)])//00->x,10->0,01->0,11->1
                    {
                        f[i][j]+=f[i-1][k];
                        // printf("i=%d,j=%d,k=%d,(j|k)=%d,和并列=%d,f[i][j]=%d\n",i,j,k,(j|k),(~(j^k))&((1<<N)-1),f[i][j]);
                    }
                }      
                // if(i==M)sum+=f[i][j];
            }
        }
        cout<<f[M][(1<<N)-1]<<endl;
    }
    return 0;
}