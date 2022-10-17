#include<bits/stdc++.h>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        string s1,s2;
        cin>>s1>>s2;
        int c1=0,c2=0;
        c1=s1.length();
        c2=s2.length();
        if(s1.back()=='S'){
            c1*=-1;
        }else if(s1.back()=='L'){
            c1*=1;
        }else{
            c1*=0;
        }
        if(s2.back()=='S'){
            c2*=-1;
        }else if(s2.back()=='L'){
            c2*=1;
        }else{
            c2*=0;
        }
        if(c1>c2){
            cout<<">"<<endl;
        }else if(c1==c2){
            cout<<"="<<endl;
        }else{
            cout<<"<"<<endl;
        }
    }
    return 0;
}