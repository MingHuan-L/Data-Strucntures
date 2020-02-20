
#define elemtype int
typedef struct LNODE
{
    elemtype data;
    struct LNODE *next;
}LNODE,*Linklist;

//给定两个单链表，编写出算法找出两个链表的公共结点
Linklist search(Linklist L1,Linklist L2){
    int len1=length(L1),len2=length(L2);  //length是计算链表长度函数，算出L1与L2的长度
    Linklist longlist,shorlist;    //分别指向长表和段表
    if(len1>len2){
        longlist=L1->next;          
        shorlist=L2->next;
        dist=len1-len2;             //表长只差
    }
    else{
        longlist=L2->next;
        shorlist=L1->next;
    }
    while (dist--)
    {
        longlist=longlist->next;       //长表先遍历到第 dist个结点
    }
    while (longlist!=NULL)              //开始寻找公共结点
    {
        if(longlist==shorlist)          //找到公共结点
            return shorlist;
        else
        {
            longlist=longlist->next;
            shorlist=shorlist->next;
        }
        
    }
    return NULL;                    //如果找不到公共结点
}