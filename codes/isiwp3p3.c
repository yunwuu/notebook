// 判断回文：判断输入的一串字符是否为“回文”。所谓“回文”是指顺读和倒读都一样的字符串。如 "XYZYX" 和 "xyzzyx" 都是回文。试编写相应程序。


#include <stdio.h>
#include <string.h>


int main() {
    char s[100];
    printf("Input string:");
    scanf("%s", s);
    int len = strlen(s);
    char *tail = s + len - 1;
    char *head = s;
    while(tail - head > 0) {
        if(*tail != *head) {
            printf("Not palindrome!");
            return 0;
        }
        tail--;
        head++;
    }
    printf("Is palindrome!");
    return 0;
}