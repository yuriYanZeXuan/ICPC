#include<stdio.h>
#include<stdlib.h>
const int maxn=100;

typedef struct  Vertex
{
    int adjVex[maxn];
    int data;
}Vertex;

typedef struct array{
    int len;
    Vertex *v[maxn];
}array;
Vertex* remove(array *a){
    // for(int i=0;i<n;i++)
}
int main(){
    array* A=(array*)malloc(sizeof(array)*10);
    for(int i=0;i<10;i++){
        A[i].len=i;
    }
    printf("%d\n",sizeof(*A));
    printf("%d\n",A[0].len);
    A++;
    for(int i=0;i<9;i++){
        printf("%d\n",A[i].len);
    }
    return 0;
}