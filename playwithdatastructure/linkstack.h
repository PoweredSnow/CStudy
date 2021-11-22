#include <stdlib.h>
#include "standard.h"

/* 栈的链式存储结构 */
typedef struct StackNode {
    SElemType data;
    struct StackNode* next;
} StackNode, * LinkStackPtr;

typedef struct LinkStack {
    LinkStackPtr top;
    int count;
} LinkStack;

/* 插入元素 e 为新的栈顶元素 */
Status Push(LinkStack* S, SElemType e) {
    LinkStackPtr s = (LinkStackPtr)malloc(sizeof(StackNode));
    s->data = e;
    s->next = S->top; /* 把当前的栈顶元素赋值给新节点的直接后继 */
    S->top = s;       /* 将新的结点 s 赋值给栈顶指针 */
    S->count++;
    return OK;
}

/* 若栈不空，则删除 S 的栈顶元素， 用 e 返回其值 */
Status Pop(LinkStack* S, SElemType* e) {
    LinkStackPtr p;
    if (StackEmpty(*S))
        return ERROR;
    *e = S->top->data;
    p = S->top;             /* 将栈顶结点赋值给 p */
    S->top = S->top->next;  /* 使得栈顶指针下一一位，指向后一结点 */
    free(p);
    S->count--;
    return OK;
}
