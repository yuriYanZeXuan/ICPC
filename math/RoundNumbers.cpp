#include<iostream>
#include<cmath>
using namespace std;
int _cnt[33]={0};//长i位的100...0~111...1中的RoundNumber数量
int cnt[33]={0};//[0~100...0](i位)中的RoundNumber数量
int c[33][33];
int C(int a,int b){
    if(c[a][b])return c[a][b];
    if(b==0)return c[a][b]=1;
    c[a][b]=1;
    if(a>=10){
        return c[a][b]=C(a-1,b-1)+C(a-1,b);
    }else{
        for(int i=a,j=1;j<=b;i--,j++){
            c[a][b]=c[a][b]*i;
        }
        for(int i=1;i<=b;i++){
            c[a][b]/=i;
        }
    }
    return c[a][b];
}
void pre(){
    _cnt[0]=0;cnt[0]=0;
    _cnt[1]=1;cnt[1]=1;
    for(int i=2;i<=32;i++){
        for(int j=ceil(1.0*i/2);j<=i-1;j++)
            _cnt[i]+=C(i-1,j);
        cnt[i]=cnt[i-1]+_cnt[i-1];
    }
}
int countone(int n){
    int ans=0;
    while(n&(-n)){
        ans++;
        n-=n&(-n);
    }
    return ans;
}
int getlen(int n){
    int len=31;
    if(!n)return 1;
    for(;!((1<<len)&n);len--);
    return len+1;
}
int totlen;
bool judge(int n,int zero){
    int eve=0;
    for(int i=0;i<getlen(n);i++){
        if(!((1<<i)&n))eve++;
    }
    if(eve+zero>=ceil(1.0*totlen/2))return true;
    else return false;
}
int dp(int n,int prezero,bool f){//[0~n]中的RoundNumber的数量,考虑已有前导零
    int ans=0,len;
    // cout<<"in"<<n<<endl;
    len=getlen(n);
    int nc=n-(1<<(len-1));
    if(f){
        if(n==1||n==0)return 1;
        if(nc==0)return cnt[len];
        ans=cnt[len]-1+dp(nc,len-getlen(nc)-1,0);
    // cout<<"out"<<ans<<endl;
        return ans;
    }else{
        // 000...1...1...
        if(ceil(1.0*totlen/2)-prezero<=0){
            //都可以
            ans+=(1<<(len-1));
        }else{
            for(int i=ceil(1.0*totlen/2)-prezero-1;i<=len-1;i++){
                ans+=C(len-1,i);
            }
            // ans+=(judge(n,prezero)?1:0);
        }
        if(nc==0)return ans+judge(n,prezero);
        ans+=dp(nc,prezero+len-getlen(nc)-1,0);
        return ans;
    }
}
int main(){
    pre();
    int p,q;
    cin>>p>>q;
    // for(int i=1;i<=50;i++){
    //     totlen=getlen(i);
    //     cout<<i<<"->"<<dp(i,0,1)<<endl;
    // }
    // int i=1111111;
    // totlen=getlen(i);
    // cout<<dp(i,0,1);
    // totlen=getlen(p);
    // cout<<dp(p,0,1)<<endl;
    if(p){
        totlen=getlen(p-1);
        p=dp(p-1,0,1);
    }else{
        p=0;
    }
    totlen=getlen(q);
    q=dp(q,0,1);
    cout<<q-p<<endl;
    //12:0,10,100,1000,1100,1010,1001
    //16:0,10,100,1000,10000,1100,1010,1001
    //11:0,10,100,1000,1010,1001
    return 0;
}
