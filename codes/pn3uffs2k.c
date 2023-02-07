// 使用函数实现字符串复制：输入一个字符串 t 和一个正整数 m， 将字符串 t 中从第 m 个字符开始的全部字符复制到字符串 s 中，再输出字符串 s 。要求自定义并调用函数 void strmcpy(char *s， char *t， int m)。试编写相应程序。


#include <stdio.h>
#include <string.h>


void strmcpy(char *s, char *t, int m){
    t = t + m - 1;
    while(*t != '\0') {
        *s = *t;
        s++;
        t++;
    }
    *s = '\0';
}


int main() {
    char s[100], t[100];
    int m;
    printf("Input m:");
    scanf("%d", &m);
    printf("Input string:");
    scanf("%s", t);
    getchar();
    if(strlen(t) < m) {
        printf("Invalid!");
        return -1;
    }
    strmcpy(s, t, m);
    printf("%s", s);
    return 0;
}