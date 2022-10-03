#include<bits/stdc++.h>
using namespace std;
const int maxn =1000000;
int nex[maxn];
int nextval[maxn];
void get_prefix(char *s,int l){
    nex[0]=0;
    nextval[0]=0;
    for(int i=1;i<=l;i++){
        int j=nex[i-1];
        while(j&&s[j-1]!=s[i-1]){
            j=nex[j-1];
            // cout<<"j="<<j<<endl;
        }
        nex[i]=j+1;
        if(s[i]==s[nex[i]-1]){
            nextval[i]=nextval[i-1];
        }else{
            nextval[i]=nex[i];
        }
    }//abaabcac
}
int main(){
    char s[maxn],t[maxn];
    scanf("%s",s);
    // scanf("%s",t);
    // kmp(s,t);
    int l=strlen(s);
    get_prefix(s,l);
    printf("next:\n");
    for(int i=0;i<l;i++){
        cout<<nex[i]<<' ';
    }
    cout<<endl;
    printf("nextval:\n");
    for(int i=0;i<l;i++){
        cout<<nextval[i]<<' ';
    }
    return 0;
}