# 图的存储

## 数组表示法（邻接矩阵）

用两个数组分别存储数据元素的信息和数据元素之间的关系（边或弧）的信息。
```c
#define MAX_VERTEX 20 // 最大顶点个数


typedef enum {DG, DN, UDG, UDN} GraphTypes; // 枚举不同类型的图：有向图 有向网 无向图 无向网
typedef struct ArcCell {
    VRType adj; // 表示顶点关系。 带权图为权值，无权图用0或1表示是否相邻。
    InfoType *info; 
}ArcCell, AdjMatrix[MAX_VERTEX][MAX_VERTEX];

typedef struct {
    VertexType vexs[MAX_VERTEX]; // 顶点向量
    AdjMatrix arcs; // 邻接矩阵
    int vexnum; // 顶点数
    int arcnum; // 弧数
    GraphType type; // 图的类型
}Graph;
```


对于无向图，顶点 $v_i$ 显然就是邻接矩阵中第 $i$ 行（或列）的元素之和：

$$TD(v_i)=\sum_{j=0}^{n-1}A[i][j] (n = MAX\_VERTEX)$$

对于有向图， 入度是列的和，出度是行的和。

同时，由于存在权值，不能只用0和1来标记边的关系。当边存在时，存储权值；当不存在时，存储`INT_MAX`（或其他不可能出现的权值）。

### 性质
1. 复杂度： 空间 $O({\mid V \mid}^2)$ 时间 $O(\mid V \mid)$
2. 适合稠密图。稀疏图会造成浪费。
3. 无向图由于邻接矩阵对称，可以压缩存储。
4. 邻接矩阵相乘： 如 矩阵 $A$ 则：
    1.  $A^2[1][4] = a_{11}a_{14} + a_{12}a_{24} + a_{13}a_{34} + a_{14}a_{44} = 1$
    2. 表示： 从A(`pos=1`)到D(`pos=4`) 的 长度为2的路径有 **1** 条。
    3. $A^n[M][N]$... 同理， 结果为由$M$到$N$长度为 $n$ 的路径。


### 算法
#### 构造图
```c
Status CreateGraph(Graph *g) {
    printf("Input graph type:");
    scanf(g->GraphType);
    switch(g->GraphType) {
        case DG: return CreateDG(g);
        // case DN...
        // case UDG...
        // case UDN...
    }
}
```

构造无向网UDN:
```c
Status CreateUDN(Graph *g) {
    scanf(&g->vexnum, &g->arcnum, &IncInfo);
    for(int i=0; i<g->vexnum; i++) {
        scanf(&g->vexs[i]); // 构造顶点向量
    }
    for(int i=0; i<g->vexnum; i++) {
        // 初始化邻接矩阵
        for(int j=0; j<g->vexnum; j++) {
            g->arcs[i][j] = {INT_MAX, NULL}; 
        }
    }
    for(int k=0; k<g->arcnum; k++) {
        // 构造邻接矩阵
        scanf(&v1, &v2, &w); // 边的两个顶点v和权值w
        v1_pos = LocateVertex(g, v1);
        v2_pos = LocateVertex(g, v2);
        g->arcs[v1_pos][v2_pos].adj = w; // 写入权值
        if(IncInfo) {
            *g->arcs[i][j].info = IncInfo;
        }
        g->arcs[j][i] = g->arcs[i][j]; // 无向图的对称弧
    }
    return OK;
}
```


## 邻接表

对图中每个顶点建立一个**单链表**，第 $i$ 个链表表示依附于顶点 $v_i$ 的边或有向图中以 $v_i$ 为尾的弧。

结点包含三个域：`adjvex`（邻接点域） `nextarc`（指示下一条边/弧） `info`。

表头结点： 包含`data` `firstarc`。

```c
#define MAX_VERTEX 20

typedef struct ArcNode {
    int adjvex; // 指向的顶点位置
    struct ArcNode *nextarc; // 下一个边/弧
    InfoType *info;
}ArcNode;
typedef struct VNode {
    VertexType data; // 顶点信息
    ArcNode *firstarc;
}VNode, AdjList[MAX_VERTEX];
typedef struct {
    AdjList vertices;
    int vexnum;
    int arcnum;
    GraphType type;
}ALGraph; // 邻接表声明
```

