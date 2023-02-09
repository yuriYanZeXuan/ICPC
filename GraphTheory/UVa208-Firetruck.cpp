#include<bits/stdc++.h>
using namespace std;
const int maxn = 22;
int g[maxn][maxn];
int n,N=21;
int pth[maxn];
int f[maxn];
int getfather(int x){
    return f[x]==x?x:f[x]=getfather(f[x]);
}
int dfs(int x,int *vis,int len){
    if(x==n){
        // cout<<pth<<"   "<<n<<endl;
        for(int i=0;i<len;i++){
            printf("%d ",pth[i]); 
        }
        printf("%d\n",n);
        return 1;
    }
    int res=0;
    vis[x]=1;
    pth[len]=x;
    for(int p=1;p<=N;p++){//邻接矩阵
        if(!g[x][p])continue;
        if(vis[p])continue;
        else{
            res+=dfs(p,vis,len+1);
        }
    }
    vis[x]=0;
    return res;
}
int main(){
    // ios::sync_with_stdio(false);
    // cin.tie(0);
    // freopen("dig208.dat","w",stdout);
    int cnt=0;
    while(scanf("%d",&n)==1){
        cnt++;
        int a,b;
        memset(g,0,sizeof(g));
        /*
            并查集要init，否则所有的f[x]都指向0
        */
        // memset(f,0,sizeof(f));
        for(int i=0;i<=N;i++){
            f[i]=i;
        }
        while(scanf("%d%d",&a,&b)&&a&&b){
            g[a][b]=g[b][a]=1;
            // g[b].push_back(a);

            // if(getfather(b)==b){             错误的并查集合并操作会导致在getfather时无穷递归
            //     f[b]=a;
            // }else if(getfather(a)!=getfather(b)){
            //     f[getfather(a)]=getfather(b);
            // }
            int x=getfather(a),y=getfather(b);
            if(x!=y){
                f[x]=y;
            }
        }
        // cout<<"CASE "<<cnt<<endl;
        printf("CASE %d:\n",cnt);
        int vis[maxn];
        // vis[1]=1;
        int sum=0;
        memset(vis,0,sizeof(vis));
        if(getfather(1)==getfather(n))
            sum=dfs(1,vis,0);
        printf("There are %d routes from the firestation to streetcorner %d.\n",sum,n);
    }
    return 0;
}