#include "队列/LinkQueue.cpp"


/*--- 结构体定义 ---*/
#define MaxVertexNum 100                //顶点数目的最大值
//图的领接矩阵存储结构定义
typedef char VertexType;                //顶点的数据类型
typedef int EdgeType;                   //带权图中边上权值的数据类型
typedef struct{
    VertexType  Vex[MaxVertexNum];       //顶点表
    EdgeType    Edge[MaxVertexNum][MaxVertexNum];   //领接矩阵，边表
    int         vexnum,arcnum;      //图的当前顶点数和弧数
}MGraph;

//图的领接表存储结构定义
typedef struct ArcNode{  //边表结点
    int adjvex; //该弧所指向的顶点的位置
    struct ArcNode *next;   //指向下一条弧的指针
    //InfoType info;        //网的边权值
}ArcNode;
typedef struct VNode{   //顶点表结点
    VertexType data;    //顶点信息
    ArcNode *first;     //指向第一条依附该顶点的弧的指针
}VNode,AdjList[MaxVertexNum];
typedef struct{
    AdjList vertices;   //领接表
    int vexnum,arcnum;  //图的顶点数和弧数
}ALGraph;   //ALGraph是以领接表存储的图类型
/*-----------------*/

/*--- 基本功能函数声明 ---*/
bool Adjacent(MGraph G,VertexType x,VertexType y);      //判断图G是否存在边<x,y>
void Neighbors(MGraph G,VertexType x);                  //列出图G中与结点x领接的边
bool InsertVertex(MGraph G,VertexType x);               //在图G中插入顶点x
bool DeleteVertex(MGraph G,VertexType x);               //从图G中删除顶点x
bool AddEdge(MGraph G,VertexType x,VertexType y);       //若边<x,y>不存在，则添加该边
bool ReMoveEdge(MGraph G,VertexType x,VertexType y);    //若边<x,y>存在，则删除该边
EdgeType Get_edge_value(MGraph G,VertexType x,VertexType y);            //获取图G中边<x,y>的权值
bool Set_edge_value(MGraph G,VertexType x,VertexType y,EdgeType v);     //设置图G中边<x,y>的权值为v
int FirstNeighbor(MGraph G,VertexType x);               //求图G中顶点x的第一个领接点，若有则返回顶点号，如没有则返回-1
int NextNeighbor(MGraph G,VertexType x,VertexType y);   //假设图G中顶点y是顶点x的一个领接点，返回除y外顶点x的下一个领接点的顶点号，
                                                        //若y为x的最后一个领接点，则返回-1
void visit(int x);   //访问结点                                                        
/*-----------------*/

//广度优先搜索BFS
LinkQueue Q;       //辅助队列
bool visited[MaxVertexNum];     //访问标记数组

void BFS(MGraph G,int v)        //从顶点v出发，广度优先遍历图G
{
    visit(v);                   //访问初始结点v
    visited[v] = true;          //标记已访问
    EnQueue(Q,v);               //顶点v入队列Q
    while(!IsEmpty(Q)){
        DeQueue(Q,v);           //顶点v出队列
        for(int w=FirstNeighbor(G,x);w>=0;w=NextNeighbor(G,v,w))    //检测v所有的领接点
        {
            if(!visited[w]) //w为v的未访问领接点
            {
                visit(w);
                visited[w] = true;    //对w做已访问标记
                EnQueue(Q,w);         //顶点w入队列
            }
        }
    }
}
void BFSTraverse(MGraph G){     //对图G进行广度优先遍历
    for(int i=0;i<G.vexnum;++i)
        visited[i] = false;     //访问标志数组初始化
    InitQueue(Q);               //初始化辅助队列Q
    for(int i=0;i<G.vexnum;++i) //从0号顶点开始遍历
    {
        if(!visited[i])         //对每个连通分量调用一次BFS,Vi未访问过，从Vi开始BFS
            BFS(G,i);
    }
}
/*-----------------*/

//深度优先搜索DFS
void DFS(MGraph G,int v)        //从顶点v出发，深度优先遍历图G
{
    visit(v);
    visited[v] = true;
    for(int w=FirstNeighbor(G,v);w>=0;w=NextNeighbor(G,v,w))
    {
        if(!visited[w]) //w为v的尚未访问的领接结点
            DFS(G,w);
    }
}
void DFSTraverse(MGraph G)  //对图G进行深度优先遍历
{
    for(int v=0;v<G.vexnum;++v)
        visited[v] = false;     //初始化已访问标记数据
    for(int v=0;v<G.vexnum;++v) //从0开始遍历
    {
        if(!visited[v])
            DFS(G,v);
    }
}
                                   






