#include <bits/stdc++.h>
using namespace std;
const int maxn = 10000;
typedef long long ll;
int N, K;
vector<int> g[maxn][10];
// g[x][i]表示x状态的
//  可达的，含i个King的状态向量
int bitnum[maxn];
ll dp[10][100][maxn];//dp[i][j]表示前i行使用了j个king的状态数
bool compatible(int a, int b)
{
    if (a & b)
        return false;
    if ((a << 1) & b)
        return false;
    if ((b << 1) & a)
        return false;
    return true;
}
bool ok(int t){
    int f=0;
    for(int i=0;i<N;i++){
        if((1<<i)&t){
            if(f)return false;
            f=1;
        }else{
            f=0;
        }
    }
    return true;
}
int getbits(int t)
{
    int k=t;
    if (bitnum[t])
        return bitnum[t];
    int ans = 0;
    while (t)
    {
        t -= (t & -t);
        ans++;
    }
    return bitnum[k] = ans;
}
void init()
{
    // memset(bitnum, -1, sizeof(bitnum));
    memset(dp,-1,sizeof(dp));
    g[0][0].push_back(0) ;
    for (int i = 0; i < (1 << N); i++)
    {
        if(!ok(i))continue;
        for (int j = i + 1; j < (1 << N); j++)
        {
            if(!ok(j))continue;
            if (compatible(i, j))
            {
                g[i][getbits(j)].push_back(j);
                // cout<<"g"<<i<<' '<<getbits(j)<<"push"<<j<<endl;
                g[j][getbits(i)].push_back(i);
                // cout<<"g"<<j<<' '<<getbits(i)<<"push"<<i<<endl;
            }
        }
    }
}
ll dfs(int d,int _used,int fa){
    if(dp[d][_used][fa]!=-1)return dp[d][_used][fa];
    if(d>N)return 0;
    else if(d==N){
        // if(g[fa][K-_used].size())
        // cout<<"fa="<<fa<<"used="<<_used<<"return"<<g[fa][K-_used].size()<<endl;
        if(K-_used>N)return 0;
        return g[fa][K-_used].size();
    };
    ll ans=0;
    for(int i=0;i<=min(K-_used,N);i++){
        //当前行用i个
        for(int j=0;j<g[fa][i].size();j++){
            ans+=dfs(d+1,_used+i,g[fa][i][j]);
        }
    }
    return dp[d][_used][fa]=ans;
}

int main()
{
    
    cin >> N >> K;
    init();
    cout<<dfs(1,0,0)<<endl;
    return 0;
}