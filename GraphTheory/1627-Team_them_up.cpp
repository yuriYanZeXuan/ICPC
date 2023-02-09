#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=2e2;
set<pair<int,int>> table;
set<int> P;
vector<int> g[maxn];
int vis[maxn];
int main()
{
    // cout<<"asd"<<endl;
    int t;
    int A[200];
    cin>>t;
    while(t--){
        cin>>n;
        table.clear();
        P.clear();
        memset(vis,0,sizeof(vis));
        for(int i=1;i<=n;i++){
            int tmp;
            memset(A,0,sizeof(A));
            while (cin>>tmp&&tmp)
            {
                A[tmp]=1;
            }
            for(int j=1;j<=n;j++){
                if(!A[j]&&j!=i){//连边，待判二分图
                    table.insert(make_pair(min(i,j),max(i,j)));
                    P.insert(i);
                    P.insert(j);
                }
            }
        }
        memset(g,0,sizeof(g));
        for(auto it:table){
            g[it.first].push_back(it.second);
            g[it.second].push_back(it.first);
        }
        queue<int> q;
        vector<int> v[2];
        bool flag=true;//标志是否有解
        for(auto p:P){
            if(vis[p])continue;
            q.push(p),vis[p]=1;//先入为主的染色可能会导致最后两组人数相差过大
            v[0].push_back(p);
            while(!q.empty()){
                int e=q.front();
                q.pop();
                for(int k=0;k<g[e].size();k++){
                    if(!vis[g[e][k]]){
                        vis[g[e][k]]=-vis[e];
                        if(vis[e]==1)
                            v[1].push_back(g[e][k]);
                        else    
                            v[0].push_back(g[e][k]);
                        q.push(g[e][k]);
                    }else if(vis[g[e][k]]==vis[e]){
                        flag=false;
                    }
                }
            }
        }
        if(flag){
            for(int j=1;j<=n;j++){
                if(!vis[j]){
                    if(v[1].size()<v[0].size()){
                        v[1].push_back(j);
                    }else{
                        v[0].push_back(j);
                    }
                }
            }
            cout<<v[0].size();
            sort(v[0].begin(),v[0].end(),greater<int>());
            while(!v[0].empty()){
                cout<<' '<<v[0].back();
                v[0].pop_back();
            }
            cout<<endl<<v[1].size();
            sort(v[1].begin(),v[1].end(),greater<int>());
            while(!v[1].empty()){
                cout<<' '<<v[1].back();
                v[1].pop_back();
            }
            cout<<endl<<endl;
        }else{
            cout<<"No solution"<<endl<<endl;
            v[0].clear();
            v[1].clear();
        }
    }
    return 0;
}