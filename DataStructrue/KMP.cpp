#include<iostream>
using namespace std;
const int maxn=2e4;
char s[maxn],t[maxn];
int nextval[maxn];
int KMP(char* s,char* t,int len){//1<=pos<=len
    int i=1,j=1;
    while(i<=len&&j<=len){
        if(j==0||s[i]==t[j]){++i,++j;}
        else j=nextval[j];
    }
    if(j>len)return i-len;
    else return -1;
}
void getnextval(char *s,int len){
    int i=1,j=0;
    nextval[1]=0;
    while(i<len){
        if(j==0||s[i]==s[j]){
            ++i,++j;
            if(s[i]!=s[j])nextval[i]=j;
            else nextval[i]=nextval[j];
        }else{
            j=nextval[j];
        }
    }
}   
int main(){
    return 0;
}