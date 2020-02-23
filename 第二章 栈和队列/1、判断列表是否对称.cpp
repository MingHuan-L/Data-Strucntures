#include<iostream>
#define elemtype int
typedef struct LNODE{
    elemtype data;
    struct LNODE *next;
}LNODE,*LinkList;

int dc(LinkList L,int n){
    //L是带头结点的n个元素单链表，本算法判断l是否中心对称
    int i; char s[n/2];    //s为字符栈
    LNODE *p=L->next;       //p为工作指针
    for(i=0;i<n/2;i++){     //链表前一半元素进栈
        s[i]=p->data;
        p=p->next;          
    }
    i--;            //恢复i的值
    if(n%2==1)
        p=p->next;      //若n为基数，后移中心点
    while(p!=NULL&&s[i]==p->data){
        i--;
        p=p->next;
    }
    if(i==-1)
        return 1;
    else
        return 0;
}