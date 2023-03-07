#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        long long a,b,n,m;
        cin>>a>>b>>n>>m;
        long double f1=1.0*m*a/(m+1),f2=1.0*b;
        if(a<=b){
            cout<<(n/(m+1))*(m*a)+(n%(m+1))*a<<endl;
        }else{
            if(f1>=f2){
                cout<<n*b<<endl;
            }else{
                cout<<(n/(m+1))*(m*a)+(n%(m+1))*b<<endl;
            }
        }
    }
    return 0;
}