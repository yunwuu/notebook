# 最小生成树

现实意义： 假设一个城镇中有医院（A），住宅（B），超市（C）等等，在这些点之间修建道路，希望其中任何两点都可以通过道路抵达的前提下尽可能节省经费。 

修建道路对应的经费和道路的长度等因素有关，即和道路两端的点有关，因此把每一个地点视作图的顶点，之间（可以修建）的道路就视作**带权值**的边。由于只需要任两点**之间有路径**，因此选用生成树；又因为要尽可能节省经费，因此要构建连通网的**最小代价生成树** (Minimum Cost Spanning Tree)。


构建最小生成树的两个算法： 普利姆（Prim） 和 克鲁斯卡尔（Kruskal）。


## Prim
::: info 整体思路
从某个顶点开始构建最小生成树，每次将代价最小的顶点加入生成树，直到全部顶点加入生成树为止。
:::

定义辅助数组`closedge`：
```c
struct {
    VertexType adjvex;
    VRType lowcost; // 代价最小的边的权值。 VRType在无权图中用0/1表示边的存在性，在有权图中表示边的权值。
}closedge[MAX_VERTEX_NUM];
```
其中： $closedge[i-1].lowcost = Min{cost(u, v_i)}$。 `lowcost`随着生成树的变化也会发生变化。当顶点尚没有和生成树中的顶点相连的边时，`lowcost`的值为`INFINITY`。(即`adj`属性标记该边不存在)

算法：
```c
void MST_Prim(MGraph g, VertexType u) {
    // 从第u个顶点出发构建G的最小生成树
    k = LocateVertex(g, u);
    for(j=0; j<g.vexnum; j++) {
        // 初始化辅助数组
        if(j != k) {
            closedge[j] = {u, g.arcs[k][j].adj};
        }
    }
    closedge[0].lowcost = 0;
    for(i=1; i<g.vexnum; i++) {
        k = GetMinimum(closedge); // 求出生成树加入的下一个结点
        printf(closedge[k].adjvex, g.vexs[k]); // 输出生成树的边
        closedge[k].lowcost = 0;
        // 重新选择最小边
        for(j=0; j<g.vexnum; j++) {
            if(g.arcs[k][j].adj < closedge[j].lowcost) {
                closedge[j] = {g.vexs[k], g.arcs[k][j].adj};
            }
        }
    }
}
```


时间复杂度： $O({\mid V \mid}^2)$ 适合稠密图。


## Kruskal
::: info 整体思路
和Prim算法相反，Kruskal算法**每次选择权值最小的一条边**，若原本已连通则不选，直到所有结点连通。
:::

时间复杂度： $O(\mid E \mid log \mid E \mid)$ 适合稀疏图。