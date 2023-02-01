#define MAX_STRING_LEN 255
#define OK 0
#define ERROR 1
#define BOOL int
#define TRUE 1
#define FALSE 0


#include <stdlib.h>
#include <stdio.h>


typedef unsigned char SqString[MAX_STRING_LEN + 1]; // 首单元存储字符串长度信息


BOOL Concat(SqString t, SqString s1, SqString s2) {
    // 将s1和s2拼接，并由t返回
    // 如果t长度不足（发生截断），则返回ERROR
    BOOL uncut;
    if(s1[0] + s2[0] <= MAX_STRING_LEN) {
        // 不会发生截断
        uncut = TRUE;
        int index = 1; // 首单元存储字符串长度信息
        while(index <= s1[0]) {
            t[index] = s1[index];
            index++;
        }
        // index=s1[0], starts from s1[0]+1
        while(index <= s1[0] + s2[0]) {
            t[index] = s2[index - s1[0]];
            index++;
        }
        t[0] = s1[0] + s2[0]; // 写入长度信息
    } else if (s1[0] < MAX_STRING_LEN) {
        // 发生截断 且仅s1没有超过MAX LENGTH
        uncut = FALSE;
        int index = 1;
        while(index <= s1[0]) {
            t[index] = s1[index];
            index++;
        }
        while(index <= MAX_STRING_LEN) {
            t[index] = s2[index - s1[0]];
            index++;
        }
        t[0] = MAX_STRING_LEN;
    } else {
        // 发生截断 且s1大于等于MAX LENGTH
        uncut = FALSE;
        int index = 0;
        while(index <= MAX_STRING_LEN) {
            t[index] = s1[index];
        }
        t[0] = MAX_STRING_LEN;
    }
    return uncut;
}


void Substring(SqString sub, SqString s, int pos, int len) {
    // 求子串
    // 用sub返回串s第pos个字符起长度为len的子串
    if(pos < 1 || pos > s[0] || len < 0 || len > s[0] - pos + 1) exit(ERROR);
    int index = 1;
    int posIndex = pos;
    while(index <= len) {
        sub[index] = s[posIndex];
        index++;
        posIndex++;
    }
    sub[0] = len;
}


int main() {
    SqString hi = "0HelloWorld!";
    hi[0] = 11;
    SqString aloha = "0Aloha!";
    aloha[0] = 6;
    SqString res;
    BOOL uncut = Concat(res, hi, aloha);
    printf(uncut == TRUE ? "uncut!" : "cut!");
    printf("\n");
    int i = 1;
    while(i <= res[0]) {
        printf("%c", res[i++]);
    }
    printf("\n");
    
    SqString sub;
    Substring(sub, hi, 2, 2);
    i = 1;
    while(i <= sub[0]) {
        printf("%c", sub[i++]);
    }
    printf("\n");
    return 0;
}