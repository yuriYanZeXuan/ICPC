#include<bits/stdc++.h>
using namespace std;
const int maxn=2e2;
struct Tree{
    Tree *lchild,*rchild;
    int data;
};
int A[maxn],B[maxn];//A是后序遍历，B是中序遍历
Tree* build(int hl,int hr,int zl,int zr){
    if(hl>hr||zl>zr)return NULL;
    Tree *rt=(Tree*)malloc(sizeof(Tree));
    rt->lchild=rt->rchild=NULL;
    rt->data=A[hr];
    int mid,cnt=0;
    for(int i=zl;i<=zr;i++)
    {
        if(B[i]==rt->data){
            mid=i;
            break;
        }
        cnt++;
    }
    rt->lchild=build(hl,hl+cnt-1,zl,mid-1);
    rt->rchild=build(hl+cnt,hr-1,mid+1,zr);
    return rt;
}
vector<int> ans;
void bfs(Tree* rt){
    queue<Tree*> q;
    q.push(rt);
    // ans.push_back(rt->data);
    while(!q.empty()){
        Tree *r=q.front();
        q.pop();
        ans.push_back(r->data);
        if(r->lchild)
            q.push(r->lchild);
        if(r->rchild)
            q.push(r->rchild);
    }
}
int main()
{
    int N;
    cin>>N;
    int t;
    for(int i=0;i<N;i++){
        cin>>A[i];
    }
    for(int i=0;i<N;i++){
        cin>>B[i];
    }
    Tree* rt=build(0,N-1,0,N-1);
    bfs(rt);
    for(int i=0;i<ans.size();i++){
        if(i)cout<<' ';
        cout<<ans[i];
    }
    return 0;
}