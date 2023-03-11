# 二叉树
## 定义
1. 二叉树的特点是每个结点**至多**只有两棵子树。
2. 二叉树是**有序**的，即子树左右**不能颠倒**。


## 性质
二叉树有许多重要的性质。
1. 二叉树的第 $i$ 层上至多有 $2^{i-1}$ 个结点。
2. 深度为 $k$ 的二叉树至多有 $2^k-1$ 个结点。
3. 设二叉树叶子结点数量为 $n$ ，**度为2的结点**为 $k$ ， 则 $n = k + 1$ 。
4. **满二叉树**：深度为 $k$ 且有 $2^k-1$ 个结点的二叉树。（每一层结点数都是最大）
5. **完全二叉树**：对满二叉树的结点连续编号，**自根节点起，从上而下，从左而右**。对于一个深度为 $k$ ， $n$ 个结点的二叉树，当且仅当其每一个结点都和深度为 $k$ 的满二叉树按编号一一对应时，称为完全二叉树。完全二叉树的**叶子结点只可能在完全二叉树层次最大的两层出现**。
6. 有 $n$ 个结点的完全二叉树的深度为 $\lfloor{log_2n}\rfloor + 1$


## 表示
### 顺序表示
```c
#define MAX_TREE_NODES 100
// typedef简化数组写法 => SqBinaryTree = ElemType SqBinaryTree[n]
typedef ElemType SqBinaryTree[MAX_TREE_NODES]; 
SqBinaryTree t;
```

1. 顺序存储结构中，用一组地址连续的存储单元，按照从上到下，从左到右的顺序存储二叉树上的结点元素。存储时要按照**完全二叉树**的结构排序，如果对应位置没有结点，则用0代替。
2. 显然，完全二叉树更适合使用顺序存储结构，而一般二叉树不适合。最坏情况下，一个深度为 $k$ 且只有 $k$ 个结点的树（每个结点都最多只有一个孩子结点）需要长度为 $2^k-1$ 的数组。


### 链式表示
```c
typedef struct BinaryTreeNode {
    ElemType data;
    struct BinaryTreeNode *lchild, *rchild;
}BinaryTreeNode, *BinaryTree;
```

二叉树的链表中的结点至少包含三个域：数据元素，左指针，右指针；还可以包含指向双亲的指针。

## 遍历二叉树
遍历二叉树，指的是以某种路径访问树中的全部结点。按照路径规律的不同，分别有三种情况：**先序遍历**，**中序遍历**，**后序遍历**。

三者的区别在于**访问根节点的时机**：
1. 先序遍历： 访问根节点 → 遍历左子树 → 遍历右子树
2. 中序遍历： 遍历左子树 → 访问根节点 → 遍历右子树
3. 后序遍历： 遍历左子树 → 遍历右子树 → 访问根节点


### 递归实现
二叉树的定义类似于一种递归的概念，因此显然对二叉树的遍历也可以用**递归**的思想来实现。

#### 代码
先序遍历：
```c
Status visit(ElemType e) {
    // 访问这个结点的函数 在这里实现需要的逻辑
    if(!e) {
        return ERROR;
    }
    printf(e); // 比如输出这个元素
    return OK;
}

Status PreOrderTraverse(BinaryTree T) {
    if(!T) {
        // 递归的终止情况
        return OK;
    } else {
        // 递归的主逻辑
        if(visit(T->data)) {
            Status left = PreOrderTraverse(T->lchild); // 遍历左子树
            if(left) {
                Status right = PreOrderTraverse(T->rchild); // 遍历右子树
                if(right) {
                    return OK;
                }
            }
            return ERROR;
        }
    }
}
```



类似的，主逻辑中访问结点的时机稍作改变，即可得到中序遍历和后序遍历的递归实现。

### 迭代实现
递归实际上是隐式维护了一个栈，而迭代实现中将显式表达出一个栈来访问树中的所有结点。

#### 代码
中序遍历：
```c
Status InOrderTraverse(BinaryTree T) {
    InitStack(stk); 
    node = T;
    while(node || !StackEmpty(stk)) {
        if(node) {
            Push(stk, node); // 结点入栈
            node = node->lchild; // 遍历左子树
        } else {
            Pop(stk, node); // 出栈
            if(!visit(node->data)) {
                // 访问结点
                return ERROR;
            }
            node = node->rchild; // 遍历右子树
        }
    }
    return OK;
}

```