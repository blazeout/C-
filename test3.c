#include<stdio.h>
#include<stdlib.h>
void print_num(int num) {
	if (num > 9) {
		print_num(num / 10);
	}
	printf("%d\n", num % 10);
}
int main() {
	int num = 0;
	printf("ÇëÊäÈëÒ»´®Êı×Ö\n");
	scanf_s("%d",&num);
	print_num(num);
	system("pause");
	return 0;
}