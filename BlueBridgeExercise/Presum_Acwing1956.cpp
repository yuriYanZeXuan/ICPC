#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5;
int A[maxn];
long long sum[maxn];
int main(){
    int n;
    cin>>n;
    for(int i=1;i<=n;i++){
        cin>>A[i];
        sum[i]=sum[i-1]+A[i];
    }
    if(sum[n]%3){
        cout<<0<<endl;
    }else{
        long long tri=sum[n]/3;
        vector<int> v1,v2;
        for(int i=1;i<=n;i++){
            if(sum[i]==tri)v1.push_back(i);
            if(sum[n]-sum[i-1]==tri)v2.push_back(i);
        }
        long long ans=0;
        for(int i=0;i<v1.size();i++){
            int p=upper_bound(v2.begin(),v2.end(),v1[i])-v2.begin();
            if(v2[p]-v1[i]==1)
                ans+=v2.size()-p-1;
            else   
                ans+=v2.size()-p;
        }
        cout<<ans<<endl;

    }

    return 0;
}
