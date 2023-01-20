#define LIST_INIT_SIZE 100

#include <stdlib.h>
#include <stdio.h>


typedef struct LNode {
    int data;
    struct LNode *next;
}LNode, *LinkList;


int GetElem(LinkList L, int i, int *e) {
    LinkList p = L->next;
    int j = 1;
    while(p && j < i) {
        p = p->next;
        j++;
    }
    if(!p || j > i) {
        return 1;
    }
    *e = p->data;
    return 0;
}


int DeleteElem(LinkList L, int i, int *e) {
    LinkList p = L;
    int j = 0;
    while(p->next && j < i - 1) {
        p = p->next;
        j++;
    }
    if(!(p->next) || j > i - 1) {
        return 1;
    }
    LinkList q = p->next;
    p->next = q->next;
    *e = p->data;
    free(q);
    return 0;
}


int Insert(LinkList L, int i, int e) {
    LinkList p = L;
    int j = 0;
    while(p && j < i - 1) {
        p = p->next;
        j++;
    }
    if(!p || j > i - 1) {
        return 1;
    }
    LinkList s = (LinkList)malloc(sizeof(LNode));
    s->data = e;
    s->next = p->next;
    p->next = s;
    return 0;
}


int PrintList(LinkList L) {
    if(!L) {
        return 1;
    }
    LinkList p = L;
    while(p) {
        printf("%d  ", p->data);
        p = p->next;
    }
    printf("\n");
    return 0;
}

int main() {
    LinkList list = (LinkList)malloc(LIST_INIT_SIZE * sizeof(LNode));
    if(!list) {
        printf("空间不足\n");
        exit(1);
    } else {
        printf("创建链表成功\n");
    }
    int list_length = 0;
    int INPUT;
    printf("请输入要插入的数据元素, 如果要终止插入, 请输入0...\n");
    while(scanf("%d", &INPUT)) {
        if(INPUT == 0) {
            printf("结束!\n");
            break;
        }
        printf("插入元素%d到%d位置", INPUT, list_length);
        printf((Insert(list, list_length+1, INPUT) == 0) ? "OK" : "Fail");
        printf("\n");
        printf("PrintList: ");
        PrintList(list);
        list_length++;
    }
    printf("请输入要删除的数据元素位置, 如果要终止删除, 请输入0...\n");
    while(scanf("%d", &INPUT)) {
        if(INPUT == 0) {
            printf("结束!\n");
            break;
        }
        printf("删除%d位置上的元素", INPUT);
        int *e = malloc(sizeof(int));
        printf((DeleteElem(list, INPUT, e) == 0) ? "OK" : "Fail");
        printf("\n");
        printf("*e = %d\n", *e);
        printf("PrintList: ");
        PrintList(list);
        printf("\n");
    }
}