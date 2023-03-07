#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
int A[maxn],diff[maxn];
int main(){
    int T;
    cin>>T;
    while(T--){
        memset(diff,0,sizeof(diff));
        int n;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>A[i];
            if(A[i]){
                diff[max(i-A[i]+1,1)]++;
                diff[min(i+1,n+1)]--;
            }
        }
        int val=0;
        for(int i=1;i<=n;i++){
            val+=diff[i];
            if(val>0){
                cout<<1<<" ";
            }else{
                cout<<0<<" ";
            }
        }
        cout<<endl;
    }

    return 0;
}