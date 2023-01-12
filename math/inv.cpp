//拓展欧几里德算法：
int exgcd(int a,int b,int &x,int &y){
    if(!b){
        x=1,y=0;
        return a;//gcd(a,b)=a
    }
    int gcd= exgcd(b,a%b,x,y);
    //ax+by=bx_0+(a%b)y_0  =>x=y_0,y=x_0-a/b*y_0
    int t=x;
    x=y;
    y=t-a/b*y;
    return gcd;
}
//逆元:若a*x_=1(mod b),则称a,x互为逆元  ==>  ax+by=1
int exgcd_inv(int a,int b){
    int x,y;
    int t=exgcd(a,b,x,y);
    return t==1?(x+b)%b:-1;//若gcd!=1,则返回-1表示无解
}
int pow_mod(int a,int b,int m){//带模快速幂
    int res=1;
    while(b){
        if(b&1)res=res*a%m;
        a=a*a%m;
        b>>=1;
    }
    
}

//Euler定理,a^-1_=a^phi(m)-1   (mod m),时间复杂度O(sqrt(n))
int get_phi(int n){
    int res=n;
    for(int i=2;i<=n/i;i++){//每次把因数除完
        if(n%i==0){
            res=res/i*(i-1);
            while(n%i==0)n/=i;
        }
    }
    if(n>1)res=res/n*(n-1);//n是素数
    return res;
}

//递推打表
const int N=1000000;
long long inv[N];
void mod_inverse(long long n,long long mod){
    inv[0]=inv[1]=1;
    for(int i=2;i<=n;i++){
        inv[i]=(mod-mod/i)*inv[mod%i]%mod;
    }
}