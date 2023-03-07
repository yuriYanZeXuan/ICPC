#include<bits/stdc++.h>
using namespace std;
int n;
const int maxn=6e5;
int A[maxn],H[maxn],vis[maxn];
struct E{
    int data;
    int pos;
};
class cmp
{
    public:
        bool operator()(const E &l,const E &r)const{
            return l.data<r.data;
        }
};

priority_queue<E,vector<E>,cmp> pq;
int main(){
    int T;
    // pq.push(1);
    // pq.push(2);
    // pq.pop();
    // cout<<pq.top()<<endl;
    cin>>T;
    while(T--){
        cin>>n;
        int hero=0;
        while(!pq.empty())pq.pop();
        for(int i=0;i<n;i++){
            cin>>A[i];
            // vis[i]=0;
            if(!A[i]){
                H[hero++]=i;
            }
        }
        long long sum=0;
        for(int i=0;i<H[0];i++){
            pq.push({A[i],i});
        }
        if(!pq.empty()&&hero){
            E e=pq.top();
            sum+=e.data;
            pq.pop();
        }
        for(int i=1;i<hero;i++){
            for(int j=H[i-1]+1;j<H[i];j++){
                pq.push({A[j],j});
            }
            if(!pq.empty()){
                E e=pq.top();
                pq.pop();
                sum+=e.data;
            }
        }
        cout<<sum<<endl;
    }
    return 0;
}