#include <stdio.h>


int cmp(char *s1, char *s2) {
    int i;
    for(i=0; s1[i] != '\0', s2[i] != '\0'; i++) {
        if((int)s1[i] > (int)s2[i]) return 1;
        if((int)s1[i] < (int)s2[i]) return -1;
    }
    if(s1[i] != '\0') return 1;
    if(s2[i] != '\0') return -1;
    return 0;
}


int main() {
    char s[4][100];
    for(int i=0; i<5; i++) {
        printf("Input %d th/st string:", i+1);
        scanf("%s", s[i]);
    }
    char tmp[80];
    for(int i=0; i<4; i++) {
        for(int j=0; j<3-i; j++) {
            char s1[] = s[j];
            char s2[] = s[j+1];
            if(cmp(s1, s2) == 1) {
                
            }
        }
    }
}