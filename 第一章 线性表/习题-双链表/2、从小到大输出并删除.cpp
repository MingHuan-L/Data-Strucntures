#include<iostream>
#define elemtype int

typedef struct LNODE   //单链表结点类型
{
	elemtype data;   //数据域
	struct LNODE *next;  //指针域
}LNODE,*LinkList;

void delprint(LinkList &L){
   LNODE *p,*q,*minp,*minpre;
    
    while(L->next!=L)
    {                           //表不空时循环
        p=L->next,q=L;      //p为工作指针，q为p的前驱
        minp=p,minpre=q;     //minp记住最小值  
        while(p!=L)
        {                            //找最小值，用minp记录
            if(p->data<minp->data)      //
            {
            minp=p;                 
            minpre=q;
            }
            q=p;                       
            p=p->next;
        }
        std::cout<<minp->data;      //输出最小值
        minpre->next=minp->next;    //将最小值结点断链
        free(minp);                 //释放
    }
    free(L);                    //释放头结点
}