// 报数：有 n 个人围成一圈，按顺序从 1 到 n 编好号。从第一个人开始报数，报到 m（m<n）的人退出圈子，下个人从 1 开始报数，报到 m 的人退出圈子。 如此下去，直到留下最后一个人。输入整数 n 和 m ，并按退出顺序输出退出圈子的人的编号。试编写相应程序。


#include <stdio.h>


int main() {
	int n;
	printf("Input n:");
	scanf("%d", &n);
	int status[n];
    for(int i=0; i<n; i++) {
        status[i] = 0;
    }
	int cnt = n; // 圈子里剩余的人数
	while(cnt > 1) {
		int tmp = 0;
        int i = 0;
		for(; tmp < n; i++) {
			if(status[i] == 0) tmp++;
		}
		status[i] = 1;
		printf("%d", i);
		cnt--;
	}

}