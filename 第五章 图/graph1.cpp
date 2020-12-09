#include <iostream>
#include <string>
#include <queue>
#include <limits>
#include <stack>
#define maxvertex 100

bool visted[maxvertex];
/* typedef struct graph{
    Vnode *vertex[maxvertex];
    int vexnum,arcnum;
}graph; */
int G[maxvertex][maxvertex];    //邻接矩阵表示法
/* class graph1
{
    int G[maxvertex][maxvertex];
public:
    int vernum;
    int arcnum;
    int first();
    int nextneiborhor();
    int dfs(int G,int v);
    int bfs(int G,int v);
};
int graph1::bfs(int G,int v)
{
    //从顶点编号v开始，广度优先搜索图G
    std::cout<<v;   //访问结点v
    visted[v]=true; //访问标志
    std::queue<int>Q;   //d队列Q
    Q.push(v);  //顶点v入队
    while (!Q.empty())
    {
        int w=Q.front();//读取队头元素
        Q.pop();    //出队
        for(w=first();w>=0;w=nextneiborhor())   //访问队头元素的邻接顶点
        {
            if(!visted[w])  //如果邻接结点未访问
            {
            std::cout<<w;   //访问
            Q.push(w);      //入队
            visted[w]=true; //访问标记
            }
        }
    }
    
} */


typedef struct Arcnode //边表结点
{
    int adjvex;           //弧所指向的顶点
    struct Arcnode *next; //指向下一条弧的指针
    int weigtht;          //边的权值
} Arcnode;                //边

typedef struct Vnode
{
    char data;               //顶点数据域
    Arcnode *first;          //指向第一条依附该节点的指针
} Vnode, Adjlist[maxvertex]; //顶点结构类型

typedef struct
{
    Adjlist vertex1;
    // Vnode *vertex[maxvertex];//顶点表
    int vexnum, arcnum; //顶点数，弧数
} graph;



void initiate(graph &G) //初始化图G
{
    for (int i = 0; i < maxvertex; i++)
    {
        G.vertex1[i].first = NULL;
        //  G.vertex[i]->first=NULL;
        G.arcnum = 0;
        G.vexnum = 0; //结点数边数为0
    }
}
void add_vertex(graph &G, int x) //添加x结点
{
    for (int i = 0, j = 65; i < x; i++, j++)
    {
        G.vertex1[i].data = j;
        //  G.vertex[i]->data=i+1;   //默认为结点的值为结点编号+1
    }
    G.vexnum = x;
}
void add_arc(graph &G, int num, int to, int weight)
{
    //有向表，边表默认为出边表
    //示例：vertex【num】→vertex【to】，weight为边的权值
    if (num > G.vexnum || to > G.vexnum)
        return;
    Arcnode *p = G.vertex1[num].first; //p指向待插入边的边结点
    Arcnode *pre = p;                  //pre指向p的前驱
    while (p != NULL)
    {
        pre = p; //pre是p的前驱
        p = p->next;
    }
    p = new Arcnode;
    p->adjvex = to;      //弧指向的顶点
    p->weigtht = weight; //边的权值
    p->next = NULL;      //下一条弧为空
    if (G.vertex1[num].first == NULL)
    {
        G.vertex1[num].first = p; //将边插
    }
    else
    {
        pre->next = p; //将边插
    }
    G.arcnum++; //弧数+1
}
/* int firstneighbor(graph G,int v)    //求图中顶点v的第一个邻接点，返回顶点号
{
    if(G.vertex1[v].first!=NULL)
        return G.vertex1[v].first->adjvex;  //返回顶点v邻接顶点的编号
    else
        return -1;  //否则返回-1；
} */

void BFS(graph G, int v) //从顶点v出发，广度优先遍历图G
{
    std::cout << G.vertex1[v].data << " "; //访问结点v
    visted[v] = true;                      //对v做已访问标记
    std::queue<int> Q;                     //队列q；
    Q.push(v);                             //结点v入队
    while (!Q.empty())
    {
        v = Q.front();                   //v指向队头顶点
        Q.pop();                         //队头结点出队
        Arcnode *p = G.vertex1[v].first; //p指向结点v第一个邻接顶点
        while (p != NULL)
        {
            int i = p->adjvex; //i为邻接结点编号
            if (!visted[i])    //如果为访问过
            {
                std::cout << i << " "; //访问
                visted[i] = true;      //访问标记
                Q.push(i);             //入队
            }
            p = p->next; //p指向下一个邻接顶点
        }
    }
}

