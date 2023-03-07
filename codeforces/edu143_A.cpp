#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,m;
        cin>>n>>m;
        string s,t;
        cin>>s>>t;
        reverse(t.begin(),t.end());
        string a=s+t;
        int i,j;
        for(i=0;i<a.length()-1;i++){
            if(a[i]==a[i+1])
            {
                break;
            }
        }
        for(j=a.length()-1;j>i;j--){
            if(a[j]==a[j-1])break;
        }
        if(j==i||j-i==1){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}