#include<bits/stdc++.h>
using namespace std;
int main(){
    __int128_t t;
    t=1ll<<63;//无法直接赋予位移量
    // t=t*8;
    cout<<sizeof(long long)<<endl;
    cout<<__builtin_popcount(t)<<endl;
    // cout<<t<<endl;   error!__int128_t不能用作输出！
    return 0;
}