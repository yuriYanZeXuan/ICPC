#include<bits/stdc++.h>
using namespace std;
const int maxn=1000000+10;
char str[maxn];
struct sk{
    int f,v;
    bool operator<(const sk& t){
        return v<t.v;
    }
}S[maxn];
int main()
{
    int t;
    cin>>t;
    while(t--){
        long long ans=0;
        string s;
        int n,type;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>S[i].f;
        }
        for(int i=0;i<n;i++){
            cin>>S[i].v;
        }
        sort(S,S+n);
        // ans=S[0].v;
        // type=S[0].f;
        vector<int> v[2];
        memset(v,0,sizeof(v));
        for(int i=0;i<n;i++){
            v[S[i].f].push_back(S[i].v);
        }
        if(v[0].size()>v[1].size()){
            ans=v[0].front();
            v[0].front()=0;
            type=0;
        }else if(v[0].size()<v[1].size()){
            ans=v[1].front();
            v[1].front()=0;
            type=1;
        }else if(v[0].front()>v[1].front()){
            ans=v[1].front();
            v[1].front()=0;
            type=1;
        }else if(v[0].front()<=v[1].front()){
            ans=v[0].front();
            v[0].front()=0;
            type=0;
        }
        int flag=0;
        while(!v[!type].empty()){
            ans+=v[!type].back()*2;
            v[!type].pop_back();
            type=!type;
        }
        while(!v[type].empty()){
            ans+=v[type].back();
            v[type].pop_back();
        }
        cout<<ans<<endl;
    }
    return 0;
}