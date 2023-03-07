#include<bits/stdc++.h>
using namespace std;
const int maxn=2e3;
struct Triple{
    int row,col;
    int val;
};
struct TSMatrix{
    Triple data[maxn];
    int mu,nu,tu;//矩阵的行数，列数，非零元个数   
};
void Trans(TSMatrix t,TSMatrix* nt){
    
    int colcnt[maxn],cpot[maxn];
    memset(colcnt,0,sizeof(colcnt));
    memset(cpot,0,sizeof(cpot));
    for(int i=0;i<t.tu;i++){
        colcnt[t.data[i].col]++;
    }
    for(int i=1;i<=t.tu;i++){
        // if(i)
        cpot[i]=cpot[i-1]+colcnt[i-1];
    }
    nt->mu=t.nu;
    nt->nu=t.mu;
    nt->tu=t.tu;
    for(int i=0;i<t.tu;i++){
        
        swap(t.data[i].col,t.data[i].row);
        nt->data[cpot[t.data[i].col]++]=t.data[i];
    }
    cout<<"trans completed"<<endl;
}
void traverse(TSMatrix t){
    for(int i=1;i<=t.mu;i++){
        for(int j=1;j<=t.nu;j++){
            bool f=false;
            for(int k=0;k<t.tu;k++){
                // cout<<t.data[i].col<<" "<<t.data[i].row<<" "<<t.data[i].val<<endl;
                if(t.data[k].row==i&&t.data[k].col==j){
                    f=true;
                    printf("%5d",t.data[k].val);
                }
            }
            if(!f) printf("%5d",0);
        }
        printf("\n");
    }
    cout<<"traverse completed"<<endl;
}
int main(){
    TSMatrix t,t2;
    t.mu=t.nu=10;
    t.tu=10;
    for(int i=0;i<10;i++){
        cin>>t.data[i].col>>t.data[i].row>>t.data[i].val;
    }
    traverse(t);
    Trans(t,&t2);
    traverse(t2);
    return 0;
}