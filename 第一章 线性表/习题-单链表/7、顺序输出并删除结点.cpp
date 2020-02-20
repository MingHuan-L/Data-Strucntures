#define elemtype int
#include <iostream>
using namespace std;
typedef struct Lnode
{
    elemtype data;
    struct Lnode *next;
}Lnode,*linklist;

//顺序输出并删除
void del_s(linklist &head){
    while (head->next!=NULL)
    {
        Lnode *pre=head,*p=pre->next;       //pre为元素最小值结点的前驱
        while (p->next!=NULL)
        {
            if(p->next->data<pre->next->data)
                pre=p;                     //pre为当前最小值结点的前驱
            else
                p=p->next;
        }
        cout<<pre->next->data;          //输出最小值
        Lnode *r=pre->next;             //r指向最小值
        pre->next=r->next;             
        free(r);                    //释放结点
    }
    free(head);                     //释放头结点
    
}
