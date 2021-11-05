#include "standard.h"


/**
 * 两栈共享空间结构
 * 前提：两个具有相同数据类型的栈
 */
typedef struct {
    SElemType data[MAXSIZE];
    int top1;
    int top2;
} SqDoubleStack;

/* 插入元素 e 为新的栈顶元素 */
Status Push(SqDoubleStack *S, SElemType e, int stackNumber)
{
    if (S->top1 + 1 == S->top2) /* 栈已满 */
        return ERROR;
    if (stackNumber == 1) /* 栈 1 有元素进栈 */
        S->data[++S->top1] = e;
    else if (stackNumber == 2)
        S->data[--S->top2] = e;
    return OK;
}

/* 若栈不空，则删除 S 的栈顶元素， 用 e 返回其值 */
Status Pop(SqDoubleStack *S, SElemType *e, int stackNumber)
{
    if (stackNumber == 1) {
        if (S->top1 == -1)
            return ERROR;
        *e = S->data[S->top1--];
    } else if (stackNumber == 2) {
        if (S->top2 == MAXSIZE)
            return ERROR;
        *e = S->data[S->top2++];
    }
    return OK;
}
