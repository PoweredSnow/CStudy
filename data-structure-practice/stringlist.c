#include<stdio.h>
#include<stdlib.h>
#include<string.h>

/**
 * 串的定长顺序存储表示
 */

#define MAXSTRLEN 255 // 用户可在 255 以内定义最大串长
typedef unsigned char SString[MAXSTRLEN + 1]; // 0号单元存放串的长度

/**
 * 串的堆分配存储表示
 */

typedef struct {
    char *ch;   // 若为非空串，则按串长分配存储区，否则 ch 为 NULL
    int length; // 串长度
} HString;

/**
 * 顺序表是在计算机内存中以数组的形式保存的线性表，
 * 是指用一组地址连续的存储单元依次存储数据元素的线性结构；
 * c2-1.h 线性表的动态分配顺序存储结构
 */

#define LIST_INIT_SIZE 10 /* 线性表存储空间的初始分配量 */
#define LIST_INCREMENT strlen(chars) /* 线性表存储空间的分配增量 */
typedef struct
{
	char *elem; /* 存储空间基址 */
	int length; /* 当前长度 */
	int listsize; /* 当前分配的存储容量(以sizeof(ElemType)为单位) */
} SqList;

SqList* InitList(SqList* L)
{   /* 操作结果：构造一个空的顺序线性表L */
    if(!((*L).elem = (char*)malloc(LIST_INIT_SIZE * sizeof(char))))
        exit(EXIT_FAILURE);
    (*L).length = 0;
    (*L).listsize = LIST_INIT_SIZE;
    return L;
}

void StrAssign(SqList *L, char *chars)
{
    if (strlen(chars) > LIST_INIT_SIZE) {
        /* 报错 */
        /* 截断 */
        /* 扩充 */
        (*L).listsize = LIST_INCREMENT;
        if (!((*L).elem = realloc((*L).elem, (*L).listsize)))
            exit(EXIT_FAILURE);
    }
    (*L).length = strlen(chars);
    for (int i = 0; i < (*L).length; i++)
        (*L).elem[i] = chars[i];
}

int main(void)
{
    SqList *L = (SqList*)malloc(sizeof(SqList));
    char *chars = "Hello,world!";

    L = InitList(L);
    StrAssign(L, chars);
    for (int i = 0; i < (*L).length; i++)
        printf("%c", (*L).elem[i]);
    printf("\n");

    return 0;
}
