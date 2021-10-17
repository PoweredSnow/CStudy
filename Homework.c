#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 11
#define MAXSTRLEN 255

int Time(int n)
{
    int count = 0;    //1
    int x = 2;        //1 n = 2^i i = log2 n
    while (x < n / 2) //2 < 2^(n-1)
    {
        x *= 2;  //2^((log2 n) +1) = 2^(n-1)
                 //(log2 n) + 1 = n-1
        count++; //i = log2 n - 2
    }
    return (count);
} //Time

int Fibonacci(int k, int m)
{
    if (k <= 1 || m < 0)
    {
        fprintf(stderr, "Error\n");
        exit(EXIT_FAILURE);
    }
    int j = 0, sum = 0;
    int *arr = calloc(m + 1, sizeof(int));
    for (int i = 0; i < k; i++)
    {
        if (i < k - 1)
            arr[j++] = 0;
        else if (i == k - 1)
            arr[j++] = 1;
    }
    for (int n = 0; n < m - k + 1; n++)
    {
        for (int i = j - k; i < j; i++)
        {
            arr[j] += arr[i];
        }
        j++;
    }
    return arr[j - 2];
}

void midsearch(int brr[], int len, int m)
{
    int left = 0, right = len - 1;
    int mid;
    while (left <= right)
    {
        mid = (left + right) / 2;
        if (brr[mid] == m)
            break;
        else if (brr[mid] < m)
        {
            left = mid + 1;
        }
        else
            right = mid - 1;
    }
    if (left <= right)
        printf("该数存在于数组中。\n");
    else
        printf("该数不存在数组中！\n");
}

/*
typedef struct Node
{
    char data;
    struct Node *next;
} Node, *LinkList;

void insertList(LinkList h, int value)
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

void printList(LinkList h)
{
    if (NULL == h)
        fprintf(stderr, "Failed\n");
    else
    {
        while (h->next)
        {
            h = h->next;
            printf("%c", h->data);
        }
        printf("\n");
    }
}

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

void isSymmetric(LinkList h)
{
    if (NULL == h)
        fprintf(stderr, "Failed\n");
    else
    {
        LinkList p = h->next, q = h;
        int len = lenList(h);

        for (int i = 0; i < len / 2; i++)
        {
            for (int j = i; j < len; j++)
                h = h->next;
            if (h->data != p->data)
            {
                printf("isNotSymmetric\n");
                return;
            }
            p = p->next;
            h = q;
        }
        printf("isSymmetric\n");
    }
}
*/

typedef struct Stack
{
    char arr[50];
    int top;
} S;

/* 设计入栈、出栈及栈中元素个数3个函数 */

