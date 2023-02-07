// 分类统计字符个数：输入一行文字，统计其中的大写字母、小写字母、空格、数字以及其他字符各有多少。试编写相应程序。


#include <stdio.h>
#include <string.h>


int main() {
    char s[100];
    printf("Input string:");
    scanf("%[^\n]", s); // scanf()默认以空格和回车作为结束标志 输入空格会强制加入\0 即便空间足够
    int len = strlen(s);
    int upper = 0, lower = 0, space = 0, number = 0;
    for(int i=0; i<len; i++) {
        if(s[i] == ' ') space++;
        if(s[i] >= 'a' && s[i] <= 'z') lower++;
        if(s[i] >= 'A' && s[i] <= 'Z') upper++;
        if((int)s[i] >= 48 && (int)s[i] <= 57) number++;
    }
    printf("Upper: %d, Lower: %d, space: %d, number: %d, others: %d", upper, lower, space, number, len-upper-lower-space-number);
    return 0;
}