#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
int indeg[maxn];
vector<int> g[maxn];
int A[maxn],p=0;
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int T;
    cin>>T;
    vector<pair<int,int>> v;
    while(T--){
        int n,m,t,x,y;
        cin>>n>>m;
        v.clear();
        // memset(g,0,sizeof(g));
        // memset(indeg,0,sizeof(indeg));
        for(int i=0;i<=n;i++){
            g[i].clear();
            indeg[i]=0;
        }
        for(int i=0;i<m;i++)
        {
            cin>>t>>x>>y;
            if(t){
                g[x].push_back(y);
                indeg[y]++;
            }else{
                v.push_back({x,y});
            }
        }
        stack<int> S;
        p=0;
        for(int i=1;i<=n;i++){
            if(indeg[i]==0){
                S.push(i);
            }
        }
        int cnt=S.size();
        while(!S.empty()){
            int elem=S.top();
            A[elem]=++p;
            S.pop();
            for(int i=0;i<g[elem].size();i++){
                indeg[g[elem][i]]--;
                if(indeg[g[elem][i]]==0){
                    S.push(g[elem][i]);
                    cnt++;
                }
            }
        }
        if(cnt<n)
        {
            cout<<"NO"<<endl;
        }else{
            cout<<"YES"<<endl;
            for(int i=1;i<=n;i++){
                for(auto e:g[i]){
                    cout<<i<<' '<<e<<endl;
                }
            }
            for(auto e:v)
            {
                if(A[e.first]<A[e.second]){
                    cout<<e.first<<' '<<e.second<<endl;
                }else{
                    cout<<e.second<<' '<<e.first<<endl;
                }
            }
        }
    }
    return 0;
}