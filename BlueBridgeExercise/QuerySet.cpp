#include<bits/stdc++.h>
using namespace std;
const int maxn=3e4;
int father[maxn],siz[maxn];
int getfather(int t)
{
    return father[t]==t?t:father[t]=getfather(father[t]);
}
void unite(int x,int y)
{
    x=getfather(x),y=getfather(y);
    if(x!=y){
        if(siz[x]<siz[y])swap(x,y);
        father[y]=x;
        siz[x]+=siz[y];
    }
}
int main(){
    cin.tie(0);
    ios::sync_with_stdio(false);
    int N,M;
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        father[i]=i;//并查集需要初始化
        siz[i]=1;
    }
    for(int i=0;i<M;i++){
        int x,y;
        cin>>x>>y;
        unite(x,y);
    }
    int Q;
    cin>>Q;
    while(Q--){
        int c,d;
        cin>>c>>d;
        if(getfather(c)==getfather(d)){
            cout<<"Yes\n";//endl会刷新输出流，用\n更快
        }else{
            cout<<"No\n";
        }
    }

    return 0;
}