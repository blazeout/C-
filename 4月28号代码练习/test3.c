#include<stdio.h>
#include<stdlib.h>
//获取一个整数二进制序列中所有的偶数位和奇数位，分别打印出二进制序列
int main() {
	int m = 0;
	scanf_s("%d", &m);
	int i = 0;
	// 偶数位
	printf("偶数位:");
	for (int i = 31; i >= 1; i -= 2) {
		printf("%d", (m >> i) & 1);
	}
	// 奇数位
	printf("\n");
	printf("奇数位:");
	for (int i = 30; i >= 0; i -= 2) {
		printf("%d", (m >> i) & 1);
	}
	printf("\n");
	system("pause");
	return 0;
}