// 循环后移：有 n 个整数，使前面各数顺序向后移 m 个位置，移出的数再从开头移入。编写一个函数实现以上功能，在主函数中输入 n 个整数并输出调整后的 n 个数。试编写相应程序。


#include <stdio.h>


void moveNumbers(int arr[], int n) {
	int tmp = arr[n-1]; // 暂存最后一位
	for(int i=n-1; i>0; i--) {
		arr[i] = arr[i-1];
	}
	arr[0] = tmp;
}

int main() {
	int n, m;
	printf("Input n:");
	scanf("%d", &n);
	int arr[n];
	printf("Input %d numbers:", n);
	for(int i=0; i<n; i++) {
		scanf("%d", &arr[i]);
	}
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	printf("Input m:");
	scanf("%d", &m);
	for(int i=0; i<m; i++) {
		moveNumbers(arr, n);
	}
	for(int i=0; i<n; i++) {
		printf("%d ", arr[i]);
	}
	return 0;
}