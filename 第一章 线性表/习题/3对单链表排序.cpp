

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

//删除单链表中介于最大值与最小值之间的元素
void rangdel(Linklist &L,int min,int max){
    LNODE *pre=L,*p=L->next;
    while (P!=NULL)
    {
        if(p->data>min&&p->data<max){
            pre->next=p->next;
            free(p);
            p=pre->next;
        }
        else{
            pre=p;
            p=p->next;
        }
    }
    
}