S *initStack(S *s)
{
    s = (S *)malloc(sizeof(S));
    if (!s)
    {
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    s->top = 50;
    return s;
}

void push(S *s, char e)
{
    if (s->top == 0)
    {
        fprintf(stderr, "The Stack is full\n");
        exit(EXIT_FAILURE);
    }
    s->top--;
    s->arr[s->top] = e;
}

void pop(S *s, char e)
{
    if (s->top == 50)
    {
        fprintf(stderr, "The Stack is null\n");
        exit(EXIT_FAILURE);
    }
    e = s->arr[s->top++];
}

int lenStack(S *s)
{
    int len = 0;
    while (s->top != 50)
    {
        len++;
        s->top++;
    }
    return len;
}

typedef struct Queue
{
    int data[MAXSIZE];
    int front;
    int rear;
    int count;
} Q;

/* 编写入队和出队的算法 */

Q *initQueue(Q *q)
{
    q = (Q *)malloc(sizeof(Q));
    q->front = 0;
    q->rear = 0;
    q->count = 0; //循环队列中的元素空间都能得到利用
    return q;
}
/* 入队 */
void enQueue(Q *q, int e)
{
    if (q->rear == q->front && q->count == 1)
    {
        fprintf(stderr, "The queue is full\n");
        exit(EXIT_FAILURE);
    }
    q->data[q->rear] = e;              // 插入队尾
    q->rear = (q->rear + 1) % MAXSIZE; // 尾部指针后移，如果到最后则转到头部
    if (q->rear == q->front)
        q->count = 1;
}
/* 出队 */
void deQueue(Q *q, int *e)
{
    if (q->front == q->rear && q->count == 0)
    {
        fprintf(stderr, "The queue is null\n");
        exit(EXIT_FAILURE);
    }
    *e = q->data[q->front];              // 返回队头元素
    q->front = (q->front + 1) % MAXSIZE; // 队头指针后移，如到最后转到头部
    if (q->front == q->rear)
        q->count = 0;
}
/* 遍历队列元素 */
/*
void queueTraverse(Q *q)
{
    if (q->front == q->rear && q->count == 0)
    {
        fprintf(stderr, "The queue is null\n");
        exit(EXIT_FAILURE);
    }
    if (q->front < q->rear)
    {
        for (int i = q->front; i < q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
    }
    else if (q->front > q->rear)
    {
        for (int i = q->front; i < q->rear; i++)
        {
            printf("%d ", q->data[i]);
        }
    }
    printf("\n");
}
*/

typedef struct Node
{
    char data;
    struct Node *next;
} Node;

typedef struct
{
    Node *f, *r;
} LQ;
/* 队列初始化 */
LQ *initLinkQueue(LQ *q)
{
    q->f = q->r = (Node *)malloc(sizeof(Node));
    if (!q->f)
    {
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    q->f->next = NULL;
    return q;
}
/* 队尾插入元素 */
void EnQ(LQ *q, char x)
{
    Node *s = (Node *)malloc(sizeof(Node));
    if (!q)
    {
        fprintf(stderr, "OVERFLOW\n");
        exit(EXIT_FAILURE);
    }
    s->data = x;
    s->next = NULL;
    q->r->next = s; // 原来队尾的 next 指向新的元素
    q->r = s;       // 将新元素变为队尾
}
/* 队头元素出队 */
int DeQ(LQ *q, char *x)
{
    Node *p;
    if (q->f == q->r)
        return 0;
    p = q->f->next; // p指向队头元素
    *x = p->data;
    q->f->next = p->next; // 头结点的后继指向队头的下一个元素
    if (q->r == p)
        q->r = q->f; // 队尾直接指向头结点将其出队
    free(p);
    return 1;
}
/* 遍历 */
void vist(LQ *q)
{
    Node *p;
    p = q->f->next;
    while (p)
    {
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

typedef unsigned char SString[MAXSTRLEN + 1];

int StrAssign(SString T, char *chars)
{
    if (strlen(chars) > MAXSTRLEN) {
        fprintf(stderr, "Error\n");
        return -1;
    }
    T[0] = strlen(chars);
    for (int i = 0; i < T[0]; i++)
        T[i + 1] = chars[i];
    return 1;
}

#define MAXSIZE 12500

typedef struct {
    int i, j; //该非零元的行下标和列下标
    int e;
} Triple;

typedef struct {
    Triple data[MAXSIZE + 1]; // 非零元三元组表， data[0]未用
    int mu, nu, tu; // 矩阵的行数、列数和非零元的个数
} TSMatrix;

int Judge(TSMatrix  T, int i, int j)
{
    if (i <= 0 || j <= 0 || i > T.mu || j > T.nu) {
        fprintf(stderr, "Error\n");
        return -1;
    }
    if (T.tu) {
        for (int k = 1; k <= T.tu; k++) {
            if (T.data[k].i == i && T.data[k].j == j) {
                    printf("是非零元\n");
                    return 0;
            }
        }
    }
    printf("不是非零元\n");
    return 0;
}

typedef enum {ATOM, LIST} ELemTag;  // ATOM == 0:原子, LIST == 1:子表
typedef struct GLNode {
    ELemTag tag;                    // 公共部分，用于区分原子节点和表结点
    union {                         // 原子节点和表结点的联合部分
        char atom;                  // 原子节点的值域
        struct GLNode *hp;          // 表结点的表头指针
    };
    struct GLNode *tp;              // 相当于线性链表的 next,指向下一个元素结点
} *Glist;                           // 广义表类型 GList 是一种拓展的线性链表

int main(void)
{
    Glist G = (Glist)malloc(sizeof(Glist));
    G->tag = 1, G->tp = NULL;
    G->hp->tag = 0, G->hp->atom = 'a';
    G->hp->tp->tag = 1, G->hp->tp->tp = NULL;
    G->hp->tp->hp->tag = 0,  G->hp->tp->hp->atom = 'b';
    G->hp->tp->hp->tp->tag = 0,  G->hp->tp->hp->tp->atom = 'c';
    G->hp->tp->hp->tp->tp->tag = 0,  G->hp->tp->hp->tp->tp->atom = 'd';
    G->hp->tp->hp->tp->tp->tp->tag = 0,  G->hp->tp->hp->tp->tp->tp->atom = 'd',
    G->hp->tp->hp->tp->tp->tp->tp = NULL;


    /*
    TSMatrix T;
    T.mu = 3, T.nu = 4, T.tu = 4;
    T.data[1].i = 2, T.data[1].j = 1, T.data[1].e = 5;
    T.data[2].i = 2, T.data[2].j = 3, T.data[2].e = 6;
    T.data[3].i = 2, T.data[3].j = 4, T.data[2].e = 3;
    T.data[4].i = 3, T.data[4].j = 1, T.data[4].e = -1;

    Judge(T, 2, 1);
    */


    /*
    SString T;
    T[0] = MAXSTRLEN;
    char chars[] = "Hello";

    StrAssign(T, chars);
    for (int i = 0; i < strlen(chars); i++)
        printf("%c", T[i + 1]);
    printf("\n");
    */


    // LQ *q = (LQ*)malloc(sizeof(Node));
    // q = initLinkQueue(q);

    /*
    Q *q = NULL;
    q = initQueue(q);
    int d;
    for (int i = 0; i < MAXSIZE; i++)
    {
        enQueue(q, i);
    }
    queueTraverse(q);
    for (int i = 2; i < MAXSIZE; i++)
    {
        deQueue(q, &d);
        printf("d = %d,\n", d);
    }
    queueTraverse(q);
    */

    /*
    S *s = NULL;
    s = initStack(s);
    char t;
    int t1;

    for (int i = 0; i < 50; i++)
    {
        push(s, i);
    }
    pop(s, t);
    for (int i = 49; i >= s->top; i--)
    {
        printf("%d ", s->arr[i]);
    }
    printf("\n");
    t1 = lenStack(s);
    printf("%d\n", t1);
    */

    /*
    LinkList h = NULL;
    LinkList h = (Node *)malloc(sizeof(Node));
    char arr[] = "xxyyx";

    for (int i = 0; i < strlen(arr); i++)
    {
        insertList(h, arr[i]);
    }
    printList(h);
    isSymmetric(h);
    free(h);
    // printf("%d\n", lenList(heada));
    */

    /*
    for (int i = 1; i < 6; i++)
    {
        insertList(heada, i), insertList(headb, i + 10);
    }
    printList(heada);
    printList(headb);
    DelList(heada, 1, 2);
    printList(heada);
    insertAToB(heada, headb, 1);
    printList(headb);
    */

    /*
    char arr[] = {1, 1, 2, 2, 3, 3, 3, 4, 4, 4, 4, '\0'};
    for (int i = 0; i < strlen(arr); i++)
        insertList(head, arr[i]);
    printList(head);
    removeRepetiton(head);
    printList(head);
    */

    return 0;
}
