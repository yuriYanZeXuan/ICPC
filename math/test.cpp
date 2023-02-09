//Memory Time 
//224K   16MS  
 
// #include<iostream>
// #include<cmath>
#include<bits/stdc++.h>
using namespace std;
 
int c[33][33]={0};
int bin[35];  //十进制n的二进制数
int _cnt[33]={0};//长i位的100...0~111...1中的RoundNumber数量
int cnt[33]={0};//[0~100...0](i位)中的RoundNumber数量
// int c[32][32];
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
/*打表，计算nCm*/
 
void play_table(void)
{
	for(int i=0;i<=32;i++)
		for(int j=0;j<=i;j++)
			if(!j || i==j)
				c[i][j]=1;
			else
				c[i][j]=c[i-1][j-1]+c[i-1][j];
//	c[0][0]=0;
	return;
}
 
/*十进制n转换二进制，逆序存放到bin[]*/
 
void dec_to_bin(int n)
{
	bin[0]=0;   //b[0]是二进制数的长度
	while(n)
	{
		bin[++bin[0]]=n%2;
		n/=2;
	}
	return;
}
 
/*计算比十进制数n小的所有RN数*/
 
int round(int n)
{
	int i,j;
	int sum=0;  //比十进制数n小的所有RN数
	dec_to_bin(n);
 
	/*计算长度小于bin[0]的所有二进制数中RN的个数*/
 
	for(i=1;i<bin[0]-1;i++)
		for(j=i/2+1;j<=i;j++)
			sum+=c[i][j];
    // cout<<n<<"->sum="<<sum<<endl;
 
	/*计算长度等于bin[0]的所有二进制数中RN的个数*/
 
	int zero=0;  //从高位向低位搜索过程中出现0的位的个数
	for(i=bin[0]-1;i>=1;i--)
		if(bin[i])   //当前位为1
			for(j=(bin[0]+1)/2-(zero+1);j<=i-1;j++)
				sum+=c[i-1][j];
		else
			zero++;
 
	return sum;
}
void pre(){
    _cnt[0]=0;cnt[0]=0;
    _cnt[1]=1;cnt[1]=1;
    for(int i=2;i<=32;i++){
        for(int j=ceil(1.0*i/2);j<=i-1;j++)
            _cnt[i]+=C(i-1,j);
        cnt[i]=cnt[i-1]+_cnt[i-1];
        // cout<<"cnt"<<i<<"="<<cnt[i]<<endl;
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
        if(n==1||n==0 )return 1;
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
int d[33][33];
int main(void)
{
	play_table();
    // cout<<round(16);
    // memcpy(d,c,sizeof(c));
    // pre();
    // for(int i=0;i<=32;i++){
    //     for(int j=0;j<=i;j++){
    //         if(d[i][j]!=C(i,j))cout<<"find"<<i<<"--"<<j<<endl;
    //     }
    // }
    // int i=18;
    // cout<<round(1<<i);
    // for(int i=1;i<=30;i++){
        // totlen=getlen(i);
        // if(round((1<<i)+1)+1-dp(1<<i,0,1)){
        // cout<<"check"<<i<<"->"<<round((1<<(i-1))+1)+1-cnt[i]<<endl;
        // }
        // cout<<i<<"->"<<round(i+1)+1<<"---"<<dp(i,0,1)<<endl;

    // }
        //38443
        // int i=17;
        // totlen=getlen(i);
        // cout<<i<<"->"<<round(i+1)+1<<endl;
        // cout<<dp(i,0,1);
        // cout<<i<<"->"<<<<endl;
    int a,b;
    cin>>a>>b;
    cout<<round(b+1)-round(a)<<endl;
	return 0;
}