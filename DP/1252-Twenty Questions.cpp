#include<bits/stdc++.h>
using namespace std;
const int maxn=128;
const int maxm=11;
int kase,n,m;
char objects[maxn][maxm+100];
int vis[1<<maxm][1<<maxm],d[1<<maxm][1<<maxm];
int cnt[1<<maxm][1<<maxm];
//cnt[s][a]: how many objects satisfies:Intersect(featureSet(i),s)=a
//s: the set of features we already asked
//a:subset of s that the object has
int dp(int s,int a){//已经问了特征集s,其中已确认了具有的特征集a,还需要询问的最小次数
    if(cnt[s][a]<=1)return 0;
    if(cnt[s][a]==2)return 1;

    int &ans=d[s][a];
    if(vis[s][a]==kase)return ans;
    vis[s][a]=kase;//免清空

    ans=m;
    for(int k=0;k<m;k++){
        if(!(s&(1<<k))){//haven't asked
            int s2=s|(1<<k),a2=a|(1<<k);
            if(cnt[s2][a2]>=1&&cnt[s2][a]>=1){
                int need =max(dp(s2,a2),dp(s2,a))+1;
                ans=min(ans,need);
            }
        }
    }
    return ans;
}

void init(){
    for(int s=0;s<(1<<m);s++){
        for(int a=s;a;a=(a-1)&s){//枚举s的子集
            cnt[s][a]=0;
        }
        cnt[s][0]=0;
    }
    for(int i=0;i<n;i++){
        int features =0 ;
        for(int f=0;f<m;f++){
            if(objects[i][f]=='1')features|=(1<<f);
        }
        for(int s=0;s<(1<<m);s++){
            cnt[s][s&features]++;
        }
    }
}
int main(){
    memset(vis,0,sizeof(vis));
    while(scanf("%d%d",&m,&n)==2&&n){
        ++kase;
        for(int i=0;i<n;i++){
            scanf("%s",objects[i]);
        }
        init();
        printf("%d\n",dp(0,0));
    }
    return 0;
}