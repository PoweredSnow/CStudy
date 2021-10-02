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
        head = (Node *)malloc(sizeof(Node));
        head->next = NULL;
    }
    else
        fprintf(stderr, "Head is not NULL!\n");
}

/* 头插法 */
void CreateList_L(Node *h, int value)
{
    if (NULL == h)
        fprintf(stderr, "Failed\n");
    else
    {
        Node *tmp = (Node *)malloc(sizeof(Node));
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
        Node *tmp = (Node *)malloc(sizeof(Node));
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

/* 删除 */
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
    CreateList_L(head, 1);
    CreateList_L(head, 2);
    printList(head);

    free(head);

    return 0;
}
