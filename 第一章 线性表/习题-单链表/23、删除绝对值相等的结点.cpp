#include<iostream>
#define elemtype int
#include<math.h>

typedef struct LNODE{
    elemtype data;
    struct LNODE *link;
}LNODE,*LinkList;

//算法思想，申请一个长度为结点数量大小的数组，边扫描边标记
//便扫描边赋值为1，如果检测到值相等的，即tag=1,删除结点
void func(LinkList &L)
{
    LNODE *p=L,*r;
    int *q,m;
    q=(int *)malloc(sizeof(int)*20);
    for(int i=0;i<20;i++)           //用一个大小为n的数组标记链表每个结点值是否出现过
        *(q+i)=0;
    while(p->link!=NULL)
    {
        m=p->link->data>0?p->link->data:-p->link->data;
        if(*(q+m)==0)                   //判断该结点是否出现过
        {
            *(q+m)=1;                   //首次出现
            p=p->link;
        }
        else                            //重复出现
        {
            r=p->link;                  //删除结点
            p->link=r->link;
            free(r);
        } 
    }
    //free(r);
}