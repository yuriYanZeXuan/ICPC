#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    long long x,y;
    while(t--){
        cin>>x>>y;
        if(x>y)swap(x,y);
        // long long dif=abs(x-y);
        int len=2*abs(x-y);
        int d=1;
        cout<<len<<endl;
        for(int i=0,j=x;i<len;i++){
            cout<<j<<' ';
            if(j==y){
                d=-1;
            }
            j+=d;
        }
        cout<<endl;
    }
    return 0;
}