void BFStraverse(graph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visted[i] = false;
    }
    for (int i = 0; i < G.vexnum; i++)
    {
        if (!visted[i])
            BFS(G, i);
    }
}

void DFS(graph G, int v)
{                      //DFS的非递归算法
    std::stack<int> S; //栈s
    S.push(v);         //顶点v入栈
    visted[v] = true;
    Arcnode *p = G.vertex1[v].first; //p指向第一条边
    while (!S.empty())               //栈不空时
    {
        int k = S.top();                         //读取栈顶顶点
        S.pop();                                 //栈顶顶点出栈
        std::cout << G.vertex1[k].data << "-"; //访问栈顶顶点
        Arcnode *p = G.vertex1[k].first;         //栈顶顶点的第一条边
        while (p)                                //将顶点k的邻接未访问顶点全部入栈
        {
            int i = p->adjvex; //顶点k的邻接顶点编号
            if (!visted[i])
            {
                S.push(i);        //将顶点k的未访问过的邻接顶点入栈
                visted[i] = true; //访问标记
            }
            p = p->next; //下一条边
        }
    }
}
void DFStraverse(graph G)
{
    for (int i = 0; i < G.vexnum; i++)
    {
        visted[i] = false;
    }
    for (int v = 0; v < G.vexnum; v++)
    {
        if (!visted[v])
            DFS(G, v);
    }
}


void dijistra(graph G,int v)
{
    //最短路径问题
    bool s[maxvertex];  //s为标记数据，
    int dist[maxvertex];
    int path[maxvertex];
    for(int i=0;i<maxvertex;i++)
    {
        dist[i]=INT_MAX;    //初始化边为∞
        s[i]=false;     //初始化
        path[i]=-1;     
    } 
    Arcnode *p=G.vertex1[v].first;    //p指向顶点v的边
    s[v]=true;  //顶点v加入s集
    path[v]=-1;
    dist[v]=0;
    int k;
    int u=v;
    for(int i=0;i<G.vexnum;++i)     //
    {
        int min=INT_MAX;        
        while(p!=NULL){
            k=p->adjvex;
            if(s[k]!=true&&dist[u]+p->weigtht<dist[k]){     
                dist[k]=dist[u]+p->weigtht;
                path[k]=u;
            }
            p=p->next;
        }
        int max=INT_MAX;
        for(int j=0;j<G.vexnum;++j){
            if(dist[j]>0&&dist[j]<max&&s[j]==false){        //找到最近的邻接顶点
                max=dist[j];
                u=j;    //u指向最近的顶点
            }
        }
        s[u]=true;  //放问标记
        p=G.vertex1[u].first;   //p指向最近顶点的邻接边
    }   //至此已找到顶点v到其他结点的所有最短路径。
    for(int i=0;i<G.vexnum;i++){
        std::cout<<v<<" to v"<<i<<" is "<<dist[i]<<" ";
    }
}

int main()
{
    graph G;
    int n = 9;
    initiate(G);
    add_vertex(G, n);
    int num, to;
    int weight = 1;
    /*     for(num=0,to=1;num<n;num++,to++)
    {
        add_arc(G,num,to,weight);   //默认图为1→2→3→4→5→6
    }  */
    add_arc(G, 0, 1, 5);
    add_arc(G, 0, 3, 2);
    add_arc(G, 0, 4, 1);
    add_arc(G, 0, 2, 10);
    add_arc(G, 3, 6, weight);
    add_arc(G, 6, 4, weight);
    add_arc(G, 4, 1,3);
    add_arc(G, 4, 7, weight);
    add_arc(G, 7, 5, weight);
    add_arc(G, 5, 8, weight);
    add_arc(G, 5, 2, weight);
    for(int i=0;i<8;++i){
        dijistra(G,i);
        std::cout<<std::endl;
    }
   // dijistra(G,0);
    //   BFStraverse(G);
    DFStraverse(G);
    system("pause");
    return 0;
}
