#include<bits/stdc++.h>
using namespace std;
const int maxn=7000;
int happy[maxn];
vector<int> g[maxn];
int head[maxn];
int rem[maxn][2];

int dfs(int x,int f){
    if(rem[x][f]){
        return rem[x][f];
    }
    int ans=0;
    if(f){
        //下属不能去
        for(int i=0;i<g[x].size();i++){
            ans+=dfs(g[x][i],0);
        }
    }else{
        //下属可去可不去
        for(int i=0;i<g[x].size();i++){
            ans+=max(dfs(g[x][i],0),dfs(g[x][i],1)+happy[g[x][i]]);
        }
    }
    return rem[x][f]=ans;
}
int main()
{
    memset(head,1,sizeof(head));
    int n,t;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>t;
        happy[i]=t;
    }
    int l,k,f=0;
    for(int i=1;i<n;i++){
        //n-1行
        cin>>l>>k;
        head[l]=0;
        g[k].push_back(l);
    }
    for(int i=1;i<=n;i++){
        if(head[i]){
            f=i;
            break;//找到根节点
        }
    }
    int maxh=-1;
    maxh=max(dfs(f,0),dfs(f,1)+happy[f]);
    cout<<maxh<<endl;
    return 0;
}