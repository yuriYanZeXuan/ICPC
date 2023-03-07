#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        string s;
        cin>>n;
        cin>>s;
        int i,cnt;bool f=true;
        for(cnt=0,i=0;(s[i]=='m'||s[i]=='M')&&i<n;i++,cnt++);
        if(!cnt)f=false;
        for(cnt=0;(s[i]=='e'||s[i]=='E')&&i<n;i++,cnt++);
        if(!cnt)f=false;
        for(cnt=0;(s[i]=='o'||s[i]=='O')&&i<n;i++,cnt++);
        if(!cnt)f=false;
        for(cnt=0;(s[i]=='w'||s[i]=='W')&&i<n;i++,cnt++);
        if(!cnt)f=false;

        if(f&&i==n){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}