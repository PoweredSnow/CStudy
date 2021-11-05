#include "standard.h"

/* 栈的顺序存储结构 */
typedef struct {
    SElemType data[MAXSIZE];
    int top;                 /* 用于栈顶指针 */
} SqStack;

/* 插入元素 e 为新的栈顶元素 */
Status Push(SqStack *S, SElemType e)
{
    if (S->top == MAXSIZE - 1) /* 栈满 */
        return ERROR;
    S->top++;
    S->data[S->top] = e;
    return OK;
}

/* 若栈不空，则删除 S 的栈顶元素， 用 e 返回其值 */
Status Pop(SqStack *S, SElemType *e)
{
    if (S->top == -1)
        return ERROR;
    *e = S->data[S->top];
    S->top--;
    return OK;
}
