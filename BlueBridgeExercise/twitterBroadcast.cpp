#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
vector<int> g[maxn];
int main(){
    int N,L;
    cin>>N>>L;
    for(int i=1;i<=N;i++)
    {   
        int num;
        cin>>num;
        int mi;
        for(int j=0;j<num;j++){
            cin>>mi;
            g[mi].push_back(i);
        }
    }
    int K,ki;
    cin>>K;
    int vis[maxn];
    for(int i=0;i<K;i++){

        cin>>ki;
        for(int j=0;j<=N;j++)vis[j]=0;
        queue<int> q;
        q.push(ki);
        vis[ki]=1;
        int ans=0;
        while(!q.empty()){
            ki=q.front();
            q.pop();
            // cout<<"vis"<<ki<<"="<<vis[ki]<<endl;
            if(vis[ki]>L)break;
            // ans+=g[ki].size();
            for(int j=0;j<g[ki].size();j++){
                if(!vis[g[ki][j]]){
                    vis[g[ki][j]]=vis[ki]+1;
                    q.push(g[ki][j]);
                    ans++;
                }
            }
        }
        cout<<ans<<endl;
    }

    return 0;
}