bool visited[_INTEGRAL_MAX_BITS];   //访问标记数组
void DFStraverse(Graph G){
    for(v=0;v<G.vexnum;++v)
        visited[v]=false;
    for(v=0;v<G.vexnum;++v)
        if(!visited[v])
            DFS(G,v);
}

void DFS(Graph G,int v)
{
    visit(V);       //访问顶点v
    visited[v]=true;
    for(w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
        if(!visited[w])     //w未u的尚未访问的邻接结点
            DFS(G,w);
}