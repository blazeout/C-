#include<stdio.h>
#include<stdlib.h>
// дһ�������ж��Ƿ�Ϊ����
void  isLeapYear(int year) {
	if (year % 100 == 0) {
		if (year % 400 == 0) {
			printf("%d����������\n", year);
		}
		else {
			printf("%d��������\n",year);
		}
	}
	else {
		if (year % 4 == 0) {
			printf("%d����ͨ����\n", year);
		}
		else {
			printf("%d��������\n",year);
		}
	}
}
int main() {
	int year = 0;
	printf("������һ�����\n");
	scanf_s("%d", &year);
	isLeapYear(year);
	system("pause");
	return 0;
}