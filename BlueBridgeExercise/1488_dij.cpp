#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
vector<int> g[maxn];
struct Edge{
    int u,v,w;
}edge[maxn];
int dis[maxn];
int edgenum;
int main(){
    int N,M,K,x;
    cin>>N>>M;
    for(int i=1;i<=M;i++){
        int a,b,c;
        cin>>a>>b>>c;
        edge[++edgenum]={a,b,c};
        g[a].push_back(edgenum);
        edge[++edgenum]={b,a,c};
        g[b].push_back(edgenum);
    }
    memset(dis,63,sizeof(dis));
    cin>>K;
    for(int i=1;i<=K;i++){
        cin>>x;
        queue<int> q;
        q.push(x);
        dis[x]=0;
        while(!q.empty()){
            int p=q.front();
            q.pop();
            for(int i=0;i<g[p].size();i++){
                Edge e=edge[g[p][i]];
                if(dis[e.u]+e.w<dis[e.v]){
                    q.push(e.v);
                    dis[e.v]=dis[e.u]+e.w;
                }
            }
        }
    }
    int Q,y;
    cin>>Q;
    for(int i=0;i<Q;i++){
        cin>>y;
        cout<<dis[y]<<endl;
    }
    return 0;
}