#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int N,T;
int parent[maxn];
vector<int> child[maxn];
int dfs(int u){
    //return min number of u
    if(child[u].empty()){
        return 1;
    }
    int cnt=0;
    int per=0;
    priority_queue<int,vector<int>,greater<int>> pq;
    for(int i=0;i<child[u].size();i++){
        pq.push(dfs(child[u][i]));
    }
    while(!pq.empty()&&(double)per/child[u].size()*100<T){
        cnt+=pq.top();
        per+=1;
        pq.pop();
    }
    // cout<<u<<"need "<<cnt<<"file"<<endl;
    return cnt;
}
int main(){
    
    while(cin>>N>>T&&N&&T){
        memset(child,0,sizeof(child));
        for(int i=1;i<=N;i++){
            cin>>parent[i];
            child[parent[i]].push_back(i);
        }
        cout<<dfs(0)<<endl;
    }
    return 0;
}