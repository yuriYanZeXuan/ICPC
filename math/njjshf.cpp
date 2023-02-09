#include<bits/stdc++.h>
using namespace std;
int n;
int f[20][20];
void solve(int step,int i,int j){
//构造法求解奇数幻方，从上方中点出发，向右上角延伸，如果有已经填过的
//就从正下方一行重新开始重复构造
    if(step==n*n+1)return;
    f[i][j]=step;
    if(f[(i-1+n)%n][(j+1)%n])
        solve(step+1,(i+1)%n,j);
    else 
        solve(step+1,(i-1+n)%n,(j+1)%n);
}
int main(){
    cin>>n;
    solve(1,0,n/2);
    for(int i=0;i<n;i++,puts("")){
        for(int j=0;j<n;j++){
            printf("%4d",f[i][j]);
        }
    }
    return 0;
}