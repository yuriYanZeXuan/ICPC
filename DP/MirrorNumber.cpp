#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll dp[50][4][50];//dp[i][j][eff]表示i位j状态eff位有效的情况数,精髓在于dp的状况的可唯一标识性
int A[50],b[50];
int len;
int check(int l){
    for(int i=0;i<l;i++)
    {
        if(A[i]!=A[l-i-1]||(A[i]!=1&&A[i]!=0&&A[i]!=8))return 0;
    }
    return 1;
}
ll dfs(int pos,int limit,int lead,int eff){
    if(pos<0)return 1;
    if(!limit&&dp[pos][2*lead+limit][eff]!=-1)return dp[pos][2*lead+limit][eff];
    int up=limit?A[pos]:9;
    ll tmp=0;
    for(int i=0;i<=up;i++){
        if(i!=0&&i!=1&&i!=8)continue;
        b[pos]=i;
        if(lead&&i==0){//全前导零
            tmp+=dfs(pos-1,0,1,eff-1);
        }else if(pos>eff/2){//未过半程
            tmp+=dfs(pos-1,limit&&i==A[pos],0,eff);
        }else if(b[pos]==b[eff-pos]){
            tmp+=dfs(pos-1,limit&&i==A[pos],0,eff);
        }
    }
    if(!limit)dp[pos][2*lead+limit][eff]=tmp;//上界的计数不具备可记忆性
    return tmp;

}
int main(){
    int cases;
    cin>>cases;
    string s1,s2;
    memset(dp,-1,sizeof(dp));
    while(cases--){
        cin>>s1>>s2;
        ll n1,n2;
        len=s1.length();
        memset(A,0,sizeof(A));
        for(int i=0;i<len;i++){
            A[i]=s1[len-i-1]-'0';
        }
        n1=dfs(s1.length()-1,1,1,s1.length()-1);
        int delta=check(s1.length());
        len=s2.length();
        memset(A,0,sizeof(A));
        for(int i=0;i<len;i++){
            A[i]=s2[len-i-1]-'0';
        }
        n2=dfs(s2.length()-1,1,1,s2.length()-1);
        cout<<n2-n1+delta<<endl;
    }
    return 0;
}