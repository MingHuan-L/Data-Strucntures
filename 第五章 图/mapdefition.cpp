
#define maxvertexnum 100
//邻接矩阵法：
typedef char vertextype;
typedef int edgetpye;
typedef struct{
    vertextype vex[maxvertexnum];   //顶点表
    edgetpye edge[maxvertexnum][maxvertexnum];  //邻接矩阵，边表
    int vexnum,arcnum;  //图当前的顶点数和弧数
}gragh;




//邻接表法
typedef struct ArcNode{     //边表结点
    int ajvex;          //该弧所指向顶点的位置
    struct AcrNode *next;   //指向下一条弧的指针
    int weight;         //该边的权重
}ArcNode;

typedef struct VNode{       //顶点表信息
    vertextype data;    //结点的数据域
    ArcNode *first;     //指向第一条依附该顶点的弧的指针
}VNode,AdjList[maxvertexnum];   //顶点结点，顶点表

typedef struct{
    AdjList vertices;     //顶点邻接表
    int vexnum,arcnum;     //图的顶点数和弧数
}Algraph;   //图的邻接表

