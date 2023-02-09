#include<bits/stdc++.h>
using namespace std;
const int maxn=2e7;
int A[maxn];
int main(){
    int t;
    // cout<<"hello"<<endl;
    cin>>t;
    while(t--){
        // memset(A,0,sizeof(A));
        int n,m,d,p,las;
        cin>>n>>m>>d;
        // if(m==1)cout<<"fuck"<<endl;
        int res=2e7;
        for(int i=1;i<=n;i++){
            cin>>p;
            A[p]=i;
        }
        for(int i=1;i<=m;i++){
            cin>>p;
            if(i>1){
                if(A[las]<A[p]&&A[p]<=A[las]+d){
                    if(d>=n-1){
                        //无法扩张
                        res=min(res,A[p]-A[las]);
                    }else{
                        // cout<<"las,p"<<A[las]<<A[p]<<endl;
                        res=min(res,min(d+A[las]-A[p]+1,A[p]-A[las]));
                    }
                }else{
                    res=0;
                }
            }
            las=p;
        }
        cout<<res<<endl;
    }
    return 0;
}