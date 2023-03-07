#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
// int A[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        // memset(A,0,sizeof(A));
        int n,k,l,r,tl=-1,tr=100;
        cin>>n>>k;
        for(int i=0;i<n;i++){
            cin>>l>>r;
            if(l<=k&&k<=r){
                tl=max(tl,l);
                tr=min(tr,r);
            }
        }
        if(tl==tr){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}