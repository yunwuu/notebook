# 图的连通性
## 无向图的连通分量和生成树
1. 无向图中，对于连通图，从任意顶点出发遍历，就能得到整个图。
2. 对于非连通图，要从若干个顶点出发。
3. 设 $E(G)$ 是连通图中所有边的集合， 从一个顶点 $v$ 出发遍历， 得到两个集合 $T(G)$ 和剩余部分 $B(G)$。 $T(G)$ 和图G的所有顶点构成了连通图G的极小连通子图。 它是连通图的一棵**生成树**；由深度优先搜索得到的称为深度优先生成树，广度优先搜索得到的称为广度优先生成树。
4. 非连通图中，每个连通分量重的顶点和遍历时走过的边构成若干棵生成树，这些生成树构成生成**森林**。


```c
void DFSForest(Graph *g, CSTree *t) {
    // 建立无向图G的深度优先生成森林的孩子兄弟链表
    t = NULL;
    for(int v=0; v<g->vexnum; v++) {
        visited[v] = false; // 初始化
    }
    for(int v=0; v<g->vexnum; v++) {
        if(!visited[v]) {
            p = (CSTree)malloc(sizeof(CSNode)); // 分配树结点
            *p = {GetVex(g, v), NULL, NULL}; // 赋值
            if(!t) t = p; // 设为第一棵生成树的根节点
            else q->nextsbling = p; // 设为兄弟结点
            q = p;
        }
        DFSTree(g, v, p);
    }
}


void DFSTree(Graph *g, int v, CSTree *t) {
    // 从第v个顶点出发，深度优先遍历图G 建立以T为根的生成树
    visited[v] = true;
    first = true;
    for(int w=FirstAdjVertex(g, v); w>=0; w=NextAdjVertex(g, v, w)) {
        if(!visited[w]) {
            p = (CSTree)malloc(sizeof(CSNode)); // 分配孩子结点
            *p = {GetVex(g, w), NULL, NULL}; // 赋值
            if(first) {
                // 为左孩子赋值
                t->lchild = p;
                first = false;
            } else {
                // 为兄弟结点赋值
                q->nextsubiling = p;
            }
            q = p;
            DFSTree(g, w, q); // 从w出发遍历 生成子生成树q
        }
    }
}
```


## 有向图的强连通分量
::: info 等待完善

:::

## 最小生成树
参见 [最小生成树](/ds/graph/connection/mst/)