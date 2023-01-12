#include<bits/stdc++.h>
using namespace std;
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;
    }
    int gcd=exgcd(b,a%b,x,y);
    int t=x;
    x=y;
    y=t-a/b*y;
    return gcd;
}
int China(int W[],int B[],int k){//W为按多少排列，B为剩余个数，W>B,k为组数
/*
    x_=B[i]  (mod W[i])
*/
    int x,y,a=0,m,n=1;
    for(int i=0;i<k;i++)
    {
        n*=W[i];
    }
    for(int i=0;i<k;i++){
        m=n/W[i];
        exgcd(W[i],m,x,y);
        a=(a+y*m*B[i])%n;
    }
    if(a>0)return a;
    else return a+n;
}
int main()
{
    int W[]={23,28,33};
    int B[3];
    for(int i=1;;i++){
        cin>>B[0]>>B[1]>>B[2];
        if(B[0]==-1&&B[1]==-1&&B[2]==-1)break;
        // Case 1: the next triple peak occurs in 21252 days.
        int d;
        cin>>d;
        printf("Case %d: the next triple peak occurs in %d days.\n",i,-d+China(W,B,3)>0?-d+China(W,B,3):-d+China(W,B,3)+21252);

    }
    return 0;
}