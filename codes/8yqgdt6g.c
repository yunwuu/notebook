// 拆分实数的整数与小数部分：要求自定义一个函数 void splitfloat (float x，int *intpart, float *fracpart)， 其中 x 是被拆分的实数，* intpart 和 * fracpart 分别是将实数 x 拆分出来的整数部分与小数部分。编写主函数，并在其中调用函数 splitfloat() 。试编写相应程序。

#include <stdio.h>


void splitfloat(float x, int *intpart, float *fracpart) {
	*intpart = (int)x;
	*fracpart = x - *intpart;
}

int main() {
	float x, fracpart;
	int intpart;
	printf("Input a number: ");
	scanf("%f", &x);
	splitfloat(x, &intpart, &fracpart);
	printf("intpart=%d, fracpart=%f\n", intpart, fracpart);
	return 0;
}