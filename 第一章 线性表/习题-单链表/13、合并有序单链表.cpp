#include <iostream>
#define elemtype int

typedef struct LNODE   //单链表结点类型
{
	elemtype data;   //数据域
	struct LNODE *next;  //指针域
}LNODE,*LinkList;

void mergelist(LinkList &La,LinkList &Lb)
{
    LNODE *r,*pa=La->next,*pb=Lb->next;
    La->next=NULL;              //先将La指针置为空，作为结果表
    while(pa&&pb)
    {
        if(pa->data<=pb->data)
        {
            r=pa->next;         //用r保存p之后的结点
            pa->next=La->next;     //头插法将p结点插入La中
            La->next=pa;
            pa=r;               //恢复下一个要比较的结点
        }
        else
        {
            r=pb->next;
            pb->next=La->next;      //头插法将pb结点插入La中
            La->next=pb;
            pb=r;
        }
        if(pa)                  //如果pa有剩余
            pb=pa;
        while(pb)               //处理剩下的结点
        {
            r=pb->next;
            pb->next=La->next;
            La->next=pb;
            pb=r;
        }
        free(pb);

    }
}