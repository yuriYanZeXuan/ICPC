#include<bits/stdc++.h>
using namespace std; 
const int maxn=2e6+10;
int prefix[maxn];//prefix[i]表示s[0:i]的相等的真前/后缀长度
int main(){
    int N,cnt=1;
    string s;
    while(cin>>N>>s&&N){
        // prefix[0]=0;
        // memset(prefix,0,sizeof(prefix));
        printf("Test case #%d\n",cnt++);
        for(int i=1;i<N;i++){
            int j=prefix[i-1];
            while(j>0&&s[i]!=s[j])j=prefix[j-1];
            if(s[i]==s[j])j++;
            prefix[i]=j;
            if((i+1)%(i+1-prefix[i])==0&&(i+1)!=(i+1-prefix[i])){
                printf("%d %d\n",i+1,(i+1)/(i+1-prefix[i]));
            }
        }
        printf("\n");
    }
    return 0;
}