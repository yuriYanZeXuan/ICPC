#include<bits/stdc++.h>
using namespace std;
const int maxn=500;
const int inf=0x3f3f3f3f;
typedef long long ll;
int n;
int A[maxn];
int score[maxn][maxn];//score[i][j]表示[i,j]区间的最大得分
int _score[maxn][maxn];//类比最小得分
ll sum[maxn];
int getsum(int l,int r){
    if(l==0)return sum[r];
    return (int)(sum[r]-sum[l-1]);
}
int main()
{
    cin>>n;//有n堆石子
    for(int i=0;i<n;i++)
    {
        cin>>A[i];
        
    }
    memcpy(A+n,A,n*sizeof(int));
    for(int i=0;i<2*n;i++){
        if(i)
        sum[i]=A[i]+sum[i-1];
        else
        sum[i]=A[i];
    }
    int maxs=-1;
    ll mins=inf;
    for(int len=1;len<n;len++){
        //每次dp len+1长度的得分
        for(int i=0;i<2*n-len;i++){
            //起点为i
            _score[i][i+len]=_score[i][i]+_score[i+1][i+len]+getsum(i,i+len);
            for(int j=i;j<i+len;j++){
                score[i][i+len]=max(score[i][i+len],score[i][j]+score[j+1][i+len]+getsum(i,i+len));
                _score[i][i+len]=min(_score[i][i+len],_score[i][j]+_score[j+1][i+len]+getsum(i,i+len));
            }
            maxs=max(maxs,score[i][i+len]);
            if(len==n-1)
            mins=min(mins,(ll)_score[i][i+len]);
        }
    }
    cout<<mins<<endl<<maxs<<endl;
    return 0;
}