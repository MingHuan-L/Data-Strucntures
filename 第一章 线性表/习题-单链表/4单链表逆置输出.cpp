#include<string>
#include<iostream>
#define elemtype int

typedef struct LNode{
    elemtype data;
    LNode *next;
}LNode,*linklist;

//单链表逆置输出
void reverseprint(linklist L)
{
    if(L->next!=NULL)
    {
        reverseprint(L->next);
    }
    std::cout<<L->data;
}