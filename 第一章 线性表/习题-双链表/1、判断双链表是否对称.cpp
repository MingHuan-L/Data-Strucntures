#include<iostream>
 #define elemtype int
 typedef struct DNODE{
     elemtype data;
     struct DNODE *prior,*next;     
 }DNODE,*Dlinklist;

 //算法思想，让p从左扫描，q从右扫描，直到指向统一结点
 //奇数个结点时（p=q）;偶数个结点时（p->next=q或q->prior=p)
 int symmetry(Dlinklist L){
     DNODE *p=L->next,*q=L->prior;
     while(p!=q&&q->prior!=p){
         if(p->data==q->data){
             p=p->next;
             q=q->prior;
         }
         else
            return 0;
         }
    return 1;     
 }