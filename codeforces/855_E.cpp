#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
// char s[maxn],t[maxn];
int cnt1[300],cnt2[300];
pair<int,int> dir[]={{0,3},{0,4},{1,4},{1,5},{2,5},{2,6},{3,6}};//7
int f[10000000];
int vis[maxn*80];
int rev[maxn];
int n,k;
int find(int x){
    return f[x]==x?x:f[x]=find(f[x]);
}
void unite(int x,int y){
    x=find(x),y=find(y);
    if(x!=y){
        f[x]=y;
    }
}
void preop(){
    for(int i=1;i<=1000000;i++)f[i]=i;
}
int getn(string s){
    int c=0,A[10]={0},f;
    for(int i=0;i<n;i++){
        f=0;
        for(int j=0;j<i;j++){
            if(s[j]==s[i]){
                A[i]=A[j];
                f=1;
                break;
            }
        }
        if(!f)
        {
            A[i]=++c;
            rev[s[i]]=A[i];
        }
    }
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans*8+A[i];
    }
    return ans;
}
int calcn(string s){
    int ans=0;
    for(int i=0;i<n;i++){
        ans=ans*8+rev[s[i]];
    }
    return ans;
}
int main(){
    int T;
    preop();
    cin>>T;
    while(T--){
        string s,t;
        memset(cnt1,0,sizeof(cnt1));
        memset(cnt2,0,sizeof(cnt2));
        cin>>n>>k;
        cin>>s>>t;
        for(int i=0;i<n;i++){
            cnt1[s[i]-'a']++;
            cnt2[t[i]-'a']++;
        }
        int f=1;
        for(int i=0;i<26;i++){
            if(cnt1[i]!=cnt2[i]){
                f=0;
                cout<<"NO"<<endl;
                break;
            }
        }
        if(!f)continue;
        if(n>7){
            cout<<"YES"<<endl;
            continue;
        }
        int num1=getn(s),num2=calcn(t);
        if(find(num1)==find(num2)){
            cout<<"YES"<<endl;
            continue;
        }
        if(!vis[num1]){
            // bfs
            queue<string> q;
            q.push(s);
            vis[num1]=1;
            while(!q.empty()){
                string m=q.front();
                q.pop();
                for(int i=0;i<7;i++){
                    if(dir[i].second<n){
                        swap(m[dir[i].first],m[dir[i].second]);
                        int n2=calcn(m);
                        if(!vis[n2]){
                            unite(n2,num1);
                            vis[n2]=1;
                            q.push(m);
                        }
                        swap(m[dir[i].first],m[dir[i].second]);
                    }
                }
            }
            if(find(num1)==find(num2)){
                cout<<"YES"<<endl;
            }else{
                cout<<"NO"<<endl;
            }
        }else{
            cout<<"NO"<<endl;
        }
    }
    return 0;
}