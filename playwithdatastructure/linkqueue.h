#include <stdlib.h>
#include "standard.h"

/* 队列的链式存储结构 */
typedef struct QNode {
    QElemType data;
    struct QNode *next;
} QNode, *QueuePtr;

typedef struct {
    QueuePtr front, rear;
} LinkQueue;

/* 插入元素 e 为 Q 的新的队尾元素 */
Status EnQueue(LinkQueue *Q, QElemType e)
{
    QueuePtr s = (QueuePtr)malloc(sizeof(QNode));
    if (!s)
        exit(OVERFLOW);
    s->data = e;
    s->next = NULL;
    Q->rear->next = s; /* 把拥有元素 e 新结点 s 赋值给原队尾结点的后继， */
    Q->rear = s;       /* 把当前的 s 设置为队尾结点，rear 指向 s */
    return OK;
}

/* 若队列不空，删除 Q 的队头元素，用 e 返回其值 */
Status DeQueue(LinkQueue *Q, QElemType *e)
{
    QueuePtr p;
    if (Q->front == Q->rear)
        return ERROR;
    p = Q->front->next; /* 将欲删除的队头结点暂存给 p */
    *e = p->data;
    Q->front->next = p->next; /* 将原队头结点后继 p->next 赋值给头节点后继 */
    if (Q->rear == p) /* 若队头是队尾，则删除后将 rear 指向头结点 */
        Q->rear = Q->front;
    free(p);
    return OK;
}
