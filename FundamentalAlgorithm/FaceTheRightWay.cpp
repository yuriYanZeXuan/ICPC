#include<bits/stdc++.h>
using namespace std;
const int maxn=1e4;
int A[maxn],f[maxn];
int M,N;
int ok(int K){
    int res=0;
    int sum=0;
    memset(f,0,sizeof(f));
    for(int i=0;i<N-K+1;i++){
        if((A[i]+sum)%2==0){
            res++;
            f[i]=1;
        }
        sum+=f[i];
        if(i>=K-1){
            sum-=f[i-K+1];
        }
    }
    for(int i=N-K+1;i<N;i++){
        if((sum+A[i])%2==0){
            return -1;
        }
        if(i-K+1>=0){
            sum-=f[i-K+1];
        }
    }
    return res;
}
int main(){
    // int N;
    cin>>N;
    char c;
    for(int i=0;i<N;i++){
        cin>>c;
        if(c=='B'){
            A[i]=0;
        }else{
            A[i]=1;
        }
    }
    int ans=0x3f3f3f3f,k;
    for(int i=1;i<=N;i++){
        int r=ok(i);
        if(r>=0){
            if(r<ans){
                ans=r;
                k=i;
            }
        }
    }
    cout<<k<<' '<<ans<<endl;
    return 0;
}