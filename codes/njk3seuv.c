#include <stdio.h>
#include <stdlib.h>
int main(void)
{
	// 习题(8.3.10)
	/*
	（选做）输出学生成绩（动态分配）：输入学生人数后输入每个学生的成绩，最后输出学生的平均成绩、最高成绩和最低成绩。
	要求使用动态内存分配来实现。
	*/
	int n, i;
	float *p, sum, max, min, avg;
	printf("input students' number n: ");
	scanf("%d", &n);
	/*为数组p动态分配n个浮点数float 类型大小的空间*/
	if ((p = (float *)calloc(n, sizeof(float))) == NULL)
	{
		printf("Not able to allocate memory.\n");
		exit(1);
	}
	sum = 0.0;
	max = -1; /*初始化*/
	min = 1000;
	printf("input %d students' scores: ", n); /*提示输入n个整数*/
	for (i = 0; i < n; i++)
	{
		scanf("%f", p + i);
		sum = sum + *(p + i);
		if (min > *(p + i))
			min = *(p + i);
		if (max < *(p + i))
			max = *(p + i);
	}
	avg = sum / n;
	printf("The avg is %f, max is %f, min is %f\n", avg, max, min);
	free(p); /*释放动态分配的空间*/
	return 0;
}