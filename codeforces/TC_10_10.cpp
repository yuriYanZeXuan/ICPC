#include<bits/stdc++.h>
using namespace std;
const int maxn=200000+10;
typedef long long ll;
int A[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        A[n]=0;
        ll ans=0;
        int p1=0,p2=0,tmp;
        while(p2<n&&p1<n){
            tmp=p2;
            p2++;
            while(p2-p1+1<=A[p2])
            {
                ans+=p2-tmp;
                p2++;
            }
            p2--;
            ans+=(tmp-p1+1)*(p2-tmp);
            p1++;
        }
        cout<<ans+1<<endl;
    }
    return 0;
}