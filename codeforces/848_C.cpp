#include<bits/stdc++.h>
using namespace std;
char A[30];
char a[200000],b[200000],c[200000];
int n,k,num;
bool next_combination(int a,int *b){
    //A是所有字母,a是输入，b是输出
    if(a>=((1<<num)-(1<<(num-k))))return false;
    int target=a;
    for(int i=0;i<k;i++){
        int lb=target&(-target);
        if(a&(lb<<1)){
            //低位已满
            target-=lb;
            continue;
        }else{
            target&=(-lb);//清除低位
            target+=lb;//进位
            for(int j=0;j<i;j++){
                target+=(1<<j);
            }//补足地位
            *b=target;
            return true;
        }
    }
}
int getindex(int p){//p=2^i,p!=0
    if(!p)return 0;
    for(int i=0;;i++){
        if((1<<i)&p){
            return i;
        }
    }
    return 0;
}
long long calc(int arg){
    long long res=0,cnt=0;
    for(int i=0;i<n;i++){
        int pos=lower_bound(c,c+num,a[i])-c;
        if(((arg>>pos)&1)||a[i]==b[i])cnt++;
        else{
            res+=(cnt+1)*cnt/2;
            cnt=0;
        }
    }
    res+=(cnt+1)*cnt/2;
    return res;
}
int main(){
    int t;
    std::ios::sync_with_stdio(false);
    std::cin.tie(nullptr);
    // while(next_combination(ans,&ans)){
    //     cout<<i++<<"  :"<<ans<<endl;
    //     if(i>40)break;
    // }
    // cout<<"f="<<f<<"ans="<<ans<<endl;
    cin>>t;
    // memset(A,0,sizeof(A));
    while(t--){
        cin>>n>>k;
        cin>>a>>b;
        memcpy(c,a,sizeof(a));
        sort(c,c+n);

        num=unique(c,c+n)-c;
        // for(int i=0;i<a.length();i++){
        //     A[a[i]-'a'];
        // }
        int beg=(1<<k)-1,nex;
        long long ans=0;
        while(next_combination(beg,&nex)){
            ans=max(ans,calc(beg));
            beg=nex;
        }
        ans=max(ans,calc(beg));
        cout<<ans<<endl;
    }
    return 0;
}