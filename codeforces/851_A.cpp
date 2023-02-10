
#include<bits/stdc++.h>
using namespace std;
const int maxn=2000;
int A[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,cnt=0;
        cin>>n;

        for(int i=0;i<n;i++){
            cin>>A[i];
            if(A[i]==2)cnt++;
        }
        if(cnt&1)cout<<-1<<endl;
        else{
            cnt>>=1;
            for(int i=0;i<n;i++){
                if(A[i]==2)cnt--;
                if(!cnt){
                    cout<<i+1<<endl;
                    break;
                }
            }
        }
    }
    return 0;
}