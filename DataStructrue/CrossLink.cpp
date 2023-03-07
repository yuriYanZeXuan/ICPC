#include<bits/stdc++.h>
using namespace std;
typedef struct Clnode
{
    int row,col;
    int value;
    struct CLnode *down,*right;
}OLNode;/*非零元素节点*/
typedef struct Clnode{
    int rn,cn,tn;
    OLNode *rhead,*chead;
    /*用两个一维数组分别存储行链表的头指针和列链表的头指针*/
}CrossList;
int main(){
    return 0;
}