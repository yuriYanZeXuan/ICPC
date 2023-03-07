// #include<bits/stdc++.h>
#include<math.h>
#include<iostream>
using namespace std;
const int maxn=2e4;
double c[maxn];
int N,K;
bool ok(double t){
    int num=0;
    for(int i=0;i<N;i++){
        double s=c[i];//用int是极其致命的错误......
        while(s>=t){
            num++;
            s-=t;
        }
    }
    if(num>=K){
        return true;
    }
    return false;
}
double eps=1e-5;//eps过大...
int main()
{
    cin>>N>>K;
    for(int i=0;i<N;i++){
        cin>>c[i];
    }
    double lft=0,rit=1e7,mid=(lft+rit)/2;//lft不从0开始......
    int cnt=100;
    while(cnt--){
        if(ok(mid)){
            lft=mid;
        }else{
            rit=mid;
        }
        mid=(lft+rit)/2;
    }
    // cout<<mid<<endl;
    printf("%.2f\n",floor(rit*100)/100);
    return 0;
}