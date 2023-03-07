#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
int A[maxn],B[maxn];
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int c=0,s=0;
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        memcpy(B,A,sizeof(A));
        sort(B,B+n);
        int minp=0,maxp=n-1;
        int l=0,r=n-1;
        for(;r-l+1>=4;){
            if(A[l]==B[minp]){
                l++,minp++;
            }else if(A[l]==B[maxp]){
                l++,maxp--;
            }else if(A[r]==B[minp])
            {
                r--,minp++;
            }else if(A[r]==B[maxp]){
                r--,maxp--;
            }else{
                break;
            }
        }    
        if(r-l+1>=4){
            cout<<l+1<<' '<<r+1<<endl;
        }else{
            cout<<-1<<endl;
        }
    }
    return 0;
}