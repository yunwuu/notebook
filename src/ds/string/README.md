# 字符串

## 定义
1. 字符串是由零个或多个字符组成的有限序列。
2. 字符串有很多特殊的操作，如`strcpy`, `concat`, `substring`等。

## 表示
### 定长顺序存储表示
```c
#define MAX_STRLEN 255
typedef unsigned char SString[MAX_STRLEN + 1]; // SString[0] 存放字符串的长度
```


在C语言中，也可以直接使用`\0`来表示字符串的结束，但无法直接得到字符串的长度，在一些操作中可能有所不便。

C语言实现：[Gist](https://gist.github.com/yunwuu/3b122f08b01fb58e06a537a20bc3f1f5)

### 堆分配存储表示
```c
typedef struct {
    char *ch;
    int length;
}HString;
```

C语言实现： [Gist](https://gist.github.com/yunwuu/e77ac2600fa36dc4e0275e387ba04fa0)


### 块链存储表示
```c
#define CHUNK_SIZE 80
typedef struct chunk {
    char ch[CHUNK_SIZE];
    struct chunk *next;
}chunk;
typedef struct {
    chunk *head, *tail;
    int len;
}LString;
```


