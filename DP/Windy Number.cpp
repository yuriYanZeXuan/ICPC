#include <bits/stdc++.h>
using namespace std;
int dp[20][12]; // dp[i][j]表示第i位,表征状态sta:0:lead,1:0/9,2:1~8
int A[30];     //表示数字
int dfs(int pos,int pre,int limit){
    if(pos<0)return 1;//假设枚举完所有位数
    if(!limit&&dp[pos][pre]!=-1){
        // if(pos==0)cout<<"return "<<dp[pos][getsta(lead,pre)]<<endl;
        return dp[pos][pre];
    } 
    int up=limit?A[pos]:9;
    int tmp=0;
    for(int i=0;i<=up;i++){
        if(abs(i-pre)<2)continue;
        if(pre==11&&i==0)
            tmp+=dfs(pos-1,11,limit&&A[pos]==i);
        else
            tmp+=dfs(pos-1,i,limit&&A[pos]==i);
    }

    if(!limit)dp[pos][pre]=tmp;
    return tmp;
}
int solve(int x)
{
    // memset(dp,-1,sizeof(dp));
    int pos = 0;
    while (x)
    {
        A[pos++] = x % 10;
        x /= 10;
    }
    return dfs(pos-1,11,1);
}
int main()
{
    int a, b;
    memset(dp, -1, sizeof(dp));
    cin>>a>>b;
    // cin >> a;
    cout<<solve(b)-solve(a-1)<<endl;
    // cout << solve(a) << endl;
    return 0;
}