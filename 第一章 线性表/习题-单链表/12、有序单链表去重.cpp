#include<iostream>
using namespace std;

#define elemtype int

typedef struct LNODE   //单链表结点类型
{
	elemtype data;   //数据域
	struct LNODE *next;  //指针域
}LNODE,*LinkList;

//算法思想：由于是有序表，所有相同值域结点都是相邻的，用p扫描链表，
//若p->data==p->next->data;则删除其后继结点；注意用*q保存，不要断链
void del_same(LinkList &L)
{
    LNODE *p=L->next,*q;
    if(p==NULL)
        return;
    while(p->next!=NULL)
    {                              //的p的后继不为空时
        q=p->next;              //q指向p的后继
        if(p->data==q->data)    //如果值相等
        {   
            p->next=q->next;       //释放q结点
            free(q);                //释放值相同结点
        }
        else
        {
            p=p->next;
        }
    }
}
//法二
//采用尾插法，将头结点摘下，从第一结点开始，依次比较插入
void delsame_2(LinkList &L)
{
    LNODE *p=L->next,*ra=L,*q;   //ra指向表尾
    ra->next=NULL;          //先将头结点摘下
    if(p==NULL)
        return;
    while(p->next!=NULL)
    {
        q=p->next;
        if(p->data!=q->data)
        {
            ra->next=p;          //将结点p插入
            ra=p;                  //ra指向新的表尾结点
            p=p->next;
            if(p->next==NULL)		//把最后一个不等的结点插入
			{						
				ra->next=p;  
				ra=p;
			}
        }
        else
            p=p->next;
    }
    ra->next=NULL;    //最后将尾结点指针置为NULL
}