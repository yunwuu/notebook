#define STACK_INIT_SIZE 100
#define STACK_INCREASEMENT 10


#include <stdio.h>
#include <stdlib.h>


typedef struct {
    int *base;
    int *top;
    int size;
} SqStack;


int InitStack(SqStack *s) {
    s->base = (int *)malloc(STACK_INIT_SIZE * sizeof(int));
    if(!s->base) {
        printf("空间不足");
        return 1;
    }
    s->top = s->base;
    s->size = STACK_INIT_SIZE;
    return 0;
}


int Push(SqStack *s, int e) {
    if(s->top - s->base >= s->size) {
        // 栈满 使用realloc重新分配空间
        s->base = (int *)realloc(s->base, (s->size + STACK_INCREASEMENT) * sizeof(int));
        if(!s->base) {
            printf("空间不足");
            return 1;
        }
        s->top = s->base + s->size;
        s->size += STACK_INCREASEMENT;
    }
    *s->top = e;
    s->top++;
    return 0;
}


int GetTop(SqStack *s, int *e) {
    if(s->base == s->top) {
        return -1;
    }
    *e = *(s->top-1);
    return 0;
}


int Pop(SqStack *s, int *e) {
    if(s->top == s->base) {
        return -1;
    }
    *e = *(s->top-1);
    s->top--;
    s->size--;
    return 0;
}


int main() {
    SqStack s;
    InitStack(&s);
    if(!s.base) {
        printf("Exit\n");
        exit(1);
    }
    printf("请输入要插入的数据元素, 如果要终止插入, 请输入0...\n");
    int INPUT, e;
    while(scanf("%d", &INPUT)) {
        if(INPUT == 0) {
            printf("结束!\n");
            break;
        }
        printf("插入元素%d, 栈大小 %ld\n", INPUT, (s.top-s.base+1));
        printf((Push(&s, INPUT) == 0) ? "OK" : "Fail");
        printf("\n");
        GetTop(&s, &e);
        printf("StackTop: %d \n", e);
    }
    printf("输入1弹出元素, 否则终止...\n");
    while(scanf("%d", &INPUT)) {
        if(INPUT != 1) {
            printf("结束!\n");
            break;
        }
        if(Pop(&s, &e) == 0) {
            printf("弹出元素 %d OK\n", e);
        } else {
            printf("弹出元素 Fail\n");
        }
    }
    return 0;
}
