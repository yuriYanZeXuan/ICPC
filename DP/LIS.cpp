#include<bits/stdc++.h>
using namespace std;
const int maxn=1001;
int dp[maxn];//dp[i]表示以i结尾的最大价值
int A[maxn];
int main(){
    int N;
    while(cin>>N&&N){
        int ans=0;
        memset(dp,0,sizeof(dp));
        for(int i=1;i<=N;i++){
            cin>>A[i];
        }
        dp[0]=0;
        for(int i=1;i<=N;i++){
            for(int j=0;j<i;j++){
                if(A[i]>A[j]){
                    dp[i]=max(dp[i],dp[j]+A[i]);
                    ans=max(ans,dp[i]);
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}