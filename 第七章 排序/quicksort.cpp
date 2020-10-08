#include <iostream>
#include <time.h>
#include <stdio.h>
int radomnum(int A[])
{
    int range = 100;
    const int maxsize = 100;
    srand((int)time(0));
    for (int i = 0; i < maxsize; i++)
    {
        A[i] = rand() % range;
    }
    return 0;
}
void swap(int A[],int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = A[a];
}
void display(int A[], int n)
{
    for (int i = 0; i < n; i++)
        std::cout << A[i] << " ";
    std::cout << std::endl;
}
int partition(int A[], int low, int high)
{
    int pivot = A[low]; //用当前第一个元素作为pivot，即A【low】用pivot保存，下面的步骤最终将pivot放在最终位置上
    while (low < high)  //循环，不断交换两个比pivot大或小的元素
    {
        while (low < high && A[high] >= pivot)
            high--;                           //找到比pivot小的元素
        A[low] = A[high];                     //放到左边
        while (low < high && A[low] <= pivot) //在左边找到比pivot大的元素
            low++;
        A[high] = A[low]; //放到右边
    }
    A[low] = pivot; //最后将pivot放到最终位置上
    return low;     //返回当前表的起始端，用于递归调用
}
int partition2(int A[], int low, int high)
{
    int random = low + rand() % (high - low + 1); //随机取random下标的值作为基准
    swap(A,random,low);                      //将选取的基准元素放到A【low】
    int pivot = A[low];                           //基准元素
    int i = low;                                  //用i记录基准元素最终位置
    for (int j = low + 1; j <= high; j++)
    {
        if (A[j] < pivot)       //如果右边有小于基准的元素
            swap(A, ++i,j); //交换位置，A[i]为基准元素的最终位置
    }
    swap(A,i,low); //将基准元素放到最终位置上
    return i;           //返回基准元素位置
}
void quicksort(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = partition(A, low, high); //pivopos是每一趟后pivot的位置
        quicksort(A, low, pivotpos - 1);        //将每次划分出来的表递归调用排序，以pivopos为中心，一分为二
        quicksort(A, pivotpos + 1, high);
    }
}
void qiucksort2(int A[], int low, int high)
{
    if (low < high)
    {
        int pivotpos = partition2(A, low, high);
        qiucksort2(A, low, pivotpos - 1);
        qiucksort2(A, pivotpos + 1, high);
    }
}
void bubblesort(int A[], int n)
{
    for (int i = 0; i < n - 1; i++) //遍历趟数，最多n-1趟。
    {
        bool flag = false;              //表示本趟冒泡是否发生交换false为未发生交换
        for (int j = n - 1; j > i; j--) //从表尾开始，A[0]~A[n-1];
        {
            if (A[j - 1] < A[j]) //若为逆序，则交换
            {
                int temp = A[j - 1];
                A[j - 1] = A[j];
                A[j] = temp;
                flag = true;
            }
        }
        if (flag == false)
            break;
    }
}
void doububble(int A[], int n)
{
    int low = 0, high = n - 1;
    bool flag = true;
    while (low < high && flag)
    {
        flag = false; //每趟flag设置为false；
        for (int i = low; i < high; i++)
        {
            if (A[i] > A[i + 1])
            {
                int temp = A[i];
                A[i] = A[i + 1];
                A[i + 1] = temp;
                flag = true;
            }
        }
        high--;
        for (int j = high; j > low; j--)
        {
            if (A[j] < A[j - 1])
            {
                int temp = A[j];
                A[j] = A[j - 1];
                A[j - 1] = temp;
                flag = true;
            }
        }
        low++;
    }
}
void move(int A[], int n)
{
    int i = 0, j = n - 1;
    while (i < j)
    {
        while (i < j && A[i] % 2 != 0)
            i++; //找偶数
        while (i < j && A[j] % 2 != 1)
            j--; //找奇数
        if (i < j)
        {
            int temp = A[i];
            A[i] = A[j];
            A[j] = temp;
        }
        i++;
        j--;
    }
}
int seek_k(int A[], int low, int high, int k)
{
    int pivot = A[low];
    int low_temp = low;
    int high_temp = high;
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
    if (low == k)
        return A[low];
    else if (low > k)
        return seek_k(A, low_temp, low - 1, k);
    else
        return seek_k(A, low + 1, high_temp, k);
}
int main()
{
    int A[100];
    radomnum(A);
    std::cout << "A:" << std::endl;
    display(A, 100);
    std::cout << std::endl;
    // qiucksort2(A,0,99);
    //  std::cout << "quicksort A:" << std::endl;
    quicksort(A, 0, 100);
    //  display(A,100);
    //  bubblesort(A,100);
    //  doububble(A,100);
    std::cout << "bubblesort A:" << std::endl;
    display(A, 100);
    // move(A,100);
    // display(A,100);
    int k = seek_k(A, 0, 99, 5);
    std::cout << k << std::endl;
    system("pause");
    return 0;
}