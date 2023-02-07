// 使用函数实现字符串复制：输入一个字符串 t 和一个正整数 m， 将字符串 t 中从第 m 个字符开始的全部字符复制到字符串 s 中，再输出字符串 s 。要求自定义并调用函数 void strmcpy(char *s， char *t， int m)。试编写相应程序。


#include <stdio.h>


void strmcpy(char *s, char *t, int m) {
    char *tm = t + m - 1;
    char *sm = s;
    int j = 0;
    for(int i=0; tm[i] != '\0'; i++) {
        sm[j++] = tm[i];
    }
    sm[j] = '\0';
    for(int k=0; k<j; k++) {
        printf("%c", s[k]);
    }
}


int main() {
    int m, n;
    printf("Input m:");
    scanf("%d", &m);
    printf("Input length of chars:");
    scanf("%d", &n);
    char t[100];
    printf("n=%d", n);
    for(int i=0; i<n; i++) {
        printf("!");
        scanf("%c", t[i]);
    }
    t[n] = '\0';
    char s[100];
    strmcpy(s, t, m);
}