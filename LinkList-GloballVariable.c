#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node *next;
} Node;

Node *head = NULL;

/* 链表初始化 */
int initList()
{
    if (NULL == head)
    {
        head = (Node *)malloc(sizeof(Node));
        if (!head)
        {
            fprintf(stderr, "OVERFLOW\n");
            return -1;
        }
        head->next = NULL;
        fprintf(stderr, "OK\n");
        return 0;
    }
    else
    {
        fprintf(stderr, "FAILED\n");
        return -1;
    }
}

/* 尾插法添加元素 */
int insertList(int value)
{
    if (NULL == head)
    {
        fprintf(stderr, "Failed\n");
        return -1;
    }
    Node *p = head;
    while (p->next)
    {
        p = p->next;
    }
    Node *tmp = (Node *)malloc(sizeof(Node));
    if (!tmp)
    {
        fprintf(stderr, "OVERFLOW\n");
        return -1;
    }
    tmp->data = value;
    tmp->next = NULL;
    p->next = tmp;
    fprintf(stderr, "OK\n");
    return 0;
}

/* 打印 */
void printList()
{
    printf("Begin to print...\n");
    if (NULL == head || NULL == head->next)
    {
        printf("List is null.");
        return;
    }
    Node *p = head->next;
    while (p->next)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("%d\n", p->data);
    printf("End print.\n");
}

/* 排序 */
int sortList()
{
    if (NULL == head || NULL == head->next)
    {
        fprintf(stderr, "FAILED\n");
        return -1;
    }
    Node *p = head->next;
    Node *q = p->next;
    while (p)
    {
        q = p->next;
        while (q)
        {
            if (p->data > q->data)
            {
                int tmp = p->data;
                p->data = q->data;
                q->data = tmp;
            }
            q = q->next;
        }
        p = p->next;
    }
    fprintf(stderr, "OK\n");
    return 0;
}

/* 长度 */
int lenList()
{
    if (NULL == head || NULL == head->next)
        return 0;
    Node *p = head->next;
    int lengh = 0;
    while (p)
    {
        p = p->next;
        lengh++;
    }
    return lengh;
}

/* 删除 */
void delList(int position)
{
    if (position > lenList() || position < 1)
        fprintf(stderr, "FAILED");
    else
    {
        Node *p = head;
        Node *q = p->next;
        if (NULL == p || NULL == q)
        {
            fprintf(stderr, "FAILED");
            return;
        }
        while (--position)
        {
            p = p->next;
            q = p->next;
        }
        p->next = q->next;
        free(q);
        fprintf(stderr, "OK\n");
    }
}

/* 销毁 */
void destroyLink()
{
    if (NULL == head)
    {
        return;
    }
    else
    {
        Node *p = head->next;
        Node *q = p;
        while (p)
        {
            p = p->next;
            free(q);
            q = p;
        }
    }
}

int main(void)
{
    initList(head);
    insertList(0xF);
    insertList(0x5);
    insertList(0xC);
    insertList(0x5);
    printList();
    sortList();
    printList();
    int l = lenList();
    printf("%d\n", l);
    delList(2);
    printList();
    destroyLink();

    return 0;
}
