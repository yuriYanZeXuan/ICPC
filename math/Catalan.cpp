#include<bits/stdc++.h>
using namespace std;
/*
    卡特兰数有如下三种表达方式:
    f(n)=f(0)f(n-1)+f(1)f(n-2)+...+f(n-1)f(0)
    f(n)=C_2n^n-C_2n^(n-1)
    f(n)=C_2n^n/(n+1)
    可用于多边形划分，括号出入栈总数的问题的求解
    从出入栈考虑最后一个出来的k，可将问题划分成f(k-1)*f(n-k)的两个小规模问题
*/
const int maxn=100;
long long f[maxn];
void gen(int n){
    // 双层for循环
    f[0]=f[1]=1;
    for(int i=2;i<=n;i++){
        for(int j=0;j<i;j++){
            f[i]+=f[j]*f[i-j-1];
        }
    }
}
int main(){
    int n;
    cin>>n;
    gen(n);
    for(int i=0;i<=n;i++){
        cout<<"f("<<i<<")="<<f[i]<<endl;
    }
    return 0;
}
