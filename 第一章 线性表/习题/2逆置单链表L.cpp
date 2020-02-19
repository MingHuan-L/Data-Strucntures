#define elemtype int;
typedef struct Lnode{
    elemtype data;
    struct Lnode *next;
}Lnode,*linklist;

//就地逆置单链表L
linklist reverses_1(linklist L){
    //将头结点摘下，从第一个结点开始，一次插入到头结点的后面
    Lnode *p,*r;
    p=L->next;
    L->next=NULL;
    while(p!=NULL){
        r=p->next;          //暂存p的后继
        p->next=L->next;    //将p结点插入到头结点之后
        L->next=p;          //新的头结点
        p=r;                //p继续工作
    }
    return L;
}

//算法二
linklist reverses_2(linklist L){
    Lnode *pre,*p,*r;
    p=L->next;     //p指向第一个结点
    r=p->next;      //r保存p之后的结点
    p->next=NULL;   //第一个结点的next置为空
    while(r!=NULL){       //后面还有结点时；
        pre=p;
        p=r;
        r=r->next;
        p->next=pre;      //指针反转
    }
    L->next=p;         //最后一个结点
    return L;
}