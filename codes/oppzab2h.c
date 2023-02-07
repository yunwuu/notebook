// 报数：有 n 个人围成一圈，按顺序从 1 到 n 编好号。从第一个人开始报数，报到 m（m<n）的人退出圈子，下个人从 1 开始报数，报到 m 的人退出圈子。 如此下去，直到留下最后一个人。输入整数 n 和 m ，并按退出顺序输出退出圈子的人的编号。试编写相应程序。


#include <stdio.h>


int main() {
	int n;
	printf("Input n:");
	scanf("%d", &n);
	int status[100];
	for(int i=0; i<n; i++) {
		status[i] = 0; // 默认为未退出状态
	}
	int m;
	printf("Input m:");
	scanf("%d", &m);
	int remain = n; // 剩余人数
	int i = 0;
	while(remain > 1) {
		int pos = 0;
		for(; i<n; i++) {
			if(status[i] == 0) pos++;
			if(pos == m) break;
			if(i + 1 >= n) i -= n; // 回到头部
		}
		status[i] = 1;
		remain--;
		printf("%d ", i+1);
	}
	for(int k=0; k<n; k++) {
		if(status[k] == 0) printf("\nLast number is %d", k+1);
	}
	return 0;
}