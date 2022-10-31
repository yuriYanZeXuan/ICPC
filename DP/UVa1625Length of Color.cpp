#include<bits/stdc++.h>
using namespace std;
const int maxn=5100;
const int inf=0x3f3f3f3f;
int d[maxn][maxn],cnt[maxn][maxn];
int ss[30],st[30],es[30],et[30];
int main()
{
    int t;
    cin>>t;
    while(t--){
        char s[maxn],t[maxn];
        scanf("%s%s",s+1,t+1);
        int lens=strlen(s+1);
        int lent=strlen(t+1);
        memset(ss,inf,sizeof(ss));
        memset(st,inf,sizeof(st));
        memset(es,0,sizeof(es));
        memset(et,0,sizeof(et));
        for(int i=1;i<=lens;i++){
            int cur=s[i]-'A';
            ss[cur]=min(ss[cur],i);
            es[cur]=i;
        }
        for(int i=1;i<=lent;i++){
            int cur=t[i]-'A';
            st[cur]=min(st[cur],i);
            et[cur]=i;
        }
        for(int i=0;i<=lens;i++)
        {
            for(int j=0;j<=lent;j++){
                int u=inf,v=inf;
                if(i==0&&j==0){
                    d[i][j]=0;
                }else{
                    if(i){
                        u=d[i-1][j]+cnt[i-1][j];
                    }
                    if(j){
                        v=d[i][j-1]+cnt[i][j-1];
                    }
                    d[i][j]=min(u,v);
                }

                if(i){
                    cnt[i][j]=cnt[i-1][j];
                    if(ss[s[i]-'A']==i&&st[s[i]-'A']>j)
                        cnt[i][j]++;//上升沿触发
                    if(es[s[i]-'A']==i&&et[s[i]-'A']<=j)
                        cnt[i][j]--;//下降沿
                }
                else if(j){
                    cnt[i][j]=cnt[i][j-1];
                    if(st[t[j]-'A']==j&&ss[t[j]-'A']>i)
                        cnt[i][j]++;
                    if(et[t[j]-'A']==j&&es[t[j]-'A']<=i)
                        cnt[i][j]--;
                }
                else if(i==0&&j==0)
                    cnt[i][j]==0;
            }
        }
        cout<<d[lens][lent]<<endl;
    }
    return 0;
}