// #include<bits/stdc++.h>
#include<iostream>
#include<string.h>
using namespace std;
const int maxn=20;
int M,N;
int G[maxn][maxn],g[maxn][maxn],t[maxn][maxn];
int solve(int mask)
{
    int ret=0;
    memcpy(g,G,sizeof(G));
    for(int i=0;i<N;i++){
        if((mask>>i)&1){
            ret++;
            t[0][i]=1;
            g[0][i]=!g[0][i];
            if(i+1<N)
                g[0][i+1]=!g[0][i+1];
            if(i-1>=0)
                g[0][i-1]=!g[0][i-1];
            if(M>1)
                g[1][i]=!g[1][i];
        }
    }
    for(int i=1;i<M;i++){
        for(int j=0;j<N;j++){
            if(g[i-1][j]){
                ret++;
                t[i][j]=1;
                g[i][j]=!g[i][j];
                if(j+1<N)
                    g[i][j+1]=!g[i][j+1];
                if(j-1>=0)//下标左闭右开
                    g[i][j-1]=!g[i][j-1];
                if(i<M)
                    g[i+1][j]=!g[i+1][j];
            }
        }
    }
    for(int i=0;i<N;i++){
        if(g[M-1][i])return -1;
    }
    return ret;
}
int main(){
    cin>>M>>N;
    for(int i=0;i<M;i++){
        for(int j=0;j<N;j++){
            cin>>G[i][j];
        }
    }
    int minn=0x3f3f3f3f,ans=-1;
    for(int i=0;i<=(1<<N)-1;i++){//区间
        int res=solve(i);
        if(res!=-1&&minn>res){
            minn=res;
            ans=i;
        }
    }
    if(minn==0x3f3f3f3f){
        cout<<"IMPOSSIBLE"<<endl;
    }else{
        memset(t,0,sizeof(t));//数组重用
        solve(ans);
        for(int i=0;i<M;i++){
            for(int j=0;j<N;j++){
                cout<<t[i][j]<<' ';
            }
            cout<<endl;
        }
        cout<<endl;
    }
    return 0;
}