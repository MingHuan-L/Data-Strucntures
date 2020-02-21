#include<iostream>

#define elemtype int
//单链表结构定义
typedef struct LNODE
{
    elemtype data;
    LNODE *next;
}LNODE,*LinkList;

//求两个递增链表的交集，结果保存与一个链表中
//归并的思想。
void sameelem(LinkList &A,LinkList &B){
    LNODE *pa=A->next,*pb=B->next,*q=A,*u;      //pa、pb为工作指针，q指向生成链表A的表尾
    while(pa&&pb)
    {        
        if(pa->data==pb->data)
        {                           //a=b,将值相同结点保留
            q->next=pa;              //尾插法将结点保留
            q=pa;
            pa=pa->next;            //指针后移
            //u=pb;
            pb=pb->next;            //指针后移
            //free(u);
        }
        else if(pa->data<pb->data)      //a<b,a后移
        {   
            u=pa;
            pa=pa->next;
            free(u);
        }
        else if(pa->data>pb->data)      //b<a,b后移
        {
            u=pb;
            pb=pb->next;
            free(u);
        }

    }
    while(pa){                  //释放剩下结点
        u=pa;
        pa=pa->next;
        free(u);
    }
    while(pb){
        u=pb;
        pb=pb->next;
        free(u);
    }
    q->next=NULL;
    free(B);
}
