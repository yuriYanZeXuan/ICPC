// #include<stdio.h>
// #include<stdlib.h>
// #include<string.h>
#include<bits/stdc++.h>
using namespace std;
const int maxn =10;
const int inf=0x3f3f3f3f;
typedef struct
{
    int Matrix[maxn][maxn];//带边权
    char vertex[maxn];
    int VerNum,EdgeNum;
}Graph;
int Locate(char c,Graph G){
    //定位G中顶点c的下标，不存在就返回-1
    for(int i=0;i<maxn;i++){
        if(G.vertex[i]==c)return i;//找到下标i符合要求
    }
    return -1;//查找失败
}
void delVertex(Graph *G,char c){
    int pos=Locate(c,*G);
    if(pos==-1){
        printf("顶点不存在！\n");
        return;
    }else{
        G->vertex[pos]=-1;
        for(int i=0;i<maxn;i++){
            if(G->Matrix[pos][i]!=inf){
                G->Matrix[pos][i]=inf;
                G->EdgeNum--;
            }
            if(G->Matrix[i][pos]!=inf){
                G->Matrix[i][pos]=inf;
                G->EdgeNum--;
            }
        }
        G->VerNum--;
    }
}
void addVertex(Graph *G,char c){
    int pos=Locate(c,*G);
    if(pos!=-1){
        printf("顶点已存在！\n");
        return;
    }
    for(int i=0;i<maxn;i++){
        if(G->vertex[i]==-1){
            G->vertex[i]=c;
            G->VerNum++;
            return;
        }
    }
    printf("空间已满！\n");
    return;
}
void addEdge(Graph *G,char u,char v,int w){
    int pos1=Locate(u,*G);
    int pos2=Locate(v,*G);
    //定位两个顶点的下标
    if(pos1==-1||pos2==-1){
        printf("某一顶点不存在！\n");
        //某一顶点不存在
        return;
    }
    if(G->Matrix[pos1][pos2]!=inf){
        printf("边已存在！\n");
        //边已存在
        return;
    }else{
        //新增边
        G->Matrix[pos1][pos2]=w;
        G->EdgeNum++;
        return;
    }

}
void delEdge(Graph *G,char u,char v){
    int pos1=Locate(u,*G);
    int pos2=Locate(v,*G);
    if(pos1==-1||pos2==-1||G->Matrix[pos1][pos2]==inf){
        //顶点不存在或者边不存在
        printf("待删除边不合法！\n");
        return;
    }else{
        G->Matrix[pos1][pos2]=inf;
        G->EdgeNum--;
        return;
    }
}
void updateVertex(Graph *G,char c,char nc){
    int pos=Locate(c,*G);
    if(pos==-1){
        printf("顶点不存在\n");
        return;
    }else{
        G->vertex[pos]=nc;
        printf("顶点值已更新\n");
        return;
    }
}
void updateEdge(Graph *G,char u,char v,int nw){
    int pos1=Locate(u,*G);
    int pos2=Locate(v,*G);
    if(pos1==-1||pos2==-1||G->Matrix[pos1][pos2]==inf)
    {
        printf("边不存在，无法更新！\n");
        return;
    }else{
        G->Matrix[pos1][pos2]=nw;
        printf("更新成功！\n");
        return;
    }
}
void print(Graph *G){
    printf("图的顶点数：%d,边数%d\n",G->VerNum,G->EdgeNum);
    for(int i=0;i<maxn;i++){
        if(G->vertex[i]==-1)continue;
        printf("%c ",G->vertex[i]);
    }
    printf("\n");
    for(int i=0;i<maxn;i++){
        if(G->vertex[i]==-1)continue;
        for(int j=0;j<maxn;j++)
        {
            if(G->vertex[j]==-1)continue;
            printf("%5d ",G->Matrix[i][j]==inf?0:G->Matrix[i][j]);
        }
        printf("\n");
    }
    printf("打印结束\n");
}
char buf[100];
Graph create(){
    int edgenum,vertexnum;
    printf("请输入节点数\n");
    scanf("%d",&vertexnum);
    printf("请输入边数\n");
    scanf("%d",&edgenum);
    Graph G;
    char u,v;
    int w;
    G.EdgeNum=edgenum;
    memset(G.Matrix,63,sizeof(G.Matrix));
    memset(G.vertex,-1,sizeof(G.vertex));
    for(int i=0;i<edgenum;i++){
        printf("边%d:\n",i);
        cin>>u>>v>>w;
        int pos1=Locate(u,G),pos2=Locate(v,G);
        if(pos1!=-1&&pos2!=-1&&G.Matrix[pos1][pos2]!=inf){
            printf("当前边已存在！\n");
            continue;
        }else{
            if(pos1==-1){
                pos1=G.VerNum++;
                G.vertex[pos1]=u;
            }
            if(pos2==-1){
                pos2=G.VerNum++;
                G.vertex[pos2]=v;
            }
            G.Matrix[pos1][pos2]=w;
        }
    }
    return G;
}
Graph Floyd(Graph *g){
    Graph res=*g;
    for(int i=0;i<maxn;i++){
        if(res.vertex[i]==-1)continue;
        for(int j=0;j<maxn;j++){
            if(res.vertex[j]==-1)continue;
            for(int k=0;k<maxn;k++){
                if(res.vertex[k]==-1)continue;
                else if(1ll*res.Matrix[i][j]+res.Matrix[j][k]<res.Matrix[i][k]){
                    res.Matrix[i][k]=res.Matrix[i][j]+res.Matrix[j][k];
                }
            }
        }
    }
    return res;
}
int main(){
    Graph g=create();
    print(&g);
    // addVertex(&g,'a');
    // addEdge(&g,'1','a',33);
    // updateEdge(&g,'1','2',6);
    // updateVertex(&g,'1','b');
    // print(&g);
    // delVertex(&g,'b');
    // print(&g);
    // delEdge(&g,'2','3');
    // print(&g);
    Graph g2=Floyd(&g);
    print(&g2);
    return 0;
}