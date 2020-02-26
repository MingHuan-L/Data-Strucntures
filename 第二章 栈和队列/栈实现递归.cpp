#include <iostream>
#define elemtype int
#define maxsize 100
typedef struct
{
    elemtype data[maxsize];
    int top;
} stack;

/*
    Pn(x)=1 , n=0;
    Pn(x)=2x,n=1;
    Pn(x)=2xPn-1(x)-2(n-1)Pn-2(x), n>1;
*/
//算法思想，设置一个栈保存n和对应的pn（x）值，栈中相邻元素的pn（x）有上述关系
//然后边出栈边计算pn（x），栈空后对于的pn（x）值就算出来了
double caculatorpn(int n, double x)
{
    struct stack
    {
        int n1;     //保存n
        double val; //保存pn（x）值
    } st[maxsize];
    int top = -1, i;             //top为栈st的下标值指针
    double fv1 = 1, fv2 = 2 * x; //n=0,n=1时p(x)的值
    for (i = n; i >= 2; i--)
    {
        top++;
        st[top].n1 = i; //将n到n-2逐一入栈
    }
    while (top >= 0) //栈不空时出栈，并计算
    {
        st[top].val = 2 * x * fv2 - 2 * (st[top].n1 - 1) * fv1; //pn的计算式
        fv1 = fv2;
        fv2 = st[top].val;
        top--;
    }
    if (n == 0)
    {
        return fv1;
    }
    return fv2;
}
int main()
{
    double x = 6;
    int n = 6;
    double result = caculatorpn(n, x);
    std::cout << result;
}
