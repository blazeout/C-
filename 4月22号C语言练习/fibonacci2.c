#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fibonacci2(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	int last2 = 1;//第i-2项
	int last1 = 1;//第i-1项
	int result = 0;
	for (int i = 3; i <= n; i++) {      //每次循环都要更新前一项与前两项的值
		result = last1 + last2;
		last2 = last1;
		last1 = result;
	}
	return result;
}

// 非递归实现斐波那契数列
int main() {
	int n = 0;
	printf("输入一个整数\n");
	scanf("%d", &n);
	int sum = fibonacci2(n);
	printf("%d\n", sum);
	system("pause");
	return 0;
}