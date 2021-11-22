#include <stdlib.h>

typedef struct Number {
    int data;
    int order, n;
    struct Number* next;
} Num, * NumList;

NumList add(NumList& a, NumList& b) {
    int firstNum = 0, secondNum = 0;

    for (int i = 0; i < a->n; i++) {
        firstNum += a->data * a->order;
        a = a->next;
    }
    for (int i = 0; i < b->n; i++) {
        secondNum += b->data * b->order;
        b = b->next;
    }

    int count;
    int result = firstNum + secondNum;

    for (count = 1;(result /= 10) >= 1;count++);

    NumList h = (NumList)malloc(sizeof(Num));
    h->n = count;
    h->data = result % 10;
    h->order = 1;
    h->next = NULL;

    for (int i = 1; i < count; i++) {
        NumList c = (NumList)malloc(sizeof(Num));
        c->n = count;
        result /= 10;
        c->data = result % 10;
        if (!i) {
            c->order = 1;
        }
        c->order *= 10;
        c->next = NULL;
        while (h->next)
            h = h->next;
        h->next = c;
    }

    return h;
}
