// 这里更像是一个Playgroud 主要用来排查各种稀奇古怪的错误用法
// 指针是一个渗透C语言方方面面的概念 专门写一些规整的代码来整理用法不太现实也没有太大意义

#define MAX_STRING_LEN 255

#include <stdlib.h>
#include <stdio.h>
#include <string.h>


struct Node {
    int data;
    struct Node *next;
};

typedef struct Node nn, *nptr;
typedef unsigned char SqString[MAX_STRING_LEN + 1]; // 首单元存储字符串长度信息


void changeNode(nptr n) {
    n->data = 111;
    n->next = NULL;
}


void writeString(SqString s) {
    SqString example = "abc";
    int SqSLength = 3;
    int index = 1;
    while(index <= example[0]) {
        s[index]  = example[index-1];
        index++;
    }
    s[0] = SqSLength;
}


int main() {
    nn n;
    changeNode(&n);
    printf("%d\n", n.data);
    SqString s;
    writeString(s);
    int i = 1;
    while(i <= s[0]) {
        printf("%c", s[i]);
        i++;
    }
    printf("\n");
}