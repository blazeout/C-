#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
// ʹ�õݹ�ͷǵݹ�ʵ�ֽ׳�
//int jiecheng(int n) {
//	int sum = 1;
//	for (int i = 1; i <= n; i++) {
//		sum *= i;
//	}
//	return sum;
//}
int  jiecheng2(int n) {
	if (n == 1) {
		return 1;
	}
	return n * jiecheng2(n - 1);
}
int main() {

	int n = 0;
	printf("������һ������n\n");
	scanf("%d", &n);
	int sum = jiecheng2(n);
	printf("%d�Ľ׳���%d\n", n, sum);
	system("pause");
	return 0;
}