若无向图中有 $n$ 个顶点， $e$ 条边，则邻接表需要 $n$ 个头结点 和 $2e$ 个表结点。 当图稀疏，邻接表表示更节省空间。

但是如果要判断任意两个顶点 $v_i$ 和 $v_j$ 是否有边或弧相连，则需要搜索两个链表，不及邻接矩阵方便。

### 逆邻接表

在无向图的邻接表中，顶点 $v_i$ 所对应的第 $i$ 个链表中结点的个数显然恰好是顶点 $v_i$ 的**度**。但对于有向图来说， 对应链表的结点个数只是顶点的**出度**。 如果要求入度，必须遍历整个邻接表。因此，如果需要确认顶点的入度或以顶点 $v_i$ 为头的弧， 可以建立逆邻接表，对每个顶点 $v_i$ 建立链接以 $v_i$ 为头的弧的表。


### 复杂度
如果输入的顶点信息就是顶点的编号，建立邻接表的时间复杂度为 $O(n+e)$ ；如果表示，要通过查找才能得到顶点在图中的位置，时间复杂度为 $O(n*e)$ 。


## 十字链表
十字链表是有向图的另一种链式存储结构，可以看作邻接表和逆邻接表的结合。

十字链表表示中，对于图的每条弧和顶点都各设一个结点。

1. 弧结点： `tailvex` `headvex` 指向尾和头顶点在图中的位置； `hlink` `tlink` 指向弧头/弧尾相同的下一条弧。 `info`指向弧信息。
2. 顶点结点： `data`存储相关信息； `firstin` `firstout` 指向以该顶点为弧头/弧尾的第一个**弧结点**。

```c
#define MAX_VERTEX 20

typedef struct ArcBox {
    int tailvex, headvex;
    struct ArcBox *hlink, *tlink;
    InfoType *info;
}ArcBox;
typedef struct VexNode {
    VertexType data;
    ArcBox *firstin, *firstout;
}VexNode;
typedef struct {
    VexNode xlist [MAX_VERTEX];
    int vexnum;
    int arcnum;
}OLGraph;
```

### 算法
#### 构造图
```c
Status CreateDG(OLGraph *g) {
    scanf(&g->vexnum, &g->arcnum, &IncInfo);
    for(int i=0; i<g->vexnum; i++) {
        scanf(&g->xlist[i]->data); // 输入顶点值
        g->xlist[i].firstin = NULL;
        g->xlist[i].firstout = NULL; // 初始化firstin firstout
    }
    for(int j=0; j<g->arcnum; j++) {
        scanf(&v1, &v2); // 弧的头和尾
        int v1_pos = LocateVertex(g, v1), v2_pos = LocateVertex(g, v2);
        ArcBox *p = (ArcBox *)malloc(sizeof(ArcBox)); // 构造弧结点
        if(!p) // ...
        *p = {v1_pos, v2_pos, g->xlist[v2_pos]->firstin, g->xlist[v1_pos]->firstout, NULL}; // 赋值
        g->xlist[v2_pos].firstin = g->xlist[v1_pos].firstout = p;
        if(IncInfo) // ...
    }
}
```

## 邻接多重表
邻接多重表是无向图的另一种链式存储结构。

邻接多重表也设边结点和顶点结点：
1. 边结点： `mark`标志改边是否被搜索过； `ivex` `jvex`表示边依附的两个顶点的位置； `ilink` `jlink`指向下一条依附于`ivex`/`jvex`的边，`info`为信息的指针域。
2. 顶点结点： `data`存储顶点信息， `firstedge`指示第一条依附于该顶点的边。

```c
#define MAX_VERTEX 20
typedef enum {unvis, vis}ifVis; // 访问标记

typedef struct EBox {
    ifVis mark;
    int ivex, jvex; // 顶点位置
    struct EBox *ilink, *jlink; 
    InfoType *info;
}EBox;
typedef struct VexBox {
    VertexType data;
    EBox *firstedge;
}VexBox;
typedef struct {
    VexBox adjmulist[MAX_VERTEX];
    int vexnum, edgenum; // 顶点和边的数量
}AMLGraph;
```