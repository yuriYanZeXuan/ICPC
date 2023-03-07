#include<bits/stdc++.h>
using namespace std;
long long dp[201][101];
//dp[i][j]表示i个气球j次实验能确定几层
/**
 dp[1][x]=x
 dp[i][j]=dp[i][j-1]+1
 dp[i+1][j]=dp[i][j-1]+1+dp[i+1][j-1]
 dp的转移方程取决于最优策略，每多一个球时
 直接从之前能确定的层数的上一层开始试，可以直接cover掉下面的层数
*/
int main(){
    int k;
    long long n;
    for(int i=1;i<=64;i++){
        dp[1][i]=i;
    }
    for(int i=2;i<=100;i++){
        //i个气球
        for(int j=1;j<=64;j++){
            //j次实验
            dp[i][j]=dp[i-1][j-1]+1+dp[i][j-1];
        }
    }
    while(cin>>k>>n&&k&&n){
        if(dp[k][63]<n){
            cout<<"More than 63 trials needed.\n";
        }else{
            for(int i=1;i<=63;i++){
                if(dp[k][i]>=n){
                    cout<<i<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}