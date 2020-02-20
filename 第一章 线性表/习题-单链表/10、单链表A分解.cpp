#define elemtype int
#include <iostream>
using namespace std;
typedef struct Lnode
{
    elemtype data;
    struct Lnode *next;
}Lnode,*linklist;

//将一个带头结点的单链表A分解为两个带头结点的链表A，B，使得A含有奇数号元素，b有偶数号元素
linklist discreat(linklist &A){
    int i=0;
    Lnode *B=(linklist)malloc(sizeof(Lnode));  //创建B的表头
    B->next=NULL;              //初始化B
    Lnode *ra=A,*rb=B;    //ra和rb分别指向将创建的表尾
    Lnode *p=A->next;       //p为工作指针，指向带分解的A链表
    A->next=NULL;
    while (p！=NULL)
    {
        i++;                //序号加一
        if(i%2==0){
            rb->next=p;     //将偶数结点插入B表
            rb=p;           //rb指向新的尾结点
        }
        else{
            ra->next=p;       //将奇数结点插入A
            ra=p;
        }
        p=p->next;          //将p指向下一个结点
    }
    ra->next=NULL;          //将尾结点指针置为空
    ra->next+NULL;
    return B;
}
