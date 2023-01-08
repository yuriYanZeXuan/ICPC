#include <cstdint>
#include <iostream>
#include <fstream>
#include<string.h>
#define MAXLEN 100
#ifndef LENGTH
#define LENGTH 3
#endif
using namespace std;
int16_t lab1(int16_t a, int16_t b) {
    // count how many 1 in a,in last b bits
    int k=(1<<b)-1;
    a=a&k;
    int value=0;
    while(a){
        a=a&(a-1);
        value++;
    }
    return value;
}
int mem[10000];
int mod(int a,int b){
    while(a>=b)a-=b;
    return a;
}
int16_t lab2(int16_t p, int16_t q, int16_t n) {
    if(n==1||n==0)return 1;
    if(mem[n])return mem[n];
    //p=2^k

    return mem[n]=((lab2(p,q,n-2)&(p-1))+mod(lab2(p,q,n-1),q));
}
int16_t lab3(int16_t n, char s[]) {

    char c=s[0];
    int value=1,cnt=1;
    for(int i=1;i<n;i++){
        if(s[i]!=c){
            c=s[i];
            cnt=1;
        }else{
            cnt++;
        }
        value=value<cnt?cnt:value;
    }
    return value;
}
void lab4(int16_t score[], int16_t *a, int16_t *b) {

    int t;
    for(int i=0;i<16;i++){
        for(int j=i;j<16;j++){
            if(score[i]>score[j]){
                t=score[i];
                score[i]=score[j];
                score[j]=t;
            }
        }
    }
    *a=*b=0;
    int j=1;
    for(int i=15;i>=0;i--,j++)
    {
        if(score[i]>=85&&j<=4)(*a)++;
        else if(score[i]>=75&&j<=8)(*b)++;
    }
    return;
}
int main() {
    std::fstream file;
    file.open("test.txt", std::ios::in);
    // lab1
    int16_t a = 0, b = 0;
    for (int i = 0; i < LENGTH; i++) {
        file>>a>>b;
        cout<<lab1(a, b)<<endl;
    }
    // lab2
    // cout<<"test"<<lab2(3,4,3)<<endl;
    // exit(0);
    int16_t p = 0, q = 0, n = 0;
    for (int i = 0; i < LENGTH; i++) {
        file>>p>>q>>n;
        memset(mem,0,sizeof(mem));
        cout<<lab2(p, q, n)<<endl;
    }
    // lab3
    char s[MAXLEN];
    for (int i = 0; i < LENGTH; i++) {
        file>>n>>s;
        cout<<lab3(n, s)<<endl;
    }
    // lab4
    int16_t score[16];
    for (int i = 0; i < LENGTH; i++) {
        for (int j = 0; j < 16; j++) {
            file>>score[j];
        }
    
        lab4(score, &a, &b);
        for (int j = 0; j < 16; j++) {
            cout<<score[j]<<" ";
        }
        cout<<endl<<a<<" "<<b<<endl;
    }
    file.close();
    return 0;
}