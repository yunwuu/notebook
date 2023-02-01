#define OVERFLOW 1
#define ERROR 2

#include <stdlib.h>
#include <stdio.h>


// 存储结构实现
struct QNode {
    int data;
    struct QNode *next;
};


typedef struct QNode QNode, *Qptr;


typedef struct {
    Qptr front;
    Qptr rear;
}LinkQueue, *LQptr;


// 基本操作函数实现
void InitQueue(LQptr q) {
    q->front = q->rear = (Qptr)malloc(sizeof(QNode));
    if(!q->front) exit(OVERFLOW);
    q->front->next = NULL;
}


void Enqueue(LQptr q, int e) {
    Qptr p = (Qptr)malloc(sizeof(QNode));
    if(!p) exit(OVERFLOW);
    p->data = e;
    p->next = NULL;
    q->rear->next = p;
    q->rear = p;
}


void Dequeue(LQptr q, int *e) {
    if(q->front == q->rear) exit(ERROR);
    Qptr p = q->front->next;
    *e = p->data;
    q->front->next = p->next; // 修改头指针指向的结点到p的next以断开连接
    // 重要！ 在释放p前 注意如果p恰是队尾 需要重新赋值rear 否则rear丢失
    if(p == q->rear) {
        q->rear = q->front;
    }
    // 释放
    free(p);
}


void DestroyQueue(LQptr q) {
    while(q->front) {
        q->rear = q->front->next;
        free(q->front);
        q->front = q->rear;
    }
}


int main() {
    LinkQueue q;
    InitQueue(&q);
    Enqueue(&q, 30);
    int e;
    Dequeue(&q, &e);
    printf("%d", e);
    DestroyQueue(&q);
    return 0;
}