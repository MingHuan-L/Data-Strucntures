
//删除带头结点单链表L中值最小的结点

linklist del_min(linklist &L){
    Lnode *pre=L,*p=L->next;
    Lnode *minpre=pre,*minp=p;    //p为工作指针，用minp来保存最小结点
    while(p!=NULL){
        if(p->data<minp->data){
            minp=p;
            minpre=pre;
        }
        pre=p;
        p=p->next;
    }
    minpre->next=minp->next;
    free(minp);
    return L;
}