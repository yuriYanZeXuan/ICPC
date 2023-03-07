#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5;
int a[maxn],b[maxn];
long long sum[maxn],res[maxn];
long long d[maxn];
int Tag=0;
int tag[maxn];
void reset(){
    Tag++;
}
inline int lowbit(int x){return x&(-x);}
void update(int k,int v){
    while(k<maxn){
        if(tag[k]!=Tag)
            d[k]=0;
        d[k]+=v;
            tag[k]=Tag;
        k+=lowbit(k);
    }
}
void add(int l,int r,int v){
    //区间加求单点值
    // d[l]+=v;
    update(l,v);
    // d[r+1]-=v;
    update(r+1,-v);
}   
long long getsum(int x){
    long long res=0;
    while(x){
        if(tag[x]==Tag)
        res+=d[x];
        x-=lowbit(x);
    }  
    return res;
}
int binarysearch(int l,int r,int v)
{
    int mid=(l+r)>>1;
    int left=l,right=r;
    while(mid!=left){
        if(sum[mid]-sum[l-1]<=v){
            left=mid;
        }else{
            right=mid;
        }
        mid=(left+right)>>1;
    }

    return sum[mid]-sum[l-1]<=v?mid+1:mid;//在mid处剩余酒量
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        Tag++;
        cin>>n;
        for(int i=1;i<=n;i++){
            cin>>a[i];
        }
        for(int i=1;i<=n;i++){
            cin>>b[i];
        }
        sum[0]=0;
        for(int i=1;i<=n;i++){
            res[i]=0;
            if(i==1)
                sum[1]=b[1];
            else
                sum[i]=b[i]+sum[i-1];
        }
        for(int i=1;i<=n;i++){
            int lb=binarysearch(i,n+1,a[i])-i;
            if(lb)
                add(i,i+lb-1,1);//从i到lb的所有drinker都满足了一次
            res[i+lb]+=a[i]-(sum[i+lb-1]-sum[i-1]);
            cout<<res[i]+getsum(i)*b[i]<<' ';
        }
        cout<<endl;
    }

    return 0;
}