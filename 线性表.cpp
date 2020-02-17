// 线性表.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <iostream>
using namespace std;
#define Maxsize 100
#define elmetype int
#define status int

//顺序表结构定义
typedef struct
{
	elmetype data[Maxsize];
	int length;
}Sqlist;

//初始化一个线性表
status InitList(Sqlist &L)
{
	memset(L.data, 0, sizeof(L));
	L.length = 0;
	return 0;
}

//创建顺序表，给表赋值
bool creatList(Sqlist &L, int n)
{
	if (n<0 || n>Maxsize)
		return false;
	for (int i = 0; i < n; i++)
	{
		elmetype temp;//temp用来存放当前输入的值；
		cin >> L.data[i];
		L.length++;
	}
	return true;
}

//本算法实现插入元素E到顺序表L第i个位置
bool Listinsert(Sqlist &L, int i, elmetype e)
{
	if (i<1 || i>L.length + 1)//判断位置i是否有效
		return false;
	if (L.length >= Maxsize)//判断储存空间是否已满
		return false;
	for (int j = L.length; j >= i; j--)
		L.data[j] = L.data[j - 1];//用j来表示数组下标，将第i个元素及之后的元素后移
	L.data[i] = e;
	L.length++;
	return true;
}

//删除算法，删除线性表L中第i个元素，成功则发回true，并将删除的元素用变量e返回
bool Listdelete(Sqlist &L, int i, int &e)
{
	if (i<1 || i>L.length)//判断i是否有效
		return false;
	e = L.data[i-1];//将第i个（数组下标为i-1）元素赋值给变量e
	for (int j = i; j < L.length; j++) //将i之后的元素往前移一位
		L.data[j - 1] = L.data[j];
	L.length--;
	return true;
}

//查找算法，在顺序表L中查找第一个值为e的元素，返回其位置
int locateElme(Sqlist &L, elmetype e)
{
	for (int i = 0; i < L.length + 1; i++)
		if (L.data[i] == e)
			return i + 1;
	return 0;
}

//删除顺序表中最小值的元素并返回其值，空出的位置用最后一个填补
bool del_min(Sqlist &L, elmetype &value)
{
	if (L.length == 0)
		return false;
	value = L.data[0];//假定0号元素的值最小
	int pos;
	for(int i=1;i<L.length;i++)    //循环让最小值赋值给value
		if (L.data[i] < value)
		{
			value = L.data[i];    
			pos = i;               //标记此时value的位置
		}
	L.data[pos] = L.data[L.length - 1];//将最小值位置用最后一个元素填补
	L.length--;
	return true;
}

//导致函数，将顺序表中L的所以元素逆置
void reverse(Sqlist &L)
{
	elmetype temp;//辅助变量，用于存放待交换的元素
	for (int i = 0; i < L.length / 2; i++)
	{
		temp = L.data[i];
		L.data[i] = L.data[L.length - i - 1];
		L.data[L.length - i - 1] = temp;
	}
}

//删除表中所有值为x的元素
void del_x(Sqlist &L, elmetype x)
{
	int k = 0;
	for(int i=0;i<L.length;i++)
		if (L.data[i] != x)
		{
			L.data[k] = L.data[i];//k用来记录不等于x的元素，不等于x的元素会被保留
			k++;
		}
	L.length = k;

	//第二种算法
	int i = 0;
	while (i < L.length)
	{
		if (L.data[i] == x)  //用k来记录移动步数
			k++;
		else
			L.data[i - k] = L.data[i];
		i++;
	}
	L.length = L.length - k;  //将顺序表后面k个值为x的元素删除
}


//删除有序顺序表L中值在给定s与t之间的所有元素
bool del_s_t(Sqlist &L, elmetype s, elmetype t)
{
	int i, j;
	if (s >= t || L.length == 0)
		return false;
	for (i = 0; i < L.length&&L.data[i] < s; i++);
	if (i >= L.length)
		return false;
	for (j = i; j < L.length&&L.data[j] <= t; j++);
	for (; j < L.length; i++, j++)
		L.data[i] = L.data[j];
	L.length = i;
	return true;
}

//删除顺序表L中值在s与t之间的元素
bool del_s_td(Sqlist &L, elmetype s, elmetype t)
{
	int i, k = 0;
	if (s>t||L.length==0)
		return false;
	for (i = 0; i < L.length; i++) {
		if (L.data[i] >= s && L.data[i] <= t)
			k++;
		else
			L.data[i - k] = L.data[i];
	}
	L.length -= k;
	return true;
}


