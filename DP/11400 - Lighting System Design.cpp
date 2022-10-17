#include<bits/stdc++.h>
using namespace std;
const int maxn=2000;
// int V[maxn],K[maxn],C[maxn],L[maxn];
int dp[maxn];//前i种灯泡采购方式的最优花费
int s[maxn];//前i种灯泡的总数量
struct Lamp{
    int v,k,c,l;
    bool operator<(const Lamp& rhs) const{
        return v<rhs.v;
    }
}lamp[maxn];
int main(){
    int n;
    while(cin>>n&&n){
        for(int i=1;i<=n;i++){
            cin>>lamp[i].v>>lamp[i].k>>lamp[i].c>>lamp[i].l;
            
        }
        sort(lamp+1,lamp+n+1);
        s[0]=0;
        for(int i=1;i<=n;i++){
            s[i]=s[i-1]+lamp[i].l;
        }

        dp[0]=0;
        for(int i=1;i<=n;i++){
            dp[i]=s[i]*lamp[i].c+lamp[i].k;//前i个灯泡全买类型i
            for(int j=1;j<=i;j++){
                dp[i]=min(dp[i],dp[j]+(s[i]-s[j])*lamp[i].c+lamp[i].k);
            }
        }
        cout<<dp[n]<<endl;
    }

    return 0;
}