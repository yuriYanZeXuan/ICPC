#include<bits/stdc++.h>
using namespace std;
struct Node{
    Node *lch,*rch;
    int val;
    int id;
}*rt;
string path;
int minval=0x3f3f3f3f,maxval=-1;
void insert(int val,Node *T,int id);
void build(){
    printf("请输入二叉树节点个数\n");
    int n;
    scanf("%d",&n);
    printf("请输入%d号节点的值\n",1);
    int val;
    scanf("%d",&val);
    rt=(Node*)malloc(sizeof(Node));
    rt->val=val;
    rt->id=1;
    rt->lch=rt->rch=NULL;
    for(int i=2;i<=n;i++){
        printf("请输入%d号节点的值\n",i);
        scanf("%d",&val);
        insert(val,rt,i);
    }

}
//左大右小
void insert(int val,Node *T,int id){
    if(val<T->val){
        if(!T->lch){
            T->lch=(Node*)malloc(sizeof(Node));
            T->lch->val=val;
            T->lch->id=id;
            T->lch->lch=T->lch->rch=NULL;

        }else{
            insert(val,T->lch,id);
        }
    }else{
        if(!T->rch){
            T->rch=(Node*)malloc(sizeof(Node));
            T->rch->val=val;
            T->rch->id=id;
            T->rch->lch=T->rch->rch=NULL;
        }else{
            insert(val,T->rch,id);
        }
    }
}
void del(Node *T){
    if(T->lch)
        del(T->lch);
    if(T->rch)
        del(T->rch);
    cout<<"删除"<<T->val<<"节点"<<endl;
    free(T);
}
int LCA(Node* current,int id1,int id2){
    int flag=-1;
    if(current==NULL){//空节点，返回-1
        return -1;
    }
    else if(current->id==id1||current->id==id2){
        return current->id;//查找到一个，返回当前节点id
    }
    int t1=-1,t2=-1;
    t1=LCA(current->lch,id1,id2);
    t2=LCA(current->rch,id1,id2);
    if(t1!=-1&&t2!=-1){
        return current->id;//左右都能找到，当前节点即为LCA
    }else if(t1!=-1){
        return t1;//返回子树中找到的LCA或者节点
    }else if(t2!=-1){
        return t2;
    }else{
        return -1;//默认失败
    }
}

int dfs(Node* T,int val){
    if(T==NULL)return -1;
    if(T->val==val){
        return 1;
    }
    int tmp=-1;
    tmp=dfs(T->lch,val);
    if(tmp==1){
        path+='l';
        return 1;
    }else{
        tmp=dfs(T->rch,val);
        if(tmp==1){
            path+='r';
            return 1;
        }
    }
    return -1;
}
void preTraverse(Node *T){
    if(!T)return;
    printf("%d号节点,val=%d\n",T->id,T->val);
    preTraverse(T->lch);
    preTraverse(T->rch);
}
void diff(Node* T){
    
    if(T==NULL){
        return;
    }
    else
    {
        minval=min(minval,T->val);
        maxval=max(maxval,T->val);
    }
    diff(T->lch);
    diff(T->rch);
}
int main(){
    build();
    preTraverse(rt);
    printf("请输入要找的val\n");
    int v;
    cin>>v;
    dfs(rt,v);
    cout<<path<<endl;
    diff(rt);
    cout<<"max diff="<<maxval-minval<<endl;
    cout<<"请输入要找公共祖先的两个id"<<endl;
    int id1,id2;
    cin>>id1>>id2;
    cout<<LCA(rt,id1,id2)<<endl;
    // cout<<"hello "<<endl;
    
    return 0;
}