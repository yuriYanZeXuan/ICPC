#include<bits/stdc++.h>
using namespace std;
const int maxn=60;
const int inf=0x3f3f3f3f;
int a[maxn];
int d[maxn][maxn];
int dp(int i,int j){
    if(d[i][j])return d[i][j];
    if(j-i==1)
    {
        return d[i][j]=0;
    }else if(i==j){
        return 0;
    }
    else{
        int ans=inf;
        for(int m=i+1;m<j;m++){
            ans=min(ans,dp(i,m)+dp(m,j)+a[j]-a[i]);
        }
        return d[i][j]=ans;
    }
}
int main(){
    int l;
    while(cin>>l&&l){
        int k;
        memset(d,0,sizeof(d));
        cin>>k;
        a[0]=0;
        for(int i=1;i<=k;i++){
            cin>>a[i];
        }
        a[k+1]=l;
        cout<<"The minimum cutting is "<<dp(0,k+1)<<'.'<<endl;
    }
    return 0;
}