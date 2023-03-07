#include<bits/stdc++.h>
using namespace std;
typedef unsigned long long ull;
const int maxn=3e2;
ull p[maxn],h[maxn];
ull get(int l,int r){
    return h[r]-h[l-1]*p[r-l+1];//注意高差等于右边三角形的底边，而非左边！！！！
}
int N;
unordered_set<ull> table;
bool ok(int len){
    table.clear();
    for(int i=1;i<=N-len+1;i++){
        if(table.find(get(i,i+len-1))!=table.end())return false;
        else table.insert(get(i,i+len-1));
    }
    return true;
}
int main(){
    string s;
    cin>>N;
    cin>>s;
    p[0]=1;
    for(int i=1;i<=N;i++){
        p[i]=p[i-1]*27;
        h[i]=h[i-1]*27+(s[i-1]-'A');
    }
    // cout<<get(1,2)<<' '<<get(2,3)<<" "<<get(3,4)<<endl;
    int l=1,r=N,mid=r+l>>1;
    while(l!=r)
    {
        if(ok(mid)){
            r=mid;
        }else{
            l=mid+1;
        }
        mid=l+r>>1;
    }
    cout<<mid<<endl;
    return 0;
}