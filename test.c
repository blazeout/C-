#include<stdio.h>
#include<stdlib.h>
// 写一个函数判断是否为闰年
void  isLeapYear(int year) {
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			printf("%d是世纪闰年\n", year);
		}
		else {
			printf("%d不是闰年\n",year);
		}
	}
	else {
		if (year % 4 == 0) {
			printf("%d是普通闰年\n", year);
		}
		else {
			printf("%d不是闰年\n",year);
		}
	}
}
int main() {
	int year = 0;
	printf("请输入一个年份\n");
	scanf_s("%d", &year);
	isLeapYear(year);
	system("pause");
	return 0;
}