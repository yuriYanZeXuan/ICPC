#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    int n;
    while(t--){
        cin>>n;
        if(n&1){
            cout<<"yes"<<endl;
        for(int i=1;i<=n/2;i++)
        {
            cout<<i<<' '<<2*n-2*i+1<<endl;
        }
        for(int i=n;i>n/2;i--){
            cout<<i<<' '<<3*n-2*i+1<<endl;
        }
        }else{
            cout<<"No"<<endl;
        }
    }
    return 0;
}