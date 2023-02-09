#include<bits/stdc++.h>
using namespace std;
int n,m;
double f[201];
//对于概率递推的有向图，如果无环可以用拓扑排序DP，
//如果有环可以在各连通图内分别建立方程，用高斯消元法求解，无需考虑极限
struct equation{
    double a[201],p;
    equation operator*(double b){
        equation x;
        for(int i=1;i<=n;i++){
            x.a[i]=x.a[i]*b;
        }
        x.p=p*b;
        return x;
    }
    void operator-= (equation b){
        int i;
        for(i=1;i<=n;i++){
            a[i]-=b.a[i];
        }
        p-=b.p;
    }
}x[201];
int main(){
    for(int i=1;i<=10;i++){
        cout<<"equation "<<i;
        for(int j=0;j<10;j++){
            cout<<x[i].a[j]<<" ";
        }
        cout<<"p="<<x[i].p;
        cout<<endl;
    }
    int i,j,k;
    cin>>n>>m;
    //以下为高斯消元法
    for(i=1;i<=n;i++){
        cin>>x[i].p;
        x[i].a[i]=1;
    }
    for(i=1;i<=m;i++){
        cin>>j>>k;
        cin>>x[j].a[k];
        x[j].a[k]=-x[j].a[k];//移常数项
    }
    for(i=j=1;i<n;j=++i){
        if(x[i].a[i]==0){
            for(j=i+1;j<=n&&fabs(x[j].a[i])<1e-10;j++);
            if(j<=n)swap(x[i],x[j]);//移动首项不为零的方程到上方
        }
        for(j++;j<=n;j++){
            if(fabs(x[j].a[i])>1e-10)
                x[j]-=x[i]*(x[j].a[i]/x[i].a[i]);//消前面的元
        }
        for(i=n;i>=1;i--){
            for(j=i+1;j<=n;j++)
                if(fabs(x[i].a[j])>1e-10)
                    x[i].p-=x[i].a[j]*f[j];//消后面的元
            f[i]=x[i].p/x[i].a[i];
        }
        for(i=1;i<=n;i++)
            printf(".6lf\n",f[i]);
        return 0;
    }
    return 0;
}