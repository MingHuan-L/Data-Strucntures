# 习题

#### 1、递归删除不带头结点的单链表L中值为x的结点

递归模型
$$
递归终止条件：f(L,x)==不做任何事；  若L为空  
递归主体 ：f(L,x)==删除 *L结点；	f（L->next,x）; 若L-data==x
		f(L,x)==f(L->next,x); 其他情况
$$




```
void del_recursion(Linklist &L,elemtype x)
{//递归删除值为x的结点
	LNODE *p;       //p指向被删除的结点
	if(L==NULL)
		return;
	if(L->data==x){
		P=L;
		L=L->next;
		ferr(p);
		del_recursion(L,x);   //递归调用
	}
	else
		del_recursion(L->next,x);  //递归调用
}
```

2、删除带头结点的单链表L中所有值为x的结点

```
void del_x(Linklist &L,elemtype x){
	//方法一：从头结点开始，向后遍历
	LNODE *P=L->next,*pre=L,*q;  //初始化pre为头指针，p为头结点
	while(p!=NULL)
	{
		if(p->data==x)
		{
		q=p;				//q指向待删除的结点
		p=p->next;			//后移
		pre->next=p;
		free(q);
		}
		else
		{
		pre=p;
		p=p->next;
		}
	}
}

void del_x2(Linklist &L,elemtype x){
	//法二：尾插法建立L单链表
	LNODE *p=L->next,*r=L,*q;  //r为尾指针，指向头结点
	while(p!=NULL)
	{
	if(p-data!==x){  //如果p结点的值为不x的时候，
	 	r->next=p;
	 	r=p;
	 	p=p->next;
	}
	else{
		q=p;
		p=p->next;
		free(q);    //删除q
	}
	}
	r->next=NULL;    //插入结束后尾指针置为NULL
}
```

