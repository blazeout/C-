#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>

int main() {
	int a = 0;
	int b = 0;
	printf("��������������!\n");
	scanf("%d %d", &a, &b);
	int num = a ^ b;
	int count = 0;//count ��ʾa��b���֮��������ж��ٸ�1
	for (int i = 0; i < 32; i++) {
		if ((num) & (1 << i)) {
			count++;
		}
	}
	printf("%d\n", count);
	system("pause");
	return 0;
}