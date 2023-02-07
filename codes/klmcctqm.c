#include <stdio.h>


void delchar(char *s, char c) {
    for(int i=0; s[i] != '\0'; i++) {
        if(s[i] == c) {
            for(int j=i; s[j] != '\0'; j++) {
                s[j] = s[j+1];
            }
            i--;
        }
    }
}


int main() {
    char c;
    char str[80];
    printf("Input string:");
    gets(str);
    printf("Input char:");
    scanf("%c", &c);
    getchar();
    delchar(str, c);
    printf("result:");
    puts(str);
    return 0;
}