# 图的遍历

## 深度优先搜索
1. 设 `visited` 数组，记录每个顶点是否被访问过。
2. 假设所有顶点均未被访问过，开始遍历。
3. 找一个顶点 $v_i$ ， 访问该顶点，然后依次访问其未被访问过的邻接点，以此出发深度优先搜索图。
4. 直到途中所有和 $v_i$ 邻接的顶点都被访问到。
5. 如果图还有未被访问的顶点，从步骤3再次开始。
6. 直到所有顶点都被访问到为止。


```c
#define bool int
#define true 1
#define false 0
#define MAX 100


bool visited[MAX]; // 记录顶点是否被访问过

void DFSTraverse(Graph *g) {
    for(int v=0; v<g->vexnum; v++) {
        visited[MAX] = false; // 初始化visited数组
    }
    for(int v=0; v<g->vexnum; v++) {
        DFS(g, v); 
    }
}

void DFS(Graph *g, int v) {
    visited[v] = true; // 标记为访问过
    // visit(v) 对顶点进行访问
    for(int w = FirstAdjVertex(g, v); w>=0; w = NextAdjVertex(g, v, w)) {
        // 获取邻接顶点 并调用DFS
        if(!visited[w]) DFS(g, w);
    }
}
```

从代码上来看，图的深度优先搜索和树的先序遍历类似，不同的是：
1. 图可能存在环/回路，要设`visited`数组。
2. 若为**非连通图**，从一个顶点出发递归调用`DFS`函数**不能**遍历得到全部顶点，因此还需要`DFSTraverse`函数，确保`visited`数组最后全部被设为`true`，否则对该点调用`DFS`函数。即如下语句：
```c
for(int v=0; v<g->vexnum; v++) {
    DFS(g, v); 
}
```

### 复杂度
遍历图耗费的时间取决于存储结构：

（**BFS/DFS时间复杂度=访问各结点需要的时间+探索所有边需要的时间**）

1. 邻接矩阵： $O(n^2)$
2. 邻接表： $O(n+e)$
空间复杂度： 最好 $O(1)$ 最坏 $O(\mid V \mid)$。


## 广度优先搜索
1. 设 `visited` 数组，记录每个顶点是否被访问过。
2. 假设所有顶点均未被访问过，开始遍历。
3. 从顶点 $v_i$ 出发。
4. 依次访问 $v_i$ 所有未曾访问的邻接点。
5. 分别从步骤2中的邻接点依次访问各自的邻接点。
6. 如果尚有未被访问的，另 $v_j$ ， 从步骤3开始。
7. 直到全部顶点都被访问到。

```c
void BFSTraverse(Graph *g) {
    for(int v=0; v<g->vexnum; v++) visited[v] = false; // 初始化visited数组
    InitQueue(q); // 初始化队列Q
    for(int v=0; v<g->vexnum; v++) {
        visited[v] = true;
        // visit(v) here...
        Enqueue(q, v); // 入队
        while(!QueueEmpty(q)) {
            Dequeue(q, u); // 出队
            // 遍历邻接点
            while(int w=FirstAdjVex(g, u), w>=0; w=NextAdjVex(g, u, w)) {
                if(!visited[w]) {
                    visited[w] = true;
                    // visit(w)...
                    Enqueue(q, w); // 入队
                }
            }
        }
    }
}
```

### 复杂度
与深度优先搜索相同。