# 队列
## 定义
1. 队列和栈相反，是一种**先进先出表**。
2. 队列只允许在表的一端插入，在另一端删除。最早进入队列的元素最早离开。
3. 允许插入的一端是**队尾**（rear），允许删除的一端是**队头**（front）。


## 表示
### 链式表示（链队列）
**单链队列的实现：**
```c
typedef struct QNode {
    ElemType data;
    struct QNode *next;
}QNode, *Queue;

typedef struct {
    Queue front; // 队头指针
    Queue rear; // 队尾指针
}LinkQueue;
```

**删除队头元素的实现：**
```c
Status Dequeue(LinkQueue &q, ElemType &e) {
    if(q.front == q.rear) {
        // 空队列
        return ERROR;
    }
    p = q.front->next;
    e = p->data;
    q.front->next = p->next;
    if(q.rear == p) {
        // 如果删除的是队列中最后一个元素 则重新赋值rear指针 否则会随着释放p而释放
        q.rear = q.front;
    }
    free(p);
    return OK;
}
```

**插入元素的实现：**
```c
Status Enqueue(LinkQueue &q, ElemType e) {
    p = (Queue)malloc(sizeof(QNode));
    if(!p) {
        // ...
        return ERROR;
    }
    p->data = e;
    p->next = NULL;
    q.rear->next = p; // 队尾元素next指向p
    q.rear = p; // 将p设为队尾元素
    return OK;
}
```

### C语言实现
[Gist](https://gist.github.com/yunwuu/35f1fcbecdcabcbc372a87693ec9b79a)


### 顺序表示（循环队列）
1. 顺序队列使用一组连续的地址存放队头到队尾的元素，用指针`front`和`rear`指示队头和队尾的位置。
2. 和栈不同，当到达存储空间边际时，队列的空间往往还没有占满（甚至可能是空的），此时不应分配更大的空间。巧妙的做法是将队列看作**环状**的空间，称之为循环队列。
3. 循环队列下`front`和`rear`指针的位置关系无法指示队列是否已满，因此可以设标志位来标记，或少使用一块空间，该空间不用于存放元素，约定队列`front`指针在`rear`指针的“下一位置”（环状状态下）时代表队列已满。

**循环队列的实现：**
```c
#define MAX_SIZE 100 // 最大队列长度
typedef struct {
    ElemType *base; 
    int front;
    int rear;
}SqQueue;

Status InitQueue(SqQueue &q) {
    q.base = (ElemType *)malloc(MAX_SIZE * sizeof(ElemType));
    if(!q.base) // ...
    q.front = q.rear = 0;
    return OK;
}
```

**获取队列的长度：**
```c
int QueueLength(SqQueue q) {
    return (q.rear - q.front + MAX_SIZE) % MAX_SIZE;
}
```

**插入元素：**
```c
Status Enqueue(SqQueue &q, ElemType e) {
    if((q.rear + 1) % MAX_SIZE == q.front) {
        // 队列满
        return ERROR;
    } 
    q.base[q.rear] = e;
    q.rear = (q.rear + 1) % MAX_SIZE;
    return OK;
}
```
**注意：在`q.front=q.rear`时，有两种可能的情况：队列空或队列满。因此，通常可以空出一块区域，即当`q.rear+1=q.front`视作队列满的标志。或者，另设标志位记录队列是否为空。上述代码使用了前者的方法。**



**删除元素：**
```c
Status Dequeue(SqQueue &q, ElemType &e) {
    if(q.front == q.rear) // ...
    e = q.base[q.front]; 
    q.front = (q.front + 1) % MAX_SIZE; 
    return OK;
}
```
同上，因为采用了少用一块空间的方法来区分队列的状态，因此`q.front=q.rear`即为队列满的标志。

### C语言实现
[Gist](https://gist.github.com/yunwuu/a7ed982197d6af828a9d037b7c9d597f)