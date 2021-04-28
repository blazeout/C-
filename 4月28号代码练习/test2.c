#include<stdio.h>
#include<stdlib.h>

int main() {
	int a = 0;
	printf("请输入一个整数\n");
	scanf_s("%d", &a);
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (a & (1 << i)) {
			count++;
		}
	}
	printf("二进制中1的个数 = %d\n", count);
	system("pause");
	return 0;
}