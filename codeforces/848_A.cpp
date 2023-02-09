#include<bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n,k,sum=0;
        bool f=false,f2=false,ex=false;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>k;
            sum+=k;
            if(k==1)f=false;
            else{
                if(k==-1&&f==true){
                    f2=true;
                }
                f=true;
                ex=true;
            }

        }
        if(f2){
            cout<<sum+4<<endl;
        }else if(ex){
            cout<<sum<<endl;
        }else{
            cout<<sum-4<<endl;
        }
    }
    return 0;
}