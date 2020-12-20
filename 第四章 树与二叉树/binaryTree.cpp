#include <iostream>
#include <stack>
#include <fstream>
#include <time.h>
#include <stack>
#include <queue>
using namespace std;
#define maxsize 100

typedef struct BiTnode
{
    int data;
    struct BiTnode *lchild, *rchild; //左右子树
} BiTnode, *BiTree;                  //二叉树结点，二叉树


typedef struct
{
    BiTree t;
    int tag;    //tag=0表示左子树入栈，tag=1表示右子树入栈
} stack1;

int radomnum(int A[])
{
    int range = maxsize;
    srand((int)time(0));
    for (int i = 0; i < maxsize; i++)
    {
        A[i] = rand() % range;
    }
    return 0;
}
void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}

int partion(int A[], int low, int high)
{
    int pivot = A[low];
    while (low < high)
    {
        while (low < high && A[high] >= pivot)
            high--;
        A[low] = A[high];
        while (low < high && A[low] <= pivot)
            low++;
        A[high] = A[low];
    }
    A[low] = pivot;
    return low;
}

void qiucksort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = partion(A, low, high);
        qiucksort(A, low, pivotpos - 1);
        qiucksort(A, pivotpos + 1, high);
    }
}

int BST_Insert(BiTree &T, int k)
{ //insert k to BST
    if (T == NULL)
    {
        T = new BiTnode;
        T->data = k;
        T->lchild = T->rchild = NULL;
       // delete T;
        return 0;
    }
    else if (k == T->data)
        return 0; //same value,don't insert
    else if (k < T->data)
        return BST_Insert(T->lchild, k); //insert k to left tree
    else
        return BST_Insert(T->rchild, k); //insert k to right tree
}
void Creat_BST(BiTree &T, int str[], int n)
{
    T = NULL; //initiate a new tree
    int i = 0;
    while (i < n) //insert each element;
    {
        BST_Insert(T, str[i]);
        i++;
    }
}
void visit(BiTree T)
{
    cout << T->data << " ";
}
void Preorder(BiTree T)
{
    if (T != NULL)
    {
        visit(T);            //访问根结点
        Preorder(T->lchild); //递归遍历左子树
        Preorder(T->rchild); //递归遍历右子树
    }
}
void preorder2(BiTree T)
{
    //先序遍历的非递归算法
    stack <BiTree> S;   //初始化一个栈
    BiTree p=T;     //p为工作指针
    while(p||!S.empty())    //当p或栈不空时循环
    {
        if(p)
        {
            visit(p);   //访问结点
            S.push(p);  //当前结点入栈
            p=p->lchild;    //向左
        }
        else
        {   
            p=S.top();   //读取栈顶元素
            S.pop();    //出栈
            p=p->rchild; //向右走；
        }
    }


}

