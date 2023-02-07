#include <stdio.h>
#include <string.h>

int main() {
    char s[4][100];
    for(int i=0; i<5; i++) {
        printf("Input %d th/st string:", i+1);
        scanf("%s", s[i]);
    }
    char tmp[80];
    for(int i=0; i<4; i++) {
        int index = 0;
        for(int j=i+1; j<5; j++) {
            if(strcmp(s[j], s[index]) == -1) index = j;
        }
        strcpy(tmp, s[i]);
        strcpy(s[i], s[index]);
        strcpy(s[index], tmp);
    }
    for(int i=0; i<5; i++) {
        printf("%s\n", s[i]);
    }
    return 0;
}