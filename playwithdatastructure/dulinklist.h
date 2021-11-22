#include "standard.h"

/* 线性表的双向链表存储结构 */
typedef struct DulNode {
    ElemType data;
    struct DulNode* prior; /* 直接前驱指针 */
    struct DulNode* next;  /* 直接后继指针 */
} DulNode, * DuLinkList;

/* 插入 */
/**
 * s->prior = p;
 * s->next = p->next;
 * p->next->prior = s;
 * p->next = s;
 */

 /* 删除 */
 /**
  * p->prior->next = p->next;
  * p->next->prior = p->prior;
  */