void Inorder(BiTree T)
{
    if (T != NULL)
    {
        Inorder(T->lchild); //递归遍历左子树
        visit(T);           //访问根结点
        Inorder(T->rchild); //递归遍历右子树
    }
}
void inorder2(BiTree T)     //中序遍历的非递归算法
{
    stack <BiTree> S;
    BiTree p=T;
    while(p||!S.empty())
    {
        if(p)
        {
            S.push(p);  //当前结点入栈；
            p=p->lchild; //左孩子不空，一直向左
        }
        else
        {
            p=S.top();  //读取栈顶元素
            S.pop();    //栈顶结点出栈
            visit(p);  //访问出栈结点
            p=p->rchild;   //走向右子树
        }
    }
}
void PostOrder(BiTree T)
{
    ofstream outfile;
    outfile.open("database1.txt", ios::out | ios::app);
    if (T != NULL)
    {
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        outfile << T->data;
        outfile << ' ';
        visit(T);
        //visit(T);
    }
}
void postorder2(BiTree T)
{
    //后序遍历的非递归算法
    stack <BiTree> S;   //初始化一个栈
    BiTree p=T, r;  //r保存刚刚访问过的结点
    while(p||!S.empty())    //p不空或栈不空时循环
    {
        if(p)
        {
            S.push(p);  //结点入栈
            p=p->lchild; //走到最左边
        }
        else
        {
            p=S.top();  //读取栈顶结点
            if(p->rchild&&p->rchild!=r)   //如果右孩子存在且未被放问
            {
                p=p->rchild;    //转向右
                S.push(p);  //入栈
                p=p->lchild;    //在向左
            }
            else{
                //否则出栈并访问结点
                p=S.top();
                visit(p);
                r=p;    //记录访问结点
                S.pop();  //出栈
                p=NULL;   //结点访问完置空
            }
        }
    }
}
void postorder3(BiTree T)
{
    //后序遍历非递归算法
    stack1 S[maxsize];
    BiTnode *p = T;
    int top = -1; //栈顶指针
    while (p || top != -1)
    {
        if (p)      
        {
            S[++top].t = p;
            S[top].tag = 0; //左子树入队
            p = p->lchild;
        }
/*         else{
            while (top != -1 && S[top].tag == 1)    //如果栈顶结点的右子树已入队，则直接访问
            {
                p = S[top--].t;
                visit(p);
                p = NULL;
            }
            if (top != -1)      //栈顶结点右子树未入队
            {
                S[top].tag = 1; //
                p = S[top].t->rchild;   //向右走
            }
        } */ 
        else{
            p=S[top].t;     //读取栈顶结点
            if(p->rchild&&S[top].tag!=1){       //如果栈顶结点的右子树存在且未入栈
                p=p->rchild;S[top].tag=1;   //转向栈顶结点的右子树  
                S[++top].t=p;S[top].tag=0;  //右子树入栈
                p=p->lchild;        //向左
            }
            else{       //右子树不存在
                    p=S[top--].t;   
                    visit(p);   //放问
                    p=NULL;       //p指针置为空
            }
        }
    }
}
void levelorder(BiTree T)
{
    queue<BiTree>Q; //队列q
    BiTree p=T;
    Q.push(p);  //根节点入队
    while(!Q.empty())   //当队不空时
    {
        p=Q.front();    //读取队首元素
        Q.pop();  //队首出队
        visit(p);
        if(p->lchild!=NULL) //左孩子不空
            Q.push(p->lchild);  //左孩子入队
        if(p->rchild!=NULL)
            Q.push(p->rchild);  //右孩子入队
    }

}

/* int database(BiTree T)
{
    ofstream outfile;
    ifstream infile;
    char value;
    outfile.open("database1.txt");
    while (T != NULL)
    {
        outfile << T->data;
    }
    return 0;
}  */
int BiTdepth2(BiTree T)
{
    if (!T)
        return 0;
    int front = -1, rear = -1;
    int last = 0, level = 0;
    BiTree Q[maxsize]; //队列Q，储存二叉树结点
    Q[++rear] = T;     //根结点入队
    BiTree p;          //工作指针
    while (front < rear)
    {
        p = Q[++front]; //队列元素出队
        if (p->lchild)
            Q[++rear] = p->lchild; //左子树入队
        if (p->rchild)
            Q[++rear] = p->rchild; //右子树入队
        if (front == last)         //该层最右结点
        {
            level++; //层数加1
            last = rear;    //last指针指向下一层
        }
    }
    return level;
} 

int iscompele(BiTree T)
{
    queue<BiTree>Q;
    BiTree p;
    if(!T)
        return 1;
    Q.push(T); 
    while(!Q.empty())
    {
        p=Q.front();
        Q.pop();
        if(p)
        {
            Q.push(p->lchild);
            Q.push(p->rchild);
        }
        else
        {
            while(!Q.empty())
            {
                p=Q.front();
                Q.pop();
                if(p)
                    return 0;
            }
        }
    }
}


int main()
{
    cout << "str1,creat a BST" << endl;
    int str1[maxsize];
    radomnum(str1);
    display(str1, maxsize);
    BiTree T;
    Creat_BST(T, str1, maxsize);
    cout << "preorder BST:" << endl;
    Preorder(T);
    cout << endl;
    preorder2(T);
    cout<<endl;
    cout << "inorder BST:" << endl;
    Inorder(T);
    cout << endl;
    inorder2(T);
    cout<<endl;
    cout << "postorder" << endl;
    PostOrder(T);
    cout << endl;
    postorder2(T);
    cout<<endl;
    cout<<"levelorder"<<endl;
    levelorder(T);
    cout<<endl;
    cout << "the tree depth:" << endl;
    cout << BiTdepth2(T) << endl;
    cout<<"the binarytree is complete tree?"<<endl;
    qiucksort(str1, 0, maxsize);
    display(str1, maxsize);
    system("pause");
    return 0;
}