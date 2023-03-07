#include<bits/stdc++.h>
using namespace std;
const int maxn=5e2;
int A[maxn],dp[maxn][maxn],s[maxn],dp2[maxn][maxn];

int main()
{
    int N;
    cin>>N;
    memset(dp,63,sizeof(dp));
    for(int i=1;i<=N;i++){
        cin>>A[i];
        s[i]=s[i-1]+A[i];
        A[i+N]=A[i];
        dp[i][i]=dp[i+N][i+N]=0;
        dp2[i][i]=dp2[i+N][i+N]=0;
    }
    for(int i=N+1;i<=2*N;i++){
        s[i]=A[i]+s[i-1];
    }
    int minval=0x3f3f3f3f,maxval=-1;
    for(int i=2;i<=N;i++){//枚举长度
        for(int l=1;l<=2*N-i+1;l++){//枚举左端点
            int r=l+i-1;
            for(int j=l;j<r;j++){
                dp[l][r]=min(dp[l][r],dp[l][j]+dp[j+1][r]+s[r]-s[l-1]);
                dp2[l][r]=max(dp2[l][r],dp2[l][j]+dp2[j+1][r]+s[r]-s[l-1]);
            }
            if(i==N){
                minval=min(minval,dp[l][r]);
                maxval=max(maxval,dp2[l][r]);
            }
        }
    }
    cout<<minval<<endl<<maxval<<endl;
    return 0;
}