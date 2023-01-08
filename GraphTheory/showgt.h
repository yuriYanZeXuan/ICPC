#ifndef  _SHOWGT_CPP_
#define  _SHOWGT_CPP_

#include <stdlib.h>
#include <stdio.h>
#include <string.h>



//保存图数据为html文件，供浏览器查看
void writeGraph(Graph *g,FILE *fp){
	for (int i = 0; i < g->nv; ++i) // 为了显示独立结点
		fprintf(fp, "{source: '%d', target: '%d', 'rela': '', type: 'resolved'},\n", g->v[i].id,g->v[i].id);
	if (g->weighted) 
		for (int i = 0; i < g->ne; ++i)	
			fprintf(fp, "{source: '%d', target: '%d', 'rela': '%d', type: 'resolved'},\n",g->e[i].h,g->e[i].t, g->e[i].w);
	else																	
		for (int i = 0; i < g->ne; ++i)
			fprintf(fp,"{source: '%d', target: '%d', 'rela': '', type: 'resolved'},\n",g->e[i].h,g->e[i].t);
}

//保存图为html文件，点击可展示图
void saveGraph(Graph *g,const char filename[]){
	FILE *fp = fopen(filename,"wb");
	if (!fp) {
		printf("打开写入文件出错！\n");
		exit(0);
	}
	//读取头部文件，二进制方式写入filename文件
	FILE *fh = fopen("head.txt","rb");
	fseek(fh,0,SEEK_END);
	unsigned long fsize = ftell(fh);
	rewind(fh);
	unsigned char *dataArray;
	dataArray = (unsigned char *)malloc(sizeof(unsigned char)*fsize);
	if (!dataArray) {
		printf("文件太大，内存不够，读入错误! %d\n",fsize);
		exit(0);
	}
	fread(dataArray,sizeof(unsigned char),fsize,fh); //读取文件
	fwrite(dataArray, sizeof(unsigned char),fsize,fp);//写入文件
	free(dataArray);
	fclose(fh);

	//将图的信息写入filename文件
	fprintf(fp,"\n\nvar links = \n[\n");
	writeGraph(g,fp);
	fprintf(fp,"\n];");

	//读取尾部文件，二进制方式写入filename文件
	if (g->dirctional)//有向图
		fh = fopen("tail.txt","rb");
	else //无向图
		fh = fopen("tail1.txt","rb");
	fseek(fh,0,SEEK_END);
	fsize = ftell(fh);
	rewind(fh);
	dataArray = (unsigned char *)malloc(sizeof(unsigned char)*fsize);
	if (!dataArray) {
		printf("文件太大，内存不够，读入错误! %d\n",fsize);
		exit(0);
	}
	fread(dataArray,sizeof(unsigned char),fsize,fh); //读取文件
	fwrite(dataArray, sizeof(unsigned char),fsize,fp);//写入文件
	free(dataArray);
	fclose(fh);

	fclose(fp);

}
#endif

