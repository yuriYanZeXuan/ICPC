#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
vector<int> g[maxn];
int sz[maxn];
int dep[maxn];
int dep_sum[maxn];
int f[maxn],n,rt;
long long mns=-1;
void dfs1(int u,int p){
    sz[u]=1;
    dep[u]=dep[p]+1;
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==p)continue;
        dfs1(g[u][i],u);
        sz[u]+=sz[g[u][i]];
    }
    f[rt]+=dep[u];
}
void dfs2(int u,int p){
    for(int i=0;i<g[u].size();i++){
        if(g[u][i]==p)continue;
        f[g[u][i]]=f[u]+n-2*sz[g[u][i]];
        if(mns<f[g[u][i]]){
            mns=f[g[u][i]];
            rt=g[u][i];
        }
        dfs2(g[u][i],u);
    }
}
int main(){
    int u,v;
    cin>>n;
    for(int i=1;i<n;i++){
        cin>>u>>v;
        rt=u;
        g[u].push_back(v);
        g[v].push_back(u);
    }
    dfs1(rt,-1);
    dfs2(rt,-1);
    cout<<rt<<endl;
    return 0;
}