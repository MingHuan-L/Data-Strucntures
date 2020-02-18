# 数据结构笔记

## 目录：

### 第一章

- ##### 1、线性表

  - ##### 什么是线性表

    - ##### 	“线性表”：由同类型数据元素构成有序序列的线性结

  1. 表中元素个数称为线性表的**长度**
  
  2. 线性表没有元素时，称为**空表**
  
3. 表起始位置称为**表头**，表结束位置称**表尾
  
     #### //单链表结点类型描述
  
     ```
     typedef struct LNODE
     {
     	elemtype data;
     	struct LNODE *next;
     }LNODE,*Linklist;
     
     ```
  
     #### //头插法建立单链表
  
     ```
     LinkList creatList(LinkList &L)
     {
     	LNODE *s;
     	int x;		//创建头结点
     	L=(LinkList)malloc(sizeof(LNODE));
     	L->next=NULL; //初始化为空表
     	cin>>x;
     	while(x!=99999)
     	{
     		s=(LNODE*)malloc(sizeof(LNODE));
     		s->data=x;
     		s->next=L->next;
     		L->next=s;
     		cin>>x;
     	}
     	return L;
     }
     ```
  
     
  
     
  

 
