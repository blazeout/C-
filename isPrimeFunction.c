#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int isPrime(int num) {
	for (int i = 2; i < num / 2; i++) {
		if (num % i == 0) {
			return 0;
		}
	}
	return 1;
}
int main() {
	int num = 0;
	for ( num = 100; num <= 200; num++) {
		if (1 == isPrime(num)) {
			printf("%d\n", num);
		}
	}
	system("pause");
	return 0;
}