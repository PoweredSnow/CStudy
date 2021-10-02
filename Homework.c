#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAXSIZE 11

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
        fprintf(stderr, "The Stack is full\n");
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

int main(void)
{

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