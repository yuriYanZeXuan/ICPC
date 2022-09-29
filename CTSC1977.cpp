#include<bits/stdc++.h>
using namespace std;
const int maxn =305;
int f[maxn][maxn],s[maxn],n,m;
vector<int> g[maxn];
int dfs(int u){
    int p=1;
    f[u][1]=s[u];
    for(auto v:g[u]){
        int siz=dfs(v);
        //注意下面两重循环的上下界，
        // 只考虑已经合并过的子树，以及选的课程数超过m+1的状态没有意义
        for(int i=min(p,m+1);i;i--){
            for(int j=1;j<=siz&&i+j<=m+1;j++){
                f[u][i+j]=max(f[u][i+j],f[u][i]+f[v][j]);
            }
        }
        p+=siz;
    }
    return p;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=n;i++){
        int k;
        cin>>k>>s[i];
        g[k].push_back(i);
    }
    dfs(0);
    cout<<f[0][m+1]<<endl;
    return 0;
}
