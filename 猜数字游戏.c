#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void  menu() {

	printf("============================\n");
	printf("====��ӭ������������Ϸ=====\n");
	printf("=====����1��ʾ��ʼ========\n");
	printf("======����0���˳�========\n");

}
void game() {
	int random = rand() % 100 + 1;
	int number;
	printf("������һ������\n");
	while (1) {
		scanf("%d", &number);
		if (number > random) {
			printf("����\n");
		}
		else if (number < random) {
			printf("����\n");
		}
		else {
			printf("��ϲ������");
				break;
		}
	}
}
int main() {
	int num = 0;
	srand((unsigned int)time(0));
	// rand����Ϊ����� ��Ҫÿ�����ò�һ����ʱ�����Ӳ���ÿһ��������ɵ����ֲ�һ�� ��ʹ��ʱ�����������
	while (1) {
		menu();
		printf("�����룡\n");
		scanf("%d", &num);
		if (num == 1) {
			game();
		}
		else if (num == 0) {
			printf("�ټ�������\n");
			break;
		}
		else {
			printf("�����������! \n");
		}
	}
	return 0;
}