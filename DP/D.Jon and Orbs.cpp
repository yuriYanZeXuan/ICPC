#include<bits/stdc++.h>
using namespace std;
double dp[8000][1001];
int main(){
    //9C11D13B
    int k,q;
    cin>>k>>q;
    memset(dp,0,sizeof(dp));
    dp[0][k]=1;
    int i;
    for(i=0;dp[i][0]<0.5;i++){
        for(int j=k;j>=1;j--){
            // printf("dp[%d][%d]=%lf\n",i,j,dp[i][j]);
            dp[i+1][j-1]+=dp[i][j]*(1.0*j/k);
            
            dp[i+1][j]+=dp[i][j]*(1-1.0*j/k);
        }
        dp[i+1][0]+=dp[i][0];
        // cout<<"dp["<<i<<"][0]="<<dp[i][0]<<endl;
    }
    // cout<<"dp["<<i<<"][0]="<<dp[i][0]<<endl;
    vector<double> v;
    for(int j=0;j<=i;j++){
        v.push_back(dp[j][0]);
    }
    for(int j=0;j<q;j++){
        int p;
        cin>>p;
        int n=upper_bound(v.begin(),v.end(),(double)(1.0*p/2000))-v.begin();
        cout<<n<<endl;
    }
    return  0;
}