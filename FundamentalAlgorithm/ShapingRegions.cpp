#include<bits/stdc++.h>
using namespace std;
int a,b,n;
int g[2000][5];//g[i][j]表示第i层j方向的坐标
int S[2000];
void dfs(int x1,int y1,int x2,int y2,int c,int dep){
    while(dep<n&&(x1>=g[dep][2]||x2<=g[dep][0]||y1>=g[dep][3]||y2<=g[dep][1]))dep++;
    if(dep>=n){
        S[c]+=(x2-x1)*(y2-y1);
        return;
    }
    if(x1<g[dep][0])dfs(x1,y1,g[dep][0],y2,c,dep+1),x1=g[dep][0];
    if(y1<g[dep][1])dfs(x1,y1,x2,g[dep][1],c,dep+1),y1=g[dep][1];
    if(x2>g[dep][2])dfs(g[dep][2],y1,x2,y2,c,dep+1),x2=g[dep][2];
    if(y2<g[dep][3])dfs(x1,g[dep][3],x2,y2,c,dep+1),y2=g[dep][3];
}
int main(){
    cin>>a>>b>>n;
    for(int i=0;i<n;i++){
        cin>>g[i][0]>>g[i][1]>>g[i][2]>>g[i][3]>>g[i][4];
    }
    dfs(0,0,a,b,1,0);
    for(int i=0;i<n;i++){
        dfs(g[i][0],g[i][1],g[i][2],g[i][3],g[i][4],i+1);
    }
    for(int i=1;i<=1000;i++){
        if(S[i])cout<<i<<' '<<S[i]<<endl;
    }
    return 0;
}