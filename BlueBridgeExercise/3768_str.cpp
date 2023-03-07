#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    cin>>s;
    int sum=0;
    for(int i=0;i<n;i++){
        if(s[i]=='x'){
            int cnt=0;
            while(s[i]=='x'&&i<n){
                cnt++;
                i++;
            }
            if(cnt>=3)sum+=cnt-2;
        }
    }
    cout<<sum<<endl;
    return 0;
}