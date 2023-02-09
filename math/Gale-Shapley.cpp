#include<bits/stdc++.h>
using namespace std;
const int maxn=505;
struct Person
{
    vector<int> opp;
    pair<bool,int> status;
}man[maxn],woman[maxn];

int ready[maxn][maxn];
//ready[i][0]表示i号女生的备胎数,ready[i][1~n]表示有哪些备胎
int listable[maxn][maxn];
//listable[i][j]表示i男生在j女生中的优先级(1表示最优先)
int main(){
    int t,n,p,k;
    cin>>t;
    while(t--){
        cin>>n;
        memset(man,0,sizeof(man));
        memset(woman,0,sizeof(woman));
        memset(ready,0,sizeof(ready));
        for(int i=1;i<=n;i++){
            cin>>p;
            for(int j=0;j<n;j++){
                cin>>k;
                // woman[p].opp.push_back(k);
                listable[k][p]=j+1;
            }
        }
        for(int i=1;i<=n;i++){
            cin>>p;
            for(int j=0;j<n;j++){
                cin>>k;
                man[p].opp.push_back(k);
            }
        }
        int singledog=n;
        while (singledog>0)
        {
            //男生发出表白
            for(int i=1;i<=n;i++){
                if(!man[i].status.first){
                    int &num=ready[man[i].opp[0]][0];
                    ready[man[i].opp[0]][++num]=i;
                }   
            }
            //女生处理备胎
            for(int i=1;i<=n;i++){
                int num=ready[i][0];
                int bestboy=1000,bestval=1000;
                for(int l=1;l<=num;l++){
                    if(listable[ready[i][l]][i]<bestval){
                        bestval=listable[ready[i][l]][i];
                        bestboy=ready[i][l];
                    }
                }
                if(bestval>=501)continue;
                if(woman[i].status.first){
                    if(listable[woman[i].status.second][i]>bestval){
                        //判断踹掉当前备胎
                        man[woman[i].status.second].status=make_pair(false,0);
                        man[bestboy].status=make_pair(true,i);
                        woman[i].status.second=bestboy;
                    }
                }else{
                    woman[i].status=make_pair(true,bestboy);
                    man[bestboy].status=make_pair(true,i);
                    singledog--;
                }
                //被拒绝的男生不再向该女生提出表白
                for(int k=1;k<=ready[i][0];k++){
                    man[ready[i][k]].opp.erase(man[ready[i][k]].opp.begin());
                }
            }
            memset(ready,0,sizeof(ready));
        }
        // cout<<"singledog="<<singledog<<endl;
        for(int i=1;i<=n;i++){
            cout<<i<<" "<<man[i].status.second<<endl;
        }
    }
    
    return 0;
}