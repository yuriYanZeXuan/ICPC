#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
int p[maxn],q[maxn];
int main(){
    int n;
    cin>>n;
        for(int i=1;i<=n;i++){
            cin>>p[i];
        }
        for(int i=1;i<=n;i++){
            cin>>q[i];
        }
        int l=1,r=1;
        int pmin=p[l],qmin=q[l];
        int ans=0;
        while(r<=n){
            while(pmin-1&&qmin-1&&r<=n){
                r++;
                pmin=min(pmin,p[r]);
                qmin=min(qmin,q[r]);
            }
            ans+=(r-l+1)*(r-l)/2;
            // if(pmin!=qmin){
                if(l!=r)
                    l=r;
                else    
                    l=++r;
            // }
             pmin=p[l],qmin=q[l];
        }
        cout<<ans<<endl;
    
    return 0;
}