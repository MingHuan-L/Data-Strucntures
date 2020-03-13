#include <iostream>
#include<stack>
using namespace std;
#define maxsize 100
typedef struct BiTnode
{
    int data;
    struct BiTnode *lchild, *rchild; //左右子树
} BiTnode, *BiTree;                  //二叉树结点，二叉树

int BST_Insert(BiTree &T, int k)
{ //insert k to BST
    if (T == NULL)
    {
        T = new BiTnode;
        T->data = k;
        T->lchild = T->rchild = NULL;
        return 1;
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
void visit(BiTree T){
    cout<<T->data<<" ";
}
void Preorder(BiTree T)
{
    if (T != NULL)
    {
        visit(T); //访问根结点
        Preorder(T->lchild);    //递归遍历左子树
        Preorder(T->rchild);    //递归遍历右子树
    }
}
void Inorder(BiTree T){
    if(T!=NULL){
        Inorder(T->lchild);//递归遍历左子树
        visit(T);           //访问根结点
        Inorder(T->rchild); //递归遍历右子树
    }
}
void PostOrder(BiTree T){
    if(T!=NULL){
        PostOrder(T->lchild);
        PostOrder(T->rchild);
        visit(T);
    }
}
int main()
{
    cout << "please input data,creat a BST" << endl;
    int str1[maxsize] = {7, 4, 6, 9, 2, 11, 15, 8, 3, 10};
    cout << " BST :7,4,6,9,2,11,15,8,3,10 :" << endl;
    BiTree T;
    Creat_BST(T, str1, 10);
    cout << "preorder BST:" << endl;
    Preorder(T);
    cout<<endl;
    cout<<"inorder BST:"<<endl;
    Inorder(T);
    cout<<endl;
    cout<<"postorder"<<endl;
    PostOrder(T);
    system("pause");
    return 0;
}