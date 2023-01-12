#include<bits/stdc++.h>
using namespace std;
int main(){
    int n;
    cin>>n;
    string s;
    while (n--)
    {
        cin>>s;
        bool flag=true;
        if(s[0]==s[s.length()-1]){
            cout<<s[0]<<" "<<s.substr(1,s.length()-2)<<" "<<s[s.length()-1]<<endl;
        }else{
            if(s[0]=='a'){
                for(int i=0;i<s.length()-2;i++){
                    if(s[i]=='b'){
                        cout<<" "<<s.substr(i,s.length()-i-1)<<" b"<<endl;
                        flag=false;
                        break;
                    }
                    cout<<s[i];
                }
                if(flag)
                cout<<" a b"<<endl;
            }else{
                if(count(s.begin(),s.end(),'a')>2){
                    cout<<s.substr(0,s.find('a'))<<" a "<<s.substr(s.find('a')+1)<<endl;
                }else{
                    cout<<"b "<<s.substr(1,s.length()-2)<<" a"<<endl;
                }
            }
        }
    }
    
    return 0;
}