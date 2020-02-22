#include<iostream>
#define elemtype int
typedef struct LNODE{
    struct LNODE *next;
    elemtype data;
}LNODE,*LinkList;

LinkList merge2(LinkList &h1,LinkList &h2){
    LNODE *pa=h1,*pb=h2;
    while(pa->next!=h1)
        pa=pa->next;
    while(pb->next!=h2)
        pb=pb->next;
    pa->next=h2;
    pb->next=h1;
    return h1;
}
