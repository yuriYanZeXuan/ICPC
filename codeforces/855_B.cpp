#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
char s[maxn];
int cnt[300];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,k;
        cin>>n>>k;
        memset(cnt,0,sizeof(cnt));
        for(int i=0;i<n;i++){
            cin>>s[i];
            cnt[s[i]]++;
        }
        int ans=0;
        for(int i=0;i<26;i++){
            ans+=min(cnt['a'+i],cnt['A'+i]);
            if(k){
                int p=abs(cnt['a'+i]-cnt['A'+i])/2;
                if(p<=k){
                    k-=p;
                    ans+=p;
                }else{
                    ans+=k;
                    k=0;
                }
            }
        }
        cout<<ans<<endl;
    }
    return 0;
}