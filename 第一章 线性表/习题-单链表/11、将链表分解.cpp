#include<iostream>
#define elemtype int
typedef struct Lnode
{
    elemtype data;
    Lnode *next;
}Lnode,*linklist;

//采用头茬法分解链表，使之形成新的链表
linklist discreat(linklist &A)
{
    linklist B =new Lnode;
    B->next=NULL;           //初始化B表
    Lnode *p=A->next,*q;  //p为工作指针
    Lnode *ra=A;            //ra指向A的尾结点
    while(p!=NULL)
    {
        ra->next=p;        //将P链接到A的表尾  处理a1
        ra=p;               //移动ra指向Ａ的表尾
        p=p->next;          // 处理 b1
        q=p->next;         //将p之后的结点保存
        p->next=B->next;   //将p插入到B的前端  
        B->next=p;          //更新头结点
        p=q;                //处理剩下的结点
    }
    ra->next=NULL;
    return B;
}
