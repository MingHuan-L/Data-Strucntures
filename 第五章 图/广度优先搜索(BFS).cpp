#include "mapdefition.cpp"
#include<deque>
#include<vector>
using namespace std;
vector<VNode> Q[maxvertexnum];

/* 
算法思想：类似于二叉树的层序遍历。首先从访问起始顶点V，接着由V出发，依次访问v的各个未访问过的邻接顶点w1，w2····；。
然后再依次访问w1，w2，···wi的所有未被访问过的邻接结点；再从这些访问过的邻接结点出发，再访问它们所有未被访问过的邻接结点
依次类推，直到图中所有顶点都被访问过为止。
 */
bool visited[maxvertexnum];     //访问标记数据
void BFStraverse(gragh G)
{
    for (int i = 0; i < G.vexnum; ++i)
    {
        visited[i]=false;   //访问标记数组初始化
    }
    InitQueue(Q);      //初始化队列Q
    for (int i = 0; i < G.vexnum; i++)
    {
        if(!visited[i])
            BFS(G,i);              //广度优先搜索函数
    }
}

void BFS(gragh G,int v)
{
    visit(v) ;  //访问函数
    visited[v]=true;    //对V做已访问标记
    Enqueue(Q,v);       //顶点V入队
    while(!is_empty(Q))
    {
        deque(Q,v);
        for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
            if(!visited[w])
            {
                visit(w);
                visited[w]=true;
                Enqueue(Q,w);
            }
    }
}

