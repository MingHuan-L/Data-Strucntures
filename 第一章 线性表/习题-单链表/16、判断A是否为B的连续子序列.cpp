#include<iostream>
#include<string>
using namespace std;

#define elemtype int

typedef struct LNODE   //单链表结点类型
{
	elemtype data;   //数据域
	struct LNODE *next;  //指针域
}LNODE,*LinkList;

bool pattern(LinkList A,LinkList B){
    LNODE *pa=A->next,*pb=B->next,*pre=pa;
    if(pa==NULL)
        return false;
    while(pa&&pb){
        if(pa->data==pb->data){
            pa=pa->next;
            pb=pb->next;
        }
        else
        {   
            pre=pre->next;
            pa=pre;
            pb=B->next;
        }    
    }
    if(pb==NULL)
        return true;
    else
        return false;
}