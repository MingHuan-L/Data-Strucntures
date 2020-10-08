#include <iostream>
#include <time.h>
#include <stdio.h>
int radomnum(int A[])
{
    A[0] = 0;
    int range = 100;
    const int maxsize = 100;
    srand((int)time(0));
    for (int i = 1; i <=maxsize; i++)
    {
        A[i] = rand() % range;
    }
    return 0;
}
void display(int A[], int n)
{
    for (int i = 0; i <= n; i++)
        std::cout <<"A["<<i<<"] is "<< A[i] << " ";
    std::cout << std::endl;
}
void headadjust(int A[], int k, int len)      //调整当前双亲结点
{
    A[0] = A[k];        //A【0】记录当前的双亲结点
    for (int i = 2 * k; i <= len; i *= 2)   //A【i】为A【k}的左孩子    
    {
        if (i < len && A[i] < A[i + 1])     //右孩子大于左孩子
            i++;            //则指向右孩子
        if (A[0] >= A[i])   //如果双亲结点大于孩子结点，不用交换
            break;
        else                
        {                       //双亲结点小于孩子结点
            A[k] = A[i];    //交换结点的值
            k = i;          //k指向当前的孩子结点，循环不断向下调整
        }
    }
    A[k] = A[0];        //被筛选结点的值放入最终位置
}
void Buildmaxheap(int A[], int len)
{
    for (int i = len / 2; i > 0; i--)   //最后一个双亲结点的编号为i/2取下界，第一个双亲结点为1.
    {                                   //对所有具有双亲结点含义的编号从大到小（i/2~1）做出调整
        headadjust(A, i, len);
    }
}
void heapsort(int A[], int len)     
{
    Buildmaxheap(A, len);   //建立大根堆。已调整完i/2~1的双亲结点。建立了初始的大根堆
    std::cout<<"current heaptop elem:"<<A[1]<<"   ";
    for (int i = len; i > 1; i--)
    {
        int temp = A[i];
        A[i] = A[1];
        std::cout << A[1] << " "; //不断输出堆顶
        A[1] = temp;     //堆底元素放到堆顶，破坏堆的结构。
        headadjust(A, 1, i - 1);    //重新建堆，长度为1~i-1;
    }
}
int main()
{
    int A[101];
    radomnum(A);
    std::cout << "A:" << std::endl;
    display(A, 100);
    std::cout << "heapsort A" << std::endl;
    heapsort(A, 100);
    system("pause");
    return 0;
}