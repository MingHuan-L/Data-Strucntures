#include<iostream>
#define elemtype char
typedef struct LNODE
{
    elemtype data;
    LNODE *next;
}LNODE,*LinkList;

//算法思想，先求两表长，再求两表长之差，长表从长度只差个位置开始，短表从第一个位置开始
//同步遍历，第一个公共结点则为公共后缀的起始位置

int length(LinkList str1)
{   
    LNODE *p=str1->next;
    int len=0;
    while(p!=NULL){
        len++;
        p=p->next;
    }
    return len;
}

LNODE* findnode(LinkList str1,LinkList str2){
    int len1=length(str1);
    int len2=length(str2);
    LNODE *p,*q;
    for(p=str1;len1>len2;len1--)
        p=p->next;
    for(q=str2;len1<len2;len2--)
        q=q->next;
    while(p->next!=NULL&&p->next!=q->next){
        p=p->next;
        q=q->next;
    }
    return p;
}