//删除相同的元素
bool del_same(Sqlist &L)
{
	if (L.length == 0)
		return false;
	int i, j;
	for (i = 0, j = 1; j < L.length; j++)
		if (L.data[i] != L.data[j])
			L.data[++i] = L.data[j];
	L.length = i + 1;
}


//合并有序顺序表A和B成为一个新的有序顺序表C
typedef struct {
	elmetype *data;
	int maxsize, length;
}Seqlist;
bool merge(Seqlist A, Seqlist B, Seqlist C)
{
	if (A.length + B.length > C.maxsize)
		return false;
	int i = 0, j = 0, k = 0;
	while (i < A.length&&j < B.length)   //循环，两两比较，小者存入C中；
	{
		if (A.data[i] < B.data[j])        
			C.data[k++] = A.data[i++];   //A的元素存入C	
		else
			C.data[k++] = B.data[j++];	//B的元素存入C
	}
	while (i < A.length)				//如果A或B还有元素没存入，则存入
		C.data[k++] = A.data[i++];
	while (i < B.length)
		C.data[k++] = A.data[j++];
	C.length = k;
	return true;

}

/*已知在一维数组A【m+n】中依次存放着两个线性表a1-am,b1-bn;写一个函数将两顺序表互换*/
//算法思想：先将A全部逆置，再将前n个逆置，再将后m个逆置
typedef int datatype;
void reverses(datatype A[], int left, int right, int arraysize)//left与right变量用来存放需要逆置的长度
{
	if (left >= right || right >= arraysize)
		return;
	int mid = (left + right) / 2;
	for (int i = 0; i < mid - left; i++)
	{
		datatype temp = A[left + i];
		A[left + i] = A[right - 1];
		A[right - 1] = temp;
	}
}
void exchange(datatype A[], int m, int n, int arraysize)
{
	reverses(A, 0, m + n - 1, arraysize);//逆置全部
	reverses(A, 0, n - 1, arraysize);//逆置前n个元素
	reverses(A, n, m - 1, arraysize);//逆置n+1到第m个元素
}

//本算法实现查找有序表A【】中值为x的元素并与其后继元素交换位置，否则插入x
void searchexchangeinsert(Sqlist &A, elmetype x)
{
	int low = 0, high = A.length - 1, mid;
	while (low <= high)//折半查找
	{
		mid = (low + high) / 2;
		if (A.data[mid] == x)
			break;
		else
			if (A.data[mid] < x)
				low = mid + 1;
			else
				high = mid - 1;
	}
	if (A.data[mid] == x && mid != A.length)
	{
		elmetype t = A.data[mid];
		A.data[mid] = A.data[mid + 1];
		A.data[mid + 1] = t;
	}
	if (low > high)
	{
		for (int i = A.length - 1; i > high; i--)
		{
			A.data[i + 1] = A.data[i];
			A.data[i] = x;
		}
	}
}


int M_search(int A[], int B[], int n)
{
	int a1 = 0, b1 = n - 1, m1, a2 = 0, b2 = n - 1, m2;
	while (a1 != b1 || a2 != b2)
	{
		m1 = (a1 + b1) / 2;
		m2 = (a2 + b2) / 2;
		if (A[m1] == B[m2])
			return A[m1];
		if (A[m1] < B[m2])
		{
			if ((a1 + b1) % 2 == 0)
			{
				a1 = m1;
				b2 = m2;
			}
			else
			{
				a1 = m1 + 1;
				b2 = m2;
			}
		}
		else
		{
			if ((a1 + b1) % 2 == 0)
			{
				a1 = m1;
				b2 = m2;
			}
			else
			{
				a1 = m1 + 1;
				b2 = m2;
			}
		}
		return A[a1] < B[a2] ? A[a1] : B[a2];
	}
}

//功能函数，实现基本操作
void output(Sqlist L)
{
	cout << "当前顺序表的元素" << endl;
	for (int i = 0; i < L.length; i++)
		cout << L.data[i]<<" ";
	cout << endl;
}

//创建函数
void creat(Sqlist &L)
{
	int n;
	bool flag;
	L.length = 0;
	cout << "请输入要插入的长度";
	cin >> n;
	cout << "请输入元素，空格隔开";
	flag = creatList(L, n);
	if (flag)
	{
		cout << "创建成功";
		output(L);
	}
	else
		cout << "长度非法";
}





int main()
{
	Sqlist L;
	creat(L);
	output(L);
	return 0;
}

		// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
