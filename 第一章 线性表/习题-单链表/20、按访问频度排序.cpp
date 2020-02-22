#include<iostream>
#define elemtype int
 typedef struct Ddnode{
     elemtype data;
     struct Ddnode *prior,*next;
     int freq;
 }Ddnode,*Dlinklist;

Dlinklist Locate(Dlinklist &L,elemtype x)
{
    Ddnode *p=L->next,*q;
    while(p&&p->data!=x)
        p=p->next;          //查找x
    if(!p)
    {
        printf("不存在结点值为x的结点");
        exit( 0);
    }
    else
    {
        p->freq++;                  //freq加一
        p->next->prior=p->prior;      //加p结点摘下
        p->prior->next=p->next;
        q=p->prior;                 //q指向p的前驱
        while(q!=L&&q->freq<p->freq)    //找到插入的结点
            q=q->prior;
        p->next=q->next;                //将p插入q之后
        q->next->prior=p;
        p->prior=q;
        q->next=p; 
    }
    return p;
}