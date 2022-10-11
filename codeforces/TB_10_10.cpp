#include<bits/stdc++.h>
using namespace std;
const int maxn=100010;
int gcd(int a,int b){
    return a%b==0?b:gcd(b,a%b);
}
int A[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n,t1,t2;
        cin>>n;
        bool f=true;
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        for(int i=1;i<n-1;i++){
            if(A[i]!=gcd(A[i-1]*A[i]/gcd(A[i-1],A[i]),
                    A[i]*A[i+1]/gcd(A[i],A[i+1])))  {
                        f=false;
                        break;
            }
        }
        if(f){
            cout<<"YES"<<endl;
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}