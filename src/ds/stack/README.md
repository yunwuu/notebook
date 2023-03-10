# 栈

## 定义
1. 栈是限定只在表尾进行插入或删除操作的**线性表**。
2. 栈的尾端称为**栈顶**，头部称为**栈底**。
3. 栈通常被称为是后进先出（`last in first out`）表，简称 `LIFO` 表。

## 表示
### 顺序表示（顺序栈）
1. 栈的顺序存储结构是利用一组地址连续的存储单元，**依次**存放自**栈底**到**栈顶**的数据元素，设 **指针`top`** 指示栈顶的位置。
2. 栈在使用过程中占用的空间难以估计，为了防止空间不足且尽可能节省空间，应当**事先分配一个基本容量，然后在应用过程中，若栈空间不足，再进行逐段扩大**。
3. 顺序栈主要有两个指针：栈底指针`base`和栈顶指针`top`。`base`在顺序栈中始终不变，因此`base`为NULL则表示栈结构**不存在**。`top`一开始指向`base`，可以作为判断**空栈**的方法。**非空栈中的栈顶指针始终在栈顶元素的下一个位置上。**

**初始化栈和按需扩容的实现：**
```c
#define STACK_INIT_SIZE 100 // 栈的初始容量
#define STACK_INCREASEMENT 10 // 栈的扩容增量

typedef struct {
    ElemType *base;
    ElemType *top;
    int size;
}SqStack;


Status InitStack(SqStack &s) {
    s.base = (ElemType *)malloc(STACK_INIT_SIZE * sizeof(ElemType)); // 分配初始空间
    if(!s.base) {
        // 分配空间失败
        return ERROR;
    }
    s.top = s.base; 
    s.size = STACK_INIT_SIZE;
    return OK;
}
```

**追加元素：**
```c
Status Push(SqStack &s, ElementType e) {
    if(s.top - s.base >= s.size) {
        // 栈满 需要追加存储空间
        s.base = (ElemType *)realloc(s.base, (s.size + STACK_INCREASEMENT) * sizeof(ElemType));
        if(!s.base) // ...
        s.top = s.base + s.size;
        s.size += STACK_INCREASEMENT;
    }
    *s.top++ = e; 
    // i++为先运算后自增
    // top指针在栈顶元素的下一个位置上 所以直接写入该位置 然后移动top指针
    return OK;
}
```



**获取栈顶元素：**
```c
Status GetTop(SqStack &s, ElemType &e) {
    // 判断是否为空栈
    if(s.base == s.top) {
        return ERROR;
    }
    e = *(s.top-1); // 返回栈顶元素 注意top指针指向的位置和栈顶元素的关系
    return OK;
}
```


## 应用
### 数制转换
输入一个非负十进制整数，输出等值的八进制数：
```c
void conversation() {
    // s = ..., N = ...
    InitStack(s); // 初始化栈s
    scanf("%d", N);
    while(N) {
        Push(S, N % 8); // 入栈
        N /= 8;
    }
    while(!StackEmpty(s)) {
        // e = ...
        Pop(S, e); // 出栈
        printf("%d", e);
    }
}
```

### 递归
栈的一个重要应用是在程序设计语言中实现**递归**。一个**直接调用自己**或通过一系列语句间接调用自己的函数，称为递归函数。


## C语言实现
[Gist](https://gist.github.com/yunwuu/1c37f910b3d270d8d8397dffbe087de0)