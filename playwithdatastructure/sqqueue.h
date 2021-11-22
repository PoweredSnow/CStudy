#include "standard.h"

/* 循序队列的顺序存储结构 */
typedef struct {
    QElemType data[MAXSIZE];
    int front;               /* 头指针 */
    int rear;                /* 尾指针，若队列不空，指向队列尾元素的下一个位置 */
} SqQueue;

/**
 * 队列满的条件：(rear + 1) % QueueSize == front
 * 通用的计算队列长度公式为：(rear - front + QueueSize) % QueueSize
 */

 /* 初始化一个空队列 Q */
Status InitQueue(SqQueue* Q) {
    Q->front = 0;
    Q->rear = 0;
    return OK;
}

/* 返回 Q 的元素个数，也就是队列的当前长度 */
int QueueLength(SqQueue Q) {
    return (Q.rear - Q.front + MAXSIZE) % MAXSIZE;
}

/* 若队列未满，则插入元素 e 为 Q 新的队尾元素 */
Status EnQueue(SqQueue* Q, QElemType e) {
    if ((Q->rear + 1) % MAXSIZE == Q->front)
        return ERROR;
    Q->data[Q->rear] = e;               /* 将元素 e 赋值给队尾 */
    Q->rear = (Q->rear + 1) % MAXSIZE;  /* rear 将指针向后移一位置， */
                                        /* 若到最后则转到数组头部 */
    return OK;
}

/* 若队列不空，则删除 Q 中队头元素，用 e 返回其值 */
Status DeQueue(SqQueue* Q, QElemType* e) {
    if (Q->front == Q->rear)
        return ERROR;
    *e = Q->data[Q->front];              /* 将队头元素赋值给 e */
    Q->front = (Q->front + 1) % MAXSIZE; /* front 指针向后移一位置， */
                                         /* 若到最后则转到数组头部 */
    return OK;
}

