#include<iostream>
#include<string>
using namespace std;

#define elemtype int

typedef struct LNODE   //单链表结点类型
{
	elemtype data;   //数据域
	struct LNODE *next;  //指针域
}LNODE,*LinkList;

//求两个有序递增的单链表A、B的公共结点形成单链表C，不破坏A、B的结点
void mergeAB(LinkList A,LinkList B)
{
    LNODE *pa=A->next,*pb=B->next;
    LinkList L;
    L=(LinkList)malloc(sizeof(LNODE));      //初始化一个结果链表
    L->next=NULL;
    LNODE *r=L->next,*s;               //p为工作指针
    while(pa&&pb)                   //从A、B第一个结点开始比较
    {
        if(pa->data==pa->data)
        {   
            s=(LNODE*)malloc(sizeof(LNODE));    //产生新结点
            s->data=pa->data;                   //将新结点插入L表尾
            r->next=pa;             //将公共结点插入L中
            r=pa;
            pa=pa->next;            //A、B同时后移
            pb=pb->next;
        }
        else
        {
            if(pa->data<pb->data)
                pa=pa->next;     //元素值小的结点指针往后移
            else
                pb=pb->next;      
        }     
    }
    r->next=NULL;         //将尾结点置为NULL；
}