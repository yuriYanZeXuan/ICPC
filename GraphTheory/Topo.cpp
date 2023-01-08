#include<bits/stdc++.h>
using namespace std;
const int maxn=100;
vector<int> g[maxn];
// void dfs(int x,vector<int> deg,int dep){
//     if()
// }
int main(){
    g[1].push_back(2);
    g[2].push_back(4);
    g[4].push_back(3);
    g[4].push_back(7);
    g[7].push_back(6);
    g[3].push_back(5);
    g[9].push_back(7);
    g[9].push_back(8);
    g[8].push_back(6);
    g[6].push_back(5);
    vector<int> deg;
    deg.resize(10,0);
    for(int i=0;i<10;i++){
        for(auto v:g[i]){
            deg[v]++;
        }
    }
    return 0;
}