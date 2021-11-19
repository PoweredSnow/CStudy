#include <stdio.h>

typedef struct Number {
    int data;
    struct Number *next;
} Num;

Num sum(Num a, Num b)
{
    int firstNum = a.data + a.next->data * 10 + a.next->next;
}

int main(int argc, char const *argv[])
{


    return 0;
}
