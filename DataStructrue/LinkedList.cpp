#include<iostream>
using namespace std;
struct Node{
    Node* next;
    int data;
};
Node *first;
void init(){
    first=(Node*)malloc(sizeof(Node));
    if(!first){
        exit(0);
    }
    first->next=NULL;
    cout<<"initiated"<<endl;
}
void insert(int pos,int data){
    Node *q=first;
    for(;pos>1;pos--){
        if(!q->next)exit(0);
        q=q->next;
    }
    Node *p=(Node*)malloc(sizeof(Node));
    p->next=q->next;
    q->next=p;
    p->data=data;
}
void reverse(){
    Node* last=first,*now=first->next,*nex=now->next;
    while(nex){
        now->next=last;
        last=now;
        now=nex;
        nex=nex->next;
    }
    now->next=last;
    cout<<"reverse complete"<<endl;
}
void traverse(){
    Node* p=first;
    while(p->next){
        p=p->next;
        cout<<p->data<<' ';
    }
    cout<<endl;
}
int main(){
    init();
    for(int i=1;i<=10;i++){
        insert(i,i);
        cout<<"inserted"<<i<<endl;
    }
    traverse();
    reverse();
    return 0;
}