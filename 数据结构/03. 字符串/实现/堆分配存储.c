#define MAX_STRING_LEN 255
#define OK 0
#define ERROR 1
#define BOOL int
#define TRUE 1
#define FALSE 0
#define OVERFLOW 2


#include <stdlib.h>
#include <stdio.h>


typedef struct {
    char *ch;
    int length;
}HeapString;


void StrAssign(HeapString *t, char *chars) {
    // 生成一个HeapString 值为chars
    if(t->ch) free(t->ch);
    char *c = chars;
    int len = 0;
    for(; *c != '\0'; ++c) {
        len++;
    }
    if(!len) {
        t->ch = NULL;
        t->length = 0;
    } else {
        t->ch = (char *)malloc(len * sizeof(char));
        if(!t->ch) exit(OVERFLOW);
        int index = 0;
        while(index <= len - 1) {
            t->ch[index] = chars[index];
            t->length = len;
            index++;
        }
    }
}


int Insert(HeapString *s, int pos, HeapString t) {
    // 在s的第pos个字符之前插入t
    if(pos < 1 || pos > s->length + 1) return ERROR;
    if(!t.length) return OK; // 无需处理
    s->ch = (char *)realloc(s->ch, (s->length + t.length) * sizeof(char)); // 扩展空间
    if(!s->ch) exit(OVERFLOW);
    // 移动pos后面的字符
    for(int i=s->length-1; i >= pos - 1; --i) {
        s->ch[i + t.length] = s->ch[i];
    }
    int sIndex = pos - 1, tIndex = 0;
    while(tIndex < t.length - 1) {
        s->ch[sIndex++] = t.ch[tIndex++]; 
    }
    s->length += t.length;
    return OK;
}


void ClearString(HeapString *s) {
    // 清空字符串
    if(s->ch) {
        free(s->ch);
        s->ch=NULL;
        s->length=0;
    }
}

int main() {
    char s[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    HeapString s1 = {malloc(sizeof(char)), 20};
    HeapString s2 = {malloc(sizeof(char)), 20};
    StrAssign(&s1, s);
    char m[6] = {'h', 'e', 'l', 'l', 'o', '\0'};
    StrAssign(&s2, m);
    Insert(&s1, 2, s2);
    char *x = s1.ch;
    int i = 0;
    while(i < s1.length) {
        printf("%c", s1.ch[i++]);
    }
    printf("\n");
    return 0;
}