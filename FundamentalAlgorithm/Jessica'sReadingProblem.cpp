#include<iostream>
#include<algorithm>
using namespace std;
const int maxn =1e6+5;
const int mod=50*1e6+1;
int A[maxn],cnt[maxn],cnt2[maxn];
int Hashtable[50*maxn];
int Hash(int t){
    int test=(1ll*t*t)%mod+1;
    if(Hashtable[test]==t)return test;
    else {
        while(Hashtable[test]!=0&&Hashtable[test]!=t){
            test=(1ll*test*test)%mod+1;
        }
        return Hashtable[test]=t;
    }
}
int main(){
    int P,know;
    // cin>>P;
    scanf("%d",&P);
    for(int i=1;i<=P;i++){
        // cin>>A[i];
        scanf("%d",A+i);
        if(!cnt[Hash(A[i])])know++;
        cnt[Hash(A[i])]++;
    }
    int difnum=0,ans=0x3f3f3f3f;
    int t=1,hashs,hasht;
    for(int s=1;s<=P&&t<=P+1;s++){
        // cnt2[A[s]]++;
        hashs=Hash(A[s]);
        while(difnum<know){
            hasht=Hash(A[t]);
            if(!cnt2[hasht]){
                difnum++;
            }
            cnt2[hasht]++;
            t++;
        }
        if(difnum==know)
        {
            ans=min(ans,t-s);
            if(cnt2[hashs]==1){
                difnum--;
            }
            cnt2[hashs]--;
        }
    }
    // cout<<ans<<endl;
    printf("%d\n",ans);
    return 0;
}