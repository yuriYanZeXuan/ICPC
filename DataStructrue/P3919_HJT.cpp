#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+10;
struct node{
    int ch[2];
    int val;
}tr[maxn*23];
#define lc(x) tr[x].ch[0]
#define rc(x) tr[x].ch[1]
int id=0;
int root[maxn];
int A[maxn];
void build(int &x,int l,int r){
    x=++id;
    int m=l+r>>1;
    if(l==r){
        tr[x].val=A[l];
        return;
    }
    build(lc(x),l,m);
    build(rc(x),m+1,r);
}
void insert(int x,int &y,int l,int r,int pos,int nv){
    y=++id;
    tr[y]=tr[x];
    if(l==r){
            tr[y].val=nv;
        return;
    }
    int m=l+r>>1;
    if(pos<=m){
        insert(lc(x),lc(y),l,m,pos,nv);
    }else{
        insert(rc(x),rc(y),m+1,r,pos,nv);
    }
}

int query(int pos,int l,int r,int t){
    //t是历史节点
    if(l==r){
        return tr[t].val;
    }
    int m=l+r>>1;
    if(pos<=m){
        return query(pos,l,m,lc(t));
    }else{
        return query(pos,m+1,r,rc(t));
    }
}
int main(){
    int N,M;
    cin.tie(0);
    ios::sync_with_stdio(0);
    cin>>N>>M;
    for(int i=1;i<=N;i++){
        cin>>A[i];
    }
    int vi,mode,loc,value;
    build(root[0],1,N);
    for(int i=1;i<=M;i++){
        cin>>vi>>mode;
        if(mode==1){//vi上将a[loc_i]->value_i
            cin>>loc>>value;
            insert(root[vi],root[i],1,N,loc,value);
        }else{
            cin>>loc;
            insert(root[vi],root[i],0,0,0,0);
            cout<<query(loc,1,N,root[vi])<<endl;
        }
    }   

    return 0;
}