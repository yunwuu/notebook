// 在数组中查找指定元素：输入一个正整数 n （1<n≤10），然后输入 n 个整数存入数组 a 中，再输入一个整数 x ，在数组 a 中查找 x ，若找到则输出相应的下标，否则显示 Not found。要求定义和调用函 search(int lis[], int n, int x)， 在数组 list 中查找元素 x ，若找到则返回相应下标，否则返回 -1，参数 n 代表数组 list 中元素的数量。试编写相应程序。


#include <stdio.h>


int search(int lis[], int n, int x) {
	int i = 0;
	while(i < n) {
		if(lis[i] == x) return i;
		else i++;
	}
	return -1;
}

int main() {
	int n, x;
	printf("Input n:");
	scanf("%d", &n);
	int lis[10];
	printf("Input x:");
	scanf("%d", &x);
	printf("Input %d numbers:", n);
	for(int k=0; k<n; k++) {
		scanf("%d", &lis[k]);
	}
	int res = search(lis, n, x);
	if(res == -1) printf("没有找到！");
	else printf("索引为%d", res);
	return 0;
}