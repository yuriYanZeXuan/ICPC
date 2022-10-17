#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while (t--)
    {
        int n;
        cin>>n;
        if(n%2==0){
            for(int i=n;i>=1;i--){
                cout<<i;
                if(i!=1)cout<<" ";
            }
            cout<<endl;
        }else{
            if(n==3)cout<<-1<<endl;
            else{
                cout<<n<<" "<<n-1<<' ';
                for(int i=1;i<=n-2;i++){
                    cout<<i;
                    if(i!=n-2)cout<<' ';
                }
                cout<<endl;
            }
        }
    }
    
    return 0;
}