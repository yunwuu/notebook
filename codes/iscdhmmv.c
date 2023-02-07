// 输出学生成绩（动态分配）：输入学生人数后输入每个学生的成绩，最后输出学生的平均成绩、最高成绩和最低成绩。要求使用动态内存分配来实现。试编写相应程序。


#include <stdio.h>
#include <stdlib.h>


int main() {
    float min = 999, max = -1, avg = 0;
    int cnt = 0, amount;
    printf("Input num:");
    scanf("%d", &amount);
    float *score = (float *)malloc(sizeof(float));
    while(amount > 0) {
        scanf("%f", score);
        if(min > *score) min = *score;
        if(max < *score) max = *score;
        cnt++;
        avg = (avg * (cnt - 1) + *score) / cnt;
        amount--;
    }
    printf("max=%f,min=%f,avg=%f", max,min,avg);
    return 0;
}