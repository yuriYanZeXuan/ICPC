#include<bits/stdc++.h>
using namespace std;
#define MAXVERTEX 100
#define MAXEDGE 20000
#define _NETWORK_CPP_ 1
int Vvis[MAXVERTEX];
int Evis[MAXEDGE];
//顶点结构体
typedef struct Vertex {
	int id;//顶点编号
	int w;//顶点权值
	int degree;//顶点的度
	long edges[MAXVERTEX];//边的编号
};

//边结构体
typedef struct Edge {
	long id;//边的编号
	int h;//边头顶点编号
	int t;//边尾顶点编号
	int w;//权值
};

//图结构体
typedef struct Graph {
	Vertex v[MAXVERTEX];//顶点数组
	Edge e[MAXEDGE];//边数组
	bool dirctional;//t:有向图，f:无向图
	bool weighted;//t:带权图，f:等权图
	unsigned nv;//顶点数
	unsigned ne;//边数
};

//生成一个随机图，包括n个顶点，每个顶点和其它顶点连边的概率为p
int randgengraph(int n, float p, bool directional, bool weighted, const char* filename, int seed) {
	srand(seed);
	char* content = (char*)malloc(5000000);
	if (!content) {
		printf("分配存储空间失败！\n");
		exit(0);
	}
	FILE* fp = fopen(filename, "wb");
	if (!fp) {
		printf("生成图文件%s时失败！\n",filename);
		exit(0);
	}
	long offset = 0;//content当前的写入位置
	int ne = 0;//生成边数
	for (int i = 0; i < n; i++)
		offset += sprintf(content + offset, "%3d %5d\n", i, rand() % 100);//写入顶点的编号和顶点随机权值
	int pn = (int)(10000 * p);
	if (directional) {//有向图
		for(int i = 0; i < n; i++)
			for(int j = 0; j < n; j++)
				if (i != j && rand() % 10000 < pn) {
					offset += sprintf(content + offset, "%3d %3d %4d\n", i, j, weighted ? rand() % 100 : 1);
					ne++;
				}
	}
	else {//无向图
		for(int i = 0; i < n; i++)
			for(int j = i; j < n; j++)
				if (i != j && rand() % 10000 < pn) {
					offset += sprintf(content + offset, "%3d %3d %4d\n", i, j, weighted ? rand() % 100 : 1);
					ne++;
				}
	}
	char ch[40];
	int sz = sprintf(ch, "%d %7d %5s %5s\n", n, ne, weighted ? "true" : "flase", directional ? "true" : "flase");
	fwrite(&ch, sz, 1, fp);//写入图的顶点数和边数
	fwrite(content, offset, 1, fp);//写入图的顶点和边的信息
	fclose(fp);
	free(content);
}

