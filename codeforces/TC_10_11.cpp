#include<bits/stdc++.h>
using namespace std;
const int maxn=3000;
const int maxp=500001;
int A[maxn];
int vis[maxp];
vector<int> p;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,sum=0;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>A[i];
            sum+=A[i];
        }
        int thickness=0x3f3f3f3f,tt;
        int seg=0;
        for(int i=1;i<=n;i++){
            seg=0;
            for(int j=1;j<=i;j++){
                seg+=A[j];
            }
            if(sum%seg)continue;
            tt=i;
            int ts=0,ind=0;
            for(int j=i+1;j<=n;j++){
                ts+=A[j];
                ind++;
                if(ts==seg){
                    ts=0;
                    tt=max(tt,ind);
                    ind=0;
                    continue;
                }else if(ts>seg){
                    tt=-1;
                    break;
                }   
            }
            if(tt>0){
                thickness=min(thickness,tt);
            }
        }
        cout<<thickness<<endl;
    }
    return 0;
}