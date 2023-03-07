#include<bits/stdc++.h>
// using namespace std;
typedef int QElemType;
typedef struct Qnode{
    QElemType data;
    struct Qnode *next;
}Qnode,*QueuePtr;
typedef struct{
    QueuePtr rear,front;
}LinkQueue;
bool Enqueue(LinkQueue &Q,QElemType e){
    QueuePtr p=(QueuePtr)malloc(sizeof(Qnode));
    if(!p)exit(0);
    p->data=e;
    p->next=NULL;
    Q.rear->next=p;
    Q.rear=p;
    return true;
}
bool Dequeue(LinkQueue &Q,QElemType &e)
{
    if(Q.front==Q.rear)return false;//队空
    QueuePtr p=(QueuePtr)malloc(sizeof(Qnode));
    p=Q.front->next;
    e=p->data;
    Q.front->next=p->next;
    if(Q.rear==p)Q.rear=Q.front;
    free(p);
    return true;
}
int main(){
    return 0;
}