//从文件中读入图，在内存中生成图的表示
void initgraph(Graph* g, const char* gfile) {
	FILE* fp = fopen(gfile, "r");
	if (!fp) {
		printf("读取图数据文件出错！\n");
		exit(0);
	}
	char bv[10];
	//读取图的基本信息
	fscanf(fp, "%u%u%s", &(g->nv), &(g->ne), bv);
	//printf("%d %d %s", g->ne, g->nv, bv);
	g->weighted = strcmp(bv, "true") == 0 ? true : false;
	fscanf(fp, "%s", bv);
	g->dirctional = strcmp(bv, "true") == 0 ? true : false;
	//读取顶点信息
	for (int i = 0; i < g->nv; i++) {
		fscanf(fp, "%d%d", &(g->v[i].id), &(g->v[i].w));
		g->v[i].degree = 0;
		//printf("顶点%d-权%d\n", g->v[i].id, g->v[i].w);
	}
	//读取边信息
	for (unsigned long i = 0; i < g->ne; i++) {
		fscanf(fp, "%u%u%d", &(g->e[i].h), &(g->e[i].t), &(g->e[i].w));
		//printf("边:%u-%u=>%d\n", g->e[i].h, g->e[i].t, g->e[i].w);
		g->e[i].id = i;
		unsigned h, t;
		h = g->e[i].h;
		t = g->e[i].t;
		g->v[h].edges[g->v[h].degree++] = i;
		if(g->dirctional==false)
			g->v[t].edges[g->v[t].degree++] = i;
	}
	fclose(fp);
}
int cnt=0;
inline long getEdgeIdx(Graph* g, long id);
//打印邻接表的信息
void printgraph(Graph* g) {
	printf("图的基本信息:顶点数(%u)-边数(%lu)-%s-%s\n", g->nv, g->ne, g->weighted ? "加权图" : "等权图", g->dirctional ? "有向图" : "无向图");
    
	for (int i = 0; i < g->nv; i++) {
		printf("ID(%u)-度(%d)-权(%d)-边表 t(eid|w):%u", g->v[i].id, g->v[i].degree, g->v[i].w, g->v[i].id);
        if(!cnt)
        Vvis[g->v[i].id]=1;
		for (int j = 0; j < g->v[i].degree; j++) {
            if(!cnt)
            Evis[g->v[i].edges[j]]=1;
			unsigned long e = getEdgeIdx(g, g->v[i].edges[j]);
			if (g->v[i].id == g->e[e].h)
				printf("->%u(%d, %d)", g->e[e].t, g->e[e].id, g->e[e].w);
			else 
				printf("->%u(%d, %d)", g->e[e].h, g->e[e].id, g->e[e].w);
		}
		printf("\n");
	}
    cnt++;
}

//查找给定编号的顶点，返回其顶点数组下标
inline int getVexIdx(Graph* g, int id) {
	for (int i = 0; i < g->nv; i++)
		if (g->v[i].id == id)
			return i;
	printf("input wrong vertex id in getVexIdx()!\n");
	return -1;
}

//查找给定编号的顶点，返回其权值
inline int getVexW(Graph* g, int id) {
	for (int i = 0; i < g->nv; i++)
		if (g->v[i].id == id)
			return g->v[i].w;
	printf("input wrong vertex id in getVexW()!\n");
	exit(0);
}

//查找给定编号的顶点，返回其度
inline int getVexDegree(Graph* g, int id) {
	for (int i = 0; i < g->nv; i++)
		if (g->v[i].id == id)
			return g->v[i].degree;
	printf("input wrong vertex id in getVexDegree()!\n");
	exit(0);
}

//查找给定编号的顶点,返回其所有边
inline long* getEdgesByNode(Graph* g, int id, int* ne) {
	for (int i = 0; i < g->nv; i++)
		if (g->v[i].id == id) {
			*ne = g->v[i].degree;
			return g->v[i].edges;
		}
	printf("input wrong vertex id in getEdgesByNode()!\n");
	exit(0);
}

//查找给定编号的边，返回其边数组下标
inline long getEdgeIdx(Graph* g, long id) {
	for (long i = 0; i < g->ne; i++)
		if (g->e[i].id == id)
			return i;
	printf("input wrong edge id in getEdgeIdx()!\n");
	// exit(0);
	return -1;
}

//查找给定编号的边，返回其权值
inline int getEdgeW(Graph* g, long id) {
	for (long i = 0; i < g->ne; i++)
		if (g->e[i].id == id)
			return g->e[i].w;
	printf("input wrong edge id in getEdgeW()!\n");
	exit(0);
}

//查找给定编号的边，返回其两个顶点
inline void getVexByEdge(Graph* g, long id, int* h, int* t) {
	long i;
	for (i = 0; i < g->ne; i++)
		if (g->e[i].id == id) {
			*h = g->e[i].h;
			*t = g->e[i].t;
			return;
		}	
	printf("input wrong edge id in getVexByEdge()!\n");
	exit(0);
}

//通过权值查找顶点编号
inline int locateVex(Graph* g, int w) {
	for (int i = 0; i < g->nv; i++)
		if (g->v[i].w == w)
			return g->v[i].id;
	return -1;
}

//通过权值查找边编号
inline int locateEdge(Graph* g, int w) {
	for (int i = 0; i < g->ne; i++)
		if (g->e[i].w == w)
			return g->e[i].id;
	return -1;
}

//设置顶点权值
inline void setVexW(Graph* g, int id, int w) {
	for (int i = 0; i < g->nv; i++)
		if (g->v[i].id == id) {
			g->v[i].w = w;
			return;
		}		
	printf("input wrong vertex id in setVexW()!\n");
	// exit(0);
}

//设置边权值
inline void setEdgeW(Graph* g, int id, int w) {
	for (long i = 0; i < g->ne; i++)
		if (g->e[i].id == id) {
			g->e[i].w = w; 
			return;
		}	
	printf("input wrong edge id in setEdgeW()!\n");
	// exit(0);
}

//删除边
void deleteEdge(Graph* g, int id) {
	long idx=getEdgeIdx(g,id);
    int h=g->e[idx].h;//弧尾编号
    int hidx=getVexIdx(g,h);
	int t=g->e[idx].t;
	int tidx=getVexIdx(g,t);
    Evis[id]=0;
    for(int i=0;i<g->v[hidx].degree;i++){
        if(g->v[hidx].edges[i]==id){
            //删除弧尾的出边
            for(int j=i;j<g->v[hidx].degree-1;j++){
                g->v[hidx].edges[j]=g->v[hidx].edges[j+1];
            }
            g->v[hidx].degree--;
            //删除边表中的边
            for(int j=idx;j<g->ne-1;j++){
                g->e[j]=g->e[j+1];
            }
            g->ne--;
            break;
        }
		
    }
	for(int i=0;i<g->v[tidx].degree;i++){

		if(!g->dirctional&&g->v[tidx].edges[i]==id){
			//删除弧尾的出边
			for(int j=i;j<g->v[tidx].degree-1;j++){
				g->v[tidx].edges[j]=g->v[tidx].edges[j+1];
			}
			g->v[tidx].degree--;
			break;
		}
	}

}


//删除顶点
void deleteVex(Graph* g, int id) {
	int idx=getVexIdx(g,id);
    Vvis[id]=0;
    for(int i=0;i<g->ne;i++){
        if(g->e[i].h==id){
            //弧尾是被删顶点
            deleteEdge(g,g->e[i].id);
			i--;
        }
        if(g->e[i].t==id){
            //弧头是被删顶点
            deleteEdge(g,g->e[i].id);
			i--;
        }
    }
    if(g->nv==0){
        printf("顶点为空！无法删除\n");
        return;
    }
    for(int i=idx;i<g->nv-1;i++){
        g->v[i]=g->v[i+1];
    }
    g->nv--;
}


//增加顶点
void addVex(Graph* g, int w) {
	g->v[g->nv++].degree=0;
    for(int i=0;i<g->nv+1;i++){
        if(!Vvis[i]){
            g->v[g->nv-1].id=i;
            Vvis[i]=1;
            break;
        }
    }
    g->v[g->nv-1].w=w;
}

//增加边
void addEdge(Graph* g, int w, int h, int t) {
	int nid;//新增边的id
    for(int i=0;i<g->nv;i++){
        if(g->v[i].id==h){
			//寻找到要加边的下标i
            g->v[i].edges[g->v[i].degree]=g->ne;
            g->e[g->ne].h=h;
            g->e[g->ne].t=t;
			//设置属性
            for(int j=0;j<g->ne+1;j++){
                if(!Evis[j]){
					//在一定范围内寻找可用的id
                    g->e[g->ne].id=j;
                    Evis[j]=1;
					nid=j;
                    break;
                }
            }
            g->e[g->ne].w=w;
            g->v[i].degree++;
            g->ne++;
            break;
        }
    }
    if(!g->dirctional){
        //双向加边,此次无需寻找新id
        for(int i=0;i<g->nv;i++){
            if(g->v[i].id==t){
                g->v[i].edges[g->v[i].degree]=nid;
                g->v[i].degree++;
                break;
            }
        }
    }
}
int vis[MAXVERTEX];
void bfssearch(Graph *g,int sid,int tid){
	//广度优先搜索
	int FRINGE[MAXVERTEX];
	memset(FRINGE,0,sizeof(FRINGE));
	memset(vis,0,sizeof(vis));
	// memset(color,0,sizeof(color));
	//初始化FRINGE数组
	int head=0,tail=0;
	FRINGE[tail++]=sid;
	int parent[MAXVERTEX];
	memset(parent,-1,sizeof(parent));
	//初始化parent数组，便于寻路
	int u,h,t;
	while(1){
		int s=FRINGE[head++];
		if(head>tail){
			if(head>tail){
				printf("越界！搜索失败\n");
				exit(0);
			}
		}
		u=getVexIdx(g,s);
		for(int i=0;i<g->v[u].degree;i++){
			//遍历邻接点
			getVexByEdge(g,(g->v[u]).edges[i],&h,&t);
			int ops=u==h?t:h;//用Ops表示待搜索节点
			if(vis[ops])continue;
			vis[ops]=1;
			FRINGE[tail++]=ops;//未访问，插入尾部
			parent[ops]=s;
			if(ops==tid){
				printf("搜索成功！\n");
				int pos=ops;
				while(pos!=sid){
					//循环跳父亲输出遍历结果
					printf("%d<-",pos);
					pos=parent[pos];
				}
				printf("%d\n",sid);
				return;
			}
		}
	}
}
void dfssearch(Graph* g,int sid,int tid){
	int FRINGE[MAXVERTEX];
	int parent[MAXVERTEX];
	memset(parent,-1,sizeof(parent));
	int top=-1;
	FRINGE[++top]=sid;
	int vis[MAXVERTEX];
	memset(vis,0,sizeof(vis));
	vis[FRINGE[top]]=1;
	//初始化待使用变量
	while(top>=0&&FRINGE[top]!=tid){
		int u=FRINGE[top--];//栈顶出栈
		printf("look up %d\n",u);
		int idx=getVexIdx(g,u);
		for(int i=0;i<g->v[idx].degree;i++){
			int h,t;
			getVexByEdge(g,g->v[idx].edges[i],&h,&t);
			if(g->dirctional){
				//有向图的处理
				if(vis[t])continue;
				parent[t]=u;
				//通过父亲来寻找回路
				if(t==tid)
				{
					printf("%d",t);
					FRINGE[++top]=t;
					break;
				}
			}else{
				//无向图的处理
				if(h==u){
					//u是无向图中弧头
					if(vis[t])continue;
					else{
						parent[t]=u;
						FRINGE[++top]=t;
					}
					if(t==tid)//判断是否已经到达
					{
						printf("%d",t);
						FRINGE[++top]=t;
						break;
					}
				}
				if(t==u){
					//u是无向图中弧尾
					if(vis[h])continue;
					else{
						parent[h]=u;
						FRINGE[++top]=h;
						if(h==tid)
						{
							// printf("%d",t);
							FRINGE[++top]=h;
							break;
						}
					}

				}
			}
			
		}
	}
	if(top<0){
		printf("节点不存在或无法找到！\n");
	}else{
		int pos=tid;
		int st=0;
		while(pos!=-1){
			//循环跳父亲输出路径
			if(st++)printf("<-%d",pos);
			else printf("%d",pos);
			pos=parent[pos];
		}
		printf("\n");
	}
}
int dis[MAXVERTEX];
void dij(Graph* g, int sid){
	int parent[MAXVERTEX];
	memset(parent,-1,sizeof(parent));
	//初始化
	memset(dis,63,sizeof(dis));
	int vis[MAXVERTEX];
	memset(vis,0,sizeof(vis));
	dis[sid]=0;
	for(int i=0;i<g->nv;i++){
		int u=0,mindis=0x3f3f3f3f;
		//初始让最远距离设为无穷0x3f3f3f3f
		for(int j=0;j<g->nv;j++){
			if(!vis[g->v[j].id]&&dis[g->v[j].id]<mindis){
				u=g->v[j].id;
				mindis=dis[g->v[j].id];
				//找到当前缩边
				printf("add %d into S\n",j);
			}
			vis[u]=1;
			int udx=getVexIdx(g,u);
			for(int i=0;i<g->v[udx].degree;i++){
				int eid=g->v[udx].edges[i];
				int edx=getEdgeIdx(g,eid);
				if(u==g->e[edx].t){
					if(dis[g->e[edx].h]>dis[u]+g->e[edx].w){
						dis[g->e[edx].h]=dis[u]+g->e[edx].w;
						parent[g->e[edx].h]=u;//设定父亲，便于寻路
					}//更新距离
				}else{
					if(dis[g->e[edx].t]>dis[u]+g->e[edx].w){
						dis[g->e[edx].t]=dis[u]+g->e[edx].w;
						parent[g->e[edx].t]=u;//用于无向图
					}//更新距离
				}
			}
		}
	}
	for(int i=0;i<g->nv;i++){
		//循环输出距离信息
		printf("dis %d=%d	",g->v[i].id,dis[g->v[i].id]);
		int k=i;
		printf("%d",k);
		while(parent[k]!=-1){
			printf("<-%d",parent[k]);
			k=parent[k];
		}
		printf("\n");
	}
}
int color[MAXVERTEX];
int coloring(Graph* g){
	memset(color,0,sizeof(color));
	int cnt=0;
	for(int i=0;i<g->nv;i++){
		if(color[g->v[i].id])continue;
		else{
			color[g->v[i].id]=++cnt;
			//新染色为当前色数
			int FRINGE[MAXVERTEX];
			memset(FRINGE,0,sizeof(FRINGE));
			int head=0,tail=0;
			FRINGE[tail++]=g->v[i].id;
			while(head<tail){
				//循环处理FRINGE
				int u=FRINGE[head++];
				int udx=getVexIdx(g,u);
				for(int j=0;j<g->v[udx].degree;j++){
					int eid=g->v[udx].edges[j];
					int h,t;
					getVexByEdge(g,eid,&h,&t);
					if(!color[t]){
						//当前点未染过色
						FRINGE[tail++]=t;
						color[t]=cnt;
					}else if(!color[h]){
						//适用于无向图修正
						FRINGE[tail++]=h;
						color[h]=cnt;
					}
				}
			}

		}
	}
	return cnt;
}
int main() {
	Graph* g = (Graph*)malloc(sizeof(Graph));
	if (!g) {
		printf("error\n");
		exit(0);
	}	
	randgengraph(10, 0.5, 0, 1, "graph.txt", 5);
	initgraph(g, "graph.txt");
	printgraph(g);

	int* h;
	h = (int*)malloc(sizeof(int)); 
	int* t;
	t = (int*)malloc(sizeof(int)); 
	// addVex(g, 30);
	// setVexW(g,1,22);
	// addEdge(g, 50, 1, 3);
    // setEdgeW(g,1,3);
	// getVexByEdge(g, 10, h, t);
	// printf("%d %d\n", *h, *t);
	// deleteEdge(g, 10);
	// deleteVex(g, 5);
	dfssearch(g,1,0);
	bfssearch(g,2,3);
	dij(g,1);
	int co=coloring(g);
	printf("联通片数量=%d",co);
    // printgraph(g);
} 
