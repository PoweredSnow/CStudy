#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node, *LinkList;

LinkList initList(LinkList head)
{
    if (NULL == head)
    {
        head = (LinkList)malloc(sizeof(Node));
        head->next = NULL;
    }
    else
        fprintf(stderr , "Head is not NULL!\n");
    return head;
}

/* 头插法 */
void CreateList_L(LinkList h, int value)
{
    if (NULL == h)
        fprintf(stderr, "Failed\n");
    else
    {
        LinkList tmp = (LinkList)malloc(sizeof(Node));
        tmp->data = value;
        tmp->next = h->next;
        h->next = tmp;
    }
}

/* 尾插法 ver1 */
void insertList_f(LinkList h, int value)
{
    if (NULL == h)
        fprintf(stderr, "Failed\n");
    else
    {
        LinkList tmp = (LinkList)malloc(sizeof(Node));
        tmp->data = value;
        tmp->next = NULL;
        while (h->next)
            h = h->next;
        h->next = tmp;
    }
}

/* 尾插法 ver2 */
void insertList_s(LinkList *head, int value)
{
    Node *tmp = (Node *)malloc(sizeof(Node));
    tmp->data = value;
    tmp->next = NULL;
    if (NULL == *head)
        *head = tmp;
    else
    {
        Node *p = *head;
        while (p->next)
            p = p->next;
        p->next = tmp;
    }
}

/* 插入 */
int ListInsert(LinkList *L, int i, int e)
{
    int j;
    LinkList p, s;
    p = *L;
    j = 1;
    while (p && j < i) { /* 寻找第 i 个结点 */
        p = p->next;
        j++;
    }
    if (!(p) || j > i) { /* 第 i 个结点不存在 */
        return -1;
    }
    s = (LinkList)malloc(sizeof(Node));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 0;
}

/* 删除 */
int ListDelete(LinkList *L, int i, int *e)
{
    int j;
    LinkList p, q;
    p = *L;
    j = 1;
    while (p->next && j < i) { /* 遍历寻找第 i 个元素 */
        p = p->next;
        j++;
    }
    if (!(p->next) || j > i) { /* 第 i 个元素不存在 */
        return -1;
    }
    q = p->next;
    p->next = q->next;
    *e = q->data;
    free(q);
    return 0;
}

/* 长度 */
int lenList(LinkList h)
{
    if (NULL == h || NULL == h->next)
        return 0;
    int lengh = 0;
    while (h->next)
    {
        h = h->next;
        lengh++;
    }
    return lengh;
}

/* 删除连续 n 个结点 */
void DelList(LinkList h, int position, int len)
{
    if (position > lenList(h) || position < 1 || len > lenList(h) || len < 0 || NULL == h)
        fprintf(stderr, "Failed\n");
    else
    {
        while (--position)
            h = h->next;
        Node *p = h;
        for (int i = 0; i < len + 1; i++)
            h = h->next;
        p->next = h;
    }
}

/* 打印 */
void printList(LinkList h)
{
    if (NULL == h)
        fprintf(stderr, "Failed\n");
    else
    {
        while (h->next)
        {
            h = h->next;
            printf("%d ", h->data);
        }
        printf("\n");
    }
}

/* 去重 */
void removeRepetiton(LinkList h)
{
    if (NULL == h)
        fprintf(stderr, "Failed\n");
    else
    {
        Node *p = h->next;
        while (h)
        {
            p = h->next;
            while (p)
            {
                if (h->data == p->data)
                {
                    h->next = p->next;
                }
                p = p->next;
            }
            h = h->next;
        }
    }
}

/* A 插入 B */
void insertAToB(LinkList ha, LinkList hb, int position)
{
    if (position > lenList(hb) || position < 0 || NULL == ha || NULL == hb)
        fprintf(stderr, "Failed\n");
    else
    {
        while (position-- > 0)
            hb = hb->next;
        Node *p = hb->next;
        hb->next = ha->next;
        while (hb->next)
            hb = hb->next;
        hb->next = p;
    }
}

int main(void)
{
    LinkList head = NULL;

    head = initList(head);
    int e;
    CreateList_L(head, 1);
    CreateList_L(head, 2);
    // ListInsert(&head, 3, 3);
    printList(head);
    printf("%d\n", lenList(head));
    // ListDelete(&head, 3, &e);
    // printList(head);

    free(head);

    return 0;
}
