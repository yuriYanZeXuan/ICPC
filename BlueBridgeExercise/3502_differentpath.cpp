#include<bits/stdc++.h>
using namespace std;
const int maxn=10;
int n,m,k;
int A[maxn][maxn];
int vis[2000000];
int dfs(int dep,int x,int y,int num){
    if(x<0||x>=n||y<0||y>=m)return 0;
    if(dep==k){
        if(!vis[num*10+A[x][y]]){
            vis[num*10+A[x][y]]=1;
            // cout<<"new num"<<num*10+A[x][y]<<endl;
            return 1;
        }else{
            return 0;
        }
    }
    int ans=0;
    ans+=dfs(dep+1,x-1,y,num*10+A[x][y]);
    ans+=dfs(dep+1,x+1,y,num*10+A[x][y]);
    ans+=dfs(dep+1,x,y-1,num*10+A[x][y]);
    ans+=dfs(dep+1,x,y+1,num*10+A[x][y]);
    return ans;   
}
int main()
{
    cin>>n>>m>>k;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cin>>A[i][j];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            ans+=dfs(0,i,j,0);
        }
    }
    cout<<ans<<endl;
    return 0;

}