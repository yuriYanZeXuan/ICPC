#include<bits/stdc++.h>
using namespace std;
const int maxn=1000;
int A[maxn],B[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,a=0,b=0;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>A[i];
            if(A[i])a++;
        }
        int cnt=0;
        for(int i=0;i<n;i++){
            cin>>B[i];
            if(B[i])b++;
            if(A[i]!=B[i])cnt++;
        }
        if(abs(a-b)==cnt)cout<<cnt<<endl;
        else cout<<abs(a-b)+1<<endl;
    }
    return 0;
}