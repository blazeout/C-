#include<stdio.h>
#include<stdlib.h>

int main() {
	int a = 0;
	printf("������һ������\n");
	scanf_s("%d", &a);
	int count = 0;
	for (int i = 0; i < 32; i++) {
		if (a & (1 << i)) {
			count++;
		}
	}
	printf("��������1�ĸ��� = %d\n", count);
	system("pause");
	return 0;
}