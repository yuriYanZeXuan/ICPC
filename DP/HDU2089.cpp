#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int a[20];
int dp[20][2];//dp[pos][pre=?6]
int dfs(int pos,int pre,int sta,bool limit){
    if(pos==-1)return 1;
    if(!limit&&dp[pos][sta]!=-1)return dp[pos][sta];
    int up=limit?a[pos]:9;
    int tmp=0;
    for(int i=0;i<=up;i++){
        if(sta&&i==2)continue;
        if(i==4)continue;//保证枚举合法性
        tmp+=dfs(pos-1,i,i==6,limit&&a[pos]==i);
    }
    if(!limit)dp[pos][sta]=tmp;
    return tmp;
}
int solve(int x){
    int pos=0;
    while(x){
        a[pos++]=x%10;
        x/=10;
    }
    return dfs(pos-1,-1,0,true);
}
int main(){
    int le,ri;
    //memset(dp,-1,sizeof(dp));可优化
    while(~scanf("%d%d",&le,&ri)&&le+ri){
        memset(dp,-1,sizeof(dp));
        cout<<solve(ri)-solve(le-1)<<endl;
    }
    return 0;
}