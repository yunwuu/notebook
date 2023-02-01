#include <stdlib.h>
#include <stdio.h>


struct Node {
    int data;
    struct Node *next;
};

typedef struct Node nn, *nptr;


void changeNode(nptr n) {
    n->data = 111;
    n->next = NULL;
}


int main() {
    nn n;
    changeNode(&n);
    printf("%d", n.data);
}