// #include<bits/stdc++.h>
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int N,C;
const int maxn=1e7;
int c[maxn];
bool ok(int dis){
    int s=C-1;
    int pos=c[0];
    for(int i=1;i<N&&s;i++){
        if(c[i]-pos>=dis){
            pos=c[i];
            s--;
        }
    }
    if(s){
        return false;
    }
    return true;
}
int main(){
    cin>>N>>C;
    for(int i=0;i<N;i++){
        cin>>c[i];
    }
    sort(c,c+N);
    int l=0,r=1e7,mid=(l+r)>>1;
    for(int i=0;i<100;i++){
        if(ok(mid)){
            l=mid;
        }else{
            r=mid;
        }
        mid=(l+r)>>1;
    }
    if(ok(r)){
        cout<<r<<endl;
    }else{
        cout<<l<<endl;
    }
    return 0;
}