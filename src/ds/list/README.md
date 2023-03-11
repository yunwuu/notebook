# 线性表

## 定义

1. 线性表是最常用且最简单的一种数据结构。
2. 线性表是n个数据元素的有限序列。
3. 若将线性表记为 $(a_1, ..., a_{i-1}, a_i, a_{i+1}, ..., a_n)$, 则称： $a_{i-1}$ 是 $a_i$ 的**直接前驱**，  $a_{i+1}$ 是 $a_i$ 的**直接后继**。
4. $a_i$ 是线性表的第 $i$ 个数据元素， $i$ 称为 $a_i$ 在线性表中的位序。
5. 线性表可以 [顺序表示](#顺序表示) 和 [链式表示](#链式表示) 。

## 顺序表示

1. 线性表的顺序表示指的是用**一组地址连续的存储单元依次存储线性表的数据元素**。
2. 线性表的第i个数据元素 $a_i$ 的存储位置为： $LOC(a_i) = LOC(a_1) + (i - 1) * l$ ， 其中 $l$是每个元素占用的存储单元的个数。
3.  $LOC(a_1)$ 是线性表第一个数据元素的存储位置，称为线性表的起始位置或**基地址**。
4. 只要确定了存储线性表的起始位置，线性表任何一个数据元素都可以**随机读取**，即线性表的顺序存储结构是一种随机存取的存储结构。
5. 高级语言中的数组类型也有随机存取的特性，因此通常用数组来描述数据结构中的顺序存储结构。
6. 线性表的长度是灵活可变的，因此在具体实现中，空间的分配应当是动态的，由问题而决定的。
7. C语言的下标是从0开始，而”第n个元素“的描述中`n`从1开始。


### 线性表动态分配顺序结构的实现
```c
#define LIST_INIT_SIZE 100 // 线性表存储空间的初始分配量
#define LIST_INCREASEMENT 10 // 线性表存储空间的分配增量
typedef struct {
	ElemType *elem; // 存储空间基址
	int length; // 当前长度
	int listsize; // 当前容量(也就是最长长度)
}SqList;
```

### 线性表初始化
```c
Status Init_SqList(SqList &L) {
	L.elem = (ElemType *)malloc(LIST_INIT_SIZE * sizeof(ElemType));
	if(!L.elem) exit(OVERFLOW);
	L.length = 0;
	L.listsize = LIST_INIT_SIZE;
	return OK;
}
```

### 线性表插入元素
在线性表`L`的第`i`个位置之前插入元素`e`：

```c
Status SqList_Insert(SqList &L, int i, ElemType e) {
	if(i < 1 || i > L.length + 1) return ERROR; // i的值无效
	// 确认存储空间是否已满
	if(L.length >= L.listsize) {
		// 当前存储空间已满 需要增加分配
		newbase = (ElemType *)realloc(L.elem, (L.listsize + LIST_INCREASEMENT) * sizeof(ElemType));
		if(!newbase) exit(OVERFLOW); // 空间不足
		L.elem = newbase; // 更新基地址
		L.listsize += LIST_INCREASEMENT; // 更新listsize
	}
	q = &(L.elem[i-1]); // 插入位置的地址
	for(p=&(L.elem[L.length-1]); p>=q; p--) {
		// q以及后面的元素向后移动
		*(p+1) = *(p);
	}
	*q = e;
	L.length++;
	return OK;
}
```
思路：
1. 确定`i`的值有效。
2. 确定存储空间是否可以容纳`L.length+1`个元素。如果不够，重新分配足够的存储空间，更新基地址和`listsize`。
3. 找到插入位置`q`。
4. 从表的尾部开始，逐个将元素后移，直到`q`的位置。
5. 将`e`赋给`*q`， `L.length`加一，插入完成。

### 线性表删除元素
在线性表`L`中删除第`i`个元素，并用`e`返回它的值：
```c
Status SqList_Delete(SqList &L, int i, ElemType e) {
	if(i < 1 || i > L.length) return ERROR;
	p = &(L.elem[i-1]); // 被删除的位置
	e = *p;
	q = &(L.elem[L.length-1]); // or: L.elem + L.length - 1
	for(++p; p<=q; ++p) {
		*(p-1) = *(p); // 后面的元素左移
	}
	L.length--;
	return OK;
}
```
思路：
1. 确定`i`的值有效。
2. 找到被删除的位置，将其值写入`e`。
3. 找到表尾元素`q`的位置。
4. 从被删除的元素后一位开始，逐个左移一位。
5. `L.length`减一， 删除完成。


## 链式表示

线性表的链式存储结构不需要逻辑上相邻的元素存储在相邻的物理位置上，不可随机存取。