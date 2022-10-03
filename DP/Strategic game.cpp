#include<iostream>
#include<string>
#include<vector>
#include<cstring>
#include<sstream>
using namespace std;
const int maxn=15005;
vector<int> g[maxn];
int fa[maxn];
int dp[maxn][2];
int dfs(int u,int f){
    //u节点f/!f
    if(g[u].empty()){
        return dp[u][f]=0;
    }
    if(dp[u][f]!=-1){
        return dp[u][f];
    }
    int sz=0;
    if(f){
        //f->子节点可选可不选
        for(int i=0;i<g[u].size();i++){
            sz+=min(dfs(g[u][i],1)+1,dfs(g[u][i],0));
        }
    }else{
        for(int i=0;i<g[u].size();i++){
            sz+=dfs(g[u][i],1)+1;
        }
    }
    return dp[u][f]=sz;
}
int main(){
    int n;
    while(scanf("%d",&n)==1)
    {
        memset(g,0,sizeof(g));
        for(int i=0;i<n;i++)
        {
            dp[i][1]=dp[i][0]=-1;
            fa[i]=0;
        }
        for(int i=0;i<n;i++)
        {
            int x,m,p;
            scanf("%d:(%d)",&x,&m);
            for(int j=0;j<m;j++)
            {
                scanf("%d",&p);
                g[x].push_back(p);
                fa[p]=1;
            }
        }
        int rt;
        for(int i=0;i<n;i++){
            if(!fa[i]){
                rt=i;
                break;
            }
        }
        int ans=min(dfs(rt,0),dfs(rt,1)+1);
        cout<<ans<<endl;

    }
    return 0;
}