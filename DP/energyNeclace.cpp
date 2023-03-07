#include<bits/stdc++.h>
using namespace std;
const int maxn =3e2;
int A[maxn];
long long dp[maxn][maxn];
int main(){
    int N;
    cin>>N;
    for(int i=1;i<=N;i++){
        cin>>A[i];
        A[i+N]=A[i];
        dp[i][i]=dp[i+N][i+N]=0;
    }
    for(int len=2;len<=N;len++){
        for(int l=1;l<=2*N-len+1;l++){
            int r=l+len-1;
            for(int j=l;j<r;j++){
                // int t=((r+1)%N)==0?N:r+1;
                dp[l][r]=max(dp[l][r],dp[l][j]+dp[j+1][r]+A[l]*A[j+1]*A[r+1]);
                // cout<<"dp"<<l<<' '<<r<<"="<<dp[l][r]<<endl;
            }
        }
    }
    long long maxval=-1;
    for(int i=1;i<=N;i++){
        maxval=max(maxval,dp[i][i+N-1]);
    }
    cout<<maxval<<endl;
    return 0;
}