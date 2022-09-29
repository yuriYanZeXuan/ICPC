#include<bits/stdc++.h>
using namespace std;
const int maxn=10000;
    int n;
struct block{
    int x,y,h;
    
    block():x(),y(),h(){}

    block(int x,int y,int h):x(x),y(y),h(h){}

    bool has(block &b){
        if(min(x,y)>min(b.x,b.y)&&max(x,y)>max(b.x,b.y)){
            return true;
        }
        return false;
    }

}Blocks[maxn];
vector<int> v[maxn];//v[i]表示v能叠的砖块向量
int maxheight;
int rem[maxn];
int dfs(int x){
    if(rem[x])return rem[x];
    int ans=Blocks[x].h;
    // cout<<"dfsing"<<x<<endl;
    for(int i=0;i<v[x].size();i++)
    {
        ans=max(ans,dfs(v[x][i])+Blocks[x].h);
    }
    maxheight=max(maxheight,ans);
    return rem[x]=ans;
}
void print(){
    for(int i=0;i<3*n;i++){
        cout<<i<<"砖块"<<Blocks[i].x<<" "<<Blocks[i].y<<" "<<Blocks[i].h<<endl;
    }
}
int main()
{
    int cnt=0;
    while(cin>>n&&n){
        cnt++;
        int a,b,c;
        maxheight=0;
        memset(Blocks,0,sizeof(Blocks));
        memset(v,0,sizeof(v));
        memset(rem,0,sizeof(rem));
        // cout<<"he"<<endl;
        for(int i=0;i<n;i++){
            cin>>a>>b>>c;
            Blocks[3*i]=block(a,b,c);
            Blocks[3*i+1]=block(a,c,b);
            Blocks[3*i+2]=block(c,b,a);
        }
        for(int i=0;i<3*n;i++){
            for(int j=0;j<3*n;j++){
                if(Blocks[i].has(Blocks[j])){
                    v[i].push_back(j);
                    // cout<<i<<"has"<<j<<endl;
                }
            }
        }
        for(int i=0;i<3*n;i++){
            dfs(i);
        }
        // Case 3: maximum height = 28
        printf("Case %d: maximum height = %d\n",cnt,maxheight);
    }
    return 0;
}