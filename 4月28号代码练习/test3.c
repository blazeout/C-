#include<stdio.h>
#include<stdlib.h>
//��ȡһ���������������������е�ż��λ������λ���ֱ��ӡ������������
int main() {
	int m = 0;
	scanf_s("%d", &m);
	int i = 0;
	// ż��λ
	printf("ż��λ:");
	for (int i = 31; i >= 1; i -= 2) {
		printf("%d", (m >> i) & 1);
	}
	// ����λ
	printf("\n");
	printf("����λ:");
	for (int i = 30; i >= 0; i -= 2) {
		printf("%d", (m >> i) & 1);
	}
	printf("\n");
	system("pause");
	return 0;
}