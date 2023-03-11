# 链表

## 单链表
线性链表，也称为单链表。

1. 线性表的链式存储结构是用一组**任意**存储单元存储线性表的数据元素。
2. 每个数据元素除了存储本身的信息之外，还需要存储一个指示其**直接后继**的信息。即包括两个**域**： **数据域** 和 **指针域**。
3. 链表的最后一个结点的指针为空（NULL）。
4. 可以在单链表的第一个结点前增加一个结点，称为**头结点**。这个结点的数据域可以没有信息，当然也可以用来存储线性表的长度等一些信息，而指针域指向第一个元素结点的存储位置。



### 单链表存储结构实现
```c
// 使用“结构指针”
typedef struct LNode {
    ElemType data;
    struct LNode *next;
}LNode, *LinkList;
```

### 单链表获取第i个元素的值的实现
从起始位置开始，不断访问`next`，直到计数器归零。
```c
Status GetElem(LinkList L, int i, ElemType &e) {
    p = L->next;
    j = 1;
    while(p != NULL && j < i) {
        p = p->next;
        j++;
    }
    if(!p || j > i) {
        // 没有第i个元素
        return ERROR;
    }
    e = p->data;
    return OK;
}
```
以上算法最坏情况下需要 $n$ 次才能找到结果，因此时间复杂度为 $O(n)$ 。

  
  

### 单链表插入元素的实现
从起始位置开始不断访问`next`，到要插入的位置，在它和它之前的一个结点中间创建一个新的结点，将前一个元素的`next`指向新结点，新结点指向原本前一个元素的`next`，并写入`data`到新结点中。
```c
Status ListInsert(LinkList &L, int i, ElemType &e) {
    p = L;
    j = 0;
    while(p != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if(!p || j > i - 1) {
        return ERROR;
    }
    s = (LinkList) malloc (sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return OK;
}
```

### 单链表删除元素的实现
```c
Status ListDelete(LinkList &L, int i, ElemType &e) {
    p = L;
    j = 0;
    while(p->next != NULL && j < i - 1) {
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i - 1) {
        return ERROR;
    }
    q = p->next;
    p->next = q->next;
    e = q->data;
    free(q); // 释放空间
    return OK;
}
```

### C语言实现
[Gist](https://gist.github.com/yunwu528491/f0b96819d99553c481741fe53887072c)

## 双向链表
1. 在单链表中，每个结点只能找到直接后继的结点，而无法找到直接前驱的结点。单链表寻找下一个结点的时间复杂度为 $O(1)$ ， 而寻找上一个结点的时间复杂度为 $O(n)$ 。
2. 双向链表的结点中有两个指针域，一个指向直接后继，另一个指向直接前驱。
3. 双向链表也可以循环。


### 双向链表存储结构实现
```c
typedef struct DuLNode {
    ElemType data;
    struct DuLNode *prior; // 指向直接前驱
    struct DuLNode *next; // 指向直接后继
}DuLNode, *DuLinkList;
```


## 循环链表
1. 循环链表的最后一个结点的指针域指向头结点。
2. 循环链表的任何一个结点出发均可找到表中其他结点。
3. 循环链表可以是多重链的。

