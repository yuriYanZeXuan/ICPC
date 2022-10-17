#include<bits/stdc++.h>
using namespace std;
const int maxn=1005;
int n,kase,vis[maxn][maxn],p[maxn][maxn],d[maxn];
//d[i]表示0~i划分成的最小回文串的个数
char s[maxn];
int is_palindrome(int i,int j){
    if(i>=j)return 1;
    if(s[i]!=s[j])return 0;
    if(vis[i][j]==kase)return p[i][j];
    vis[i][j]=kase;//用kase做时间戳，避免重复格式化
    p[i][j]=is_palindrome(i+1,j-1);
    return p[i][j];
}
int main(){
    int T;
    scanf("%d",&T);
    memset(vis,0,sizeof(vis));
    for(kase=1;kase<=T;kase++){
        scanf("%s",s+1);
        n=strlen(s+1);
        d[0]=0;
        for(int i=1;i<=n;i++){
            d[i]=i+1;
            for(int j=0;j<i;j++){
                if(is_palindrome(j+1,i))d[i]=min(d[i],d[j]+1);
            }
        }
        printf("%d\n",d[n]);
    }
    return 0;
}