#include<stdio.h>
#include<stdlib.h>
int DigitSum(n) {
	int sum = 0;
	int i = 0;
	if (n > 9) {
		 i = DigitSum(n / 10);
	}
	n = n % 10;
	sum = sum + n + i;
	return sum;
}
int main() {
	unsigned int n = 0;
	printf("请输入一个非负整数\n");
	scanf_s("%d", &n);
	int sum = DigitSum(n);
	printf("结果为%d\n", sum);
	system("pause");
	return 0;
}