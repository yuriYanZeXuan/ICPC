#include<bits/stdc++.h>
using namespace std;
int L,n,m;
int a[50005];
bool ok(int c){
    int sum=m,la=0;
    for(int i=1;i<=n;i++){
        if(la+c<=a[i]){
            la=a[i];
        }else{
            if(!(sum--))
                return 0;
        }
    }
    if(la+c>L)
        if(!(sum--))return 0;
    return 1;
}
int main(){
    cin>>L>>n>>m;
    for(int i=1;i<=n;i++)
        cin>>a[i];
    sort(a+1,a+n+1);
    int l=0,r=L;
    while(l!=r){
        int mid=(l+r+1)>>1;
        if(ok(mid)){
            l=mid;
        }else{
            r=mid-1;
        }
    }
    cout<<l<<endl;
    return 0;
}