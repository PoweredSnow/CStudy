#include "standard.h"
#include <stdlib.h>
#include <time.h>

/**
 * 线性表的单链表存储结构
 */
typedef struct Node {
    ElemType data;
    struct Node* next;
} Node;
typedef struct Node* LinkList;

/**
 * 初始条件：顺序线性表 L 已存在，1<=i<=ListLengh(L)
 * 操作结果：用 e 返回 L 中第 i 个数据元素的值
 */
Status GetElem(LinkList L, int i, ElemType* e) {
    int j;
    LinkList p;
    p = L->next;
    j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    *e = p->data;
    return OK;
}

/**
 * 初始条件：顺序线性表 L 已存在，1<=i<=ListLengh(L)
 * 操作结果：在 L 中第 i 个位置之前插入新的数据元素 e，L的长度加 1
 */
Status LinkInsert(LinkList* L, int i, ElemType e) {
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i) {
        p = p->next;
        ++j;
    }
    if (!p || j > i)
        return ERROR;
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}


/**
 * 初始条件：顺序线性表 L 已存在，1<=i<=ListLengh(L)
 * 操作结果：删除 L 的第 i 个数据元素，并用 e 返回其值，L 的长度减1
 */
Status ListDelete(LinkList* L, int i, ElemType* e) {
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i) {
        p = p->next;
        ++j;
    }
    if (!(p->next) || j > i)
        return ERROR;
    q = (LinkList)malloc(sizeof(Node));
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return OK;
}

/* 随机产生 n 个元素的值，建立带表头结点的单链线性表 L（头插法） */
void CreateListHead(LinkList* L, int n) {
    LinkList p;
    int i;
    srand(time(0)); /* 初始化随机数种子 */
    *L = (LinkList)malloc(sizeof(Node));
    (*L)->next = NULL; /* 先建立一个带头结点的单链表 */
    for (i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1; /* 随机生成 100 以内的数字 */

        p->next = (*L)->next;
        (*L)->next = p; /* 插入到表头 */

    }
}

/* 随机产生 n 个元素的值，建立带表头结点的单链线性表 L（尾插法） */
void CreateListTail(LinkList* L, int n) {
    LinkList p, r;
    int i;
    srand(time(0));
    *L = (LinkList)malloc(sizeof(Node));

    r = *L; /* r 为指向尾部的结点 */
    for (i = 0; i < n; i++) {
        p = (LinkList)malloc(sizeof(Node));
        p->data = rand() % 100 + 1;

        r->next = p;
        r = p;
    }
    r->next = NULL;
}

/* 初始条件：顺序线性表 L 已存在，操作结果：将 L 重置为空表 */
Status ClearList(LinkList* L) {
    LinkList p, q;
    p = (*L)->next;
    while (p) {
        q = p->next;
        free(p);
        p = q;
    }
    (*L)->next = NULL;
    return OK;
}

