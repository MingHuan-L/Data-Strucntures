

/*#define elemtype int
typedef struct LNODE   //单链表结点类型
{
	elemtype data;   //数据域
	struct LNODE *next;  //指针域
}LNODE,*LinkList;
*/

#define elemtype int
typedef struct LNODE
{
    elemtype data;
    struct LNODE *next;
}LNODE,*Linklist;

//对单链表排序
void sort_1(Linklist &L){
    LNODE *pre,*p,*r;
    p=L->next;              
    r=p->next;             //r保持p的后继结点
    p->next=NULL;         //构造只含一个元素的有序表
    p=r;
    while(p!=NULL){
        r=p->next;         //保持p的后继结点
        pre=L;             //
        while(pre->next!=NULL&&pre->next->data<p->data)
            pre=pre->next;
        p->next=pre->next;
        pre->next=p;
        p=r;
    }
}