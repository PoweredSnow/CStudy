#include <stdio.h>
#include "standard.h"

typedef struct {
    VertexType vex[MAXVEX];          /* 顶点表 */
    EdgeType arc[MAXVEX][MAXVEX];    /* 邻接矩阵，可看作边表 */
    int numVertexes, numEdges;       /* 图中当前的顶点数和边数 */
} MGraph;

/* 建立无向网图的邻接矩阵表示 */
void CreateMGraph(MGraph *G)
{
    int i, j, k, w;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);  /* 输入顶点数和边数 */
    for (i = 0; i < G->numVertexes; i++)            /* 读入顶点信息，建立顶点表 */
        scanf(&G->vex[i]);
    for (i = 0; i < G->numVertexes; i++)
        for (j = 0; j < G->numVertexes; j++)
            G->arc[i][j] = INFINITY;                /* 邻接矩阵初始化 */
    for (k = 0; k < G->numEdges; k++) { /* 读入 numEdges 条边，建立邻接矩阵 */
        printf("输入边（vi, vj）上的下标 i，下标 j 和权 w:\n");
        scanf("%d,%d,%d", &i,&j,&w);                /* 输入边(vi,vj)上的权 */
        G->arc[i][j] = w;
        G->arc[j][i] = G->arc[i][j];                /* 因为是无向图，矩阵对称 */
    }
}

typedef struct EdgeNode {       /* 边表结点 */
    int adjvex;                 /* 邻接点域，存储该顶点对应的下标 */
    EdgeType weight;            /* 用于存储权值，对于非网图可以不需要 */
    struct EdgeNode *next;      /* 链域，指向下一个邻接点 */
} EdgeNode;

typedef struct VertexNode {     /* 顶点表结点 */
    VertexType data;            /* 顶点域，存储顶点信息 */
    EdgeNode *firstedge;        /* 边表头指针 */
} VertexNode, AdjList[MAXVEX];

typedef struct {
    AdjList adjList;
    int numVertexes, numEdges;  /* 图中当前顶点数和边数 */
} GraphAdjList;

/* 建立图的邻接表结构 */
void CreateALGraph(GraphAdjList *G)
{
    int i, j ,k;
    EdgeNode *e;
    printf("输入顶点数和边数：\n");
    scanf("%d,%d", &G->numVertexes, &G->numEdges);  /* 输入顶点数和边数 */
    for (i = 0; i < G->numVertexes; i++) {
        scanf(&G->adjList[i].data);                 /* 输入顶点信息 */
        G->adjList[i].firstedge = NULL;             /* 将边表置为空表 */
    }
}
