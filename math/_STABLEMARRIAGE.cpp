#include <bits/stdc++.h>
using namespace std;
const int MAXN=1e3+10;
int pref[MAXN][MAXN],order[MAXN][MAXN],nex[MAXN];
int future_husband[MAXN],future_wife[MAXN];
queue<int> q;

void engage(int man,int woman)
{
    int m=future_husband[woman];
    if(m)
    {
        future_wife[m]=0;
        q.push(m);
    }
    future_wife[man]=woman;
    future_husband[woman]=man;
}

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n; 
        for(int i=1;i<=n;i++)
        {
            int which;
            cin>>which;
            for(int j=1;j<=n;j++)
            {
                int x;
                cin>>x;
                order[which][x]=j;
            }
            future_husband[which]=0;
        }
        for(int i=1;i<=n;i++)
        {
            int which;
            cin>>which;
            for(int j=1;j<=n;j++)
            {
                cin>>pref[which][j];
            }
            nex[which]=1;
            future_wife[which]=0;
            q.push(which);
        }
        while(!q.empty())
        {
            int man=q.front();q.pop();
            int woman=pref[man][nex[man]++];
            if(!future_husband[woman])
            {
                engage(man,woman);
            }
            else if(order[woman][man]<order[woman][future_husband[woman]])
            {
                engage(man,woman);
            }
            else
            {
                q.push(man);
            }
        }
        while(!q.empty()) q.pop();
        for(int i=1;i<=n;i++)
        {
            cout<<i<<" "<<future_wife[i]<<endl;
        }
    }
}