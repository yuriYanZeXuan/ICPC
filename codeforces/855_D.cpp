#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
typedef unsigned long long ull;
char A[maxn];
ull p[maxn];
ull H[maxn];
set<ull> table;
ull get(int l,int r){//1<=l,r<=n
    if(l>r)return 0;
    return H[r]-H[l-1]*p[r-l+1];
}
int main(){
    int t;
    cin>>t;
    p[0]=1;
    for(int i=1;i<=maxn;i++){
        p[i]=p[i-1]*27;
    }
    while(t--){
        int n;
        table.clear();
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>A[i];
            H[i]=H[i-1]*27+A[i]-'a';
        }
        for(int i=2;i<=n;i++){
            table.insert(get(1,i-2)*p[n-i]+get(i+1,n));
        }
        cout<<table.size()<<endl;
    }
    return 0;
}