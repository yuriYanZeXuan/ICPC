#include<bits/stdc++.h>
using namespace std;
const int maxn =1e5+5;
const int inf=0x3f3f3f3f;
vector<int> G[maxn],vertices;
int p[maxn],d[maxn][3];

//build a rooted tree  and dfs sequence
void dfs(int u,int fa){
    vertices.push_back(u);
    p[u]=fa;
    for(int i=0;i<G[u].size();i++){
        int v=G[u][i];
        if(v!=fa)dfs(v,u);
    }
}
int main(){
    int n;
    while(cin>>n){
        for(int i=0;i<n;i++){
            G[i].clear();
        }
        for(int i=0;i<n-1;i++){
            int u,v;
            cin>>u>>v;
            u--,v--;
            G[u].push_back(v);
            G[v].push_back(u);
        }
        vertices.clear();
        dfs(0,-1);
        for(int i=vertices.size()-1;i>=0;i--){
            int u=vertices[i];
            d[u][0]=1;
            d[u][1]=0;
            for(int j=0;j<G[u].size();j++){
                int v=G[u][j];
                if(v==p[u])continue;
                d[u][0]+=min(d[v][0],d[v][1]);//u is server
                d[u][1]+=d[v][2];//u is not server,u's father is server
                if(d[u][0]>inf)d[u][0]=inf;
                if(d[u][1]>inf)d[u][1]=inf;
            }
            d[u][2]=inf;
            for(int j=0;j<G[u].size();j++){
                int v=G[u][j];
                if(v==p[u])continue;
                d[u][2]=min(d[u][2],d[u][1]-d[v][2]+d[v][0]);//neither u or father is server

            }
        }
        printf("%d\n",min(d[0][0],d[0][2]));
        scanf("%d",&n);//flag
    }
    return 0;
}