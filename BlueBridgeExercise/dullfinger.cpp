#include<bits/stdc++.h>
using namespace std;
int pa=0,pb=0;
int out2(string &s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        int k=s[i]-'0';
        ans=ans*2+k;
    }
    // cout<<ans<<endl;
    return ans;
}
int out3(string &s){
    int ans=0;
    for(int i=0;i<s.length();i++){
        int k=s[i]-'0';
        ans=ans*3+k;
    }
    // cout<<ans<<endl;
    return ans;
}
const int maxn=3e3;
int A[maxn],B[maxn];
int main(){
    string s,t;
    cin>>s>>t;
    int ans=0;
    if(s.length()==1){
        cout<<!(s[0]-'0')<<endl;
        return 0;
    }
    if(s[0]=='0'){
        s[0]='1';
        ans=out2(s);
        cout<<ans<<endl;
        return 0;
    }
    bool f=true;
    if(t[0]=='0'){
        t[0]='1';
        ans=out3(t);
        B[pb++]=ans;
        t[0]='2';
        ans=out3(t);
        B[pb++]=ans;
        // return 0;
        f=false;
        ans=0;
    }
    if(ans){
        cout<<ans<<endl;
        return 0;
    }
    for(int i=1;i<s.length();i++){
        s[i]=!(s[i]-'0')+'0';
        A[pa++]=out2(s);
        s[i]=!(s[i]-'0')+'0';
    }
    char c=t[0];
    if(c=='1'){
        t[0]='2';
    }else{
        t[0]='1';
    }
    B[pb++]=out3(t);
    t[0]=c;
    if(f)
    for(int i=1;i<t.length();i++){
        char c=t[i];
        if(t[i]=='0'){
            t[i]='1';
            B[pb++]=out3(t);
            t[i]='2';
            B[pb++]=out3(t);
        }else if(t[i]=='1'){
            t[i]='0';
            B[pb++]=out3(t);
            t[i]='2';
            B[pb++]=out3(t);
        }else if(t[i]=='2'){
            t[i]='0';
            B[pb++]=out3(t);
            t[i]='1';
            B[pb++]=out3(t);
        }
        t[i]=c;
    }
    sort(A,A+pa);
    sort(B,B+pb);
    // for(int i=0;i<pa;i++)cout<<A[i]<<' ';
    // cout<<endl;
    // for(int i=0;i<pb;i++)cout<<B[i]<<' ';
    // cout<<endl;
    // printf("pa=%d,pb=%d\n",pa,pb);
    for(int i=0;i<pa;i++){
        int m=*lower_bound(B,B+pb,A[i]);
        if(m==A[i]){
            cout<<m<<endl;
            return 0;
        }
    }
    return 0;
}