#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10;
string s;
int Len[maxn];
vector<int> manacher(int n){
    vector<int> d1(n);
    for(int i=0,l=0,r=-1;i<n;i++){
        int k=(i>r)?1:min(d1[l+r-i],r-i+1);
        while(0<=i-k&&i+k<n&&s[i-k]==s[i+k]){
            k++;//在字符串边界内拓展回文串
        }
        d1[i]=k--;//k:原始回文串右长,统一后即为总长
        if(i+k>r){
            //维护已找到的最靠有的子回文串的边界
            l=i-k;
            r=i+k;
        }
    }
    return d1;
}
int main()
{
    string cs;
    while(cin>>cs){
        s.clear();
        for(int i=0;i<cs.length();i++){
            s.push_back('#');
            s.push_back(cs[i]);
        }
        s.push_back('#');//插入分隔符后总长一定为奇数
        vector<int> d= manacher(s.length());
        cout<<cs;
        for(int i=0;i<d.size();i++){
            Len[i]=d[i];
            if(Len[i]+i==d.size()){
                // int begin=(i-Len[i])%2?(i-Len[i])-1:(i-Len[i]);
                int begin=i-Len[i];
                // cout<<"begin="<<begin<<"i="<<i<<endl;
                for(int j=begin;j>=0;j--){
                    if(s[j]!='#')
                        cout<<s[j];
                }
                cout<<endl;
                break;
            }
        }
        // for(auto v:d){
        //     cout<<v<<" ";
        // }
    }
    return 0;
}