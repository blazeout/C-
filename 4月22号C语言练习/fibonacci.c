#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fibonacci(int n) {
	if (n == 2 || n == 1) {
		return 1;
	}
	return  fibonacci(n - 1) + fibonacci(n - 2);
}
int main() {
	int n = 0;
	scanf("%d", &n);
	int sum = fibonacci(n);
	printf("%d", sum);
	system("pause");
	return 0;
}