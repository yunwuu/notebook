#define OVERFLOW 1
#define ERROR 2
#define MAX_QUEUE_SIZE 100

#include <stdlib.h>
#include <stdio.h>


// 循环队列存储结构实现
typedef struct {
    int *base;
    int front;
    int rear;
}SqQueue, *SqQptr;


// 基本操作函数实现
void InitQueue(SqQptr q) {
    // 构造空队列
    q->base = (int*)malloc(MAX_QUEUE_SIZE * sizeof(int));
    if(!q->base) exit(OVERFLOW);
    q->front = q->rear = 0; // 起始指针指向0位置
}


int QueueLength(SqQptr q) {
    // 计算队列的长度
    return (q->rear - q->front + MAX_QUEUE_SIZE) % MAX_QUEUE_SIZE;
}


void Enqueue(SqQptr q, int e) {
    // 入队
    if((q->rear+1)%MAX_QUEUE_SIZE == q->front) exit(ERROR); //队列满
    q->base[q->rear] = e;
    q->rear = (q->rear + 1) % MAX_QUEUE_SIZE;
}


void Dequeue(SqQptr q, int *e) {
    // 出队
    if(q->front == q->rear) exit(ERROR); 
    *e = q->base[q->front];
    q->front = (q->front + 1) % MAX_QUEUE_SIZE;
}


int main() {
    SqQueue q;
    InitQueue(&q);
    Enqueue(&q, 20);
    Enqueue(&q, 50);
    int len = QueueLength(&q);
    printf("Length=%d\n", len);
    int e;
    Dequeue(&q, &e);
    printf("%d\n", e);
    Dequeue(&q, &e);
    printf("%d\n", e);
    return 0;
}