#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
int fibonacci2(int n) {
	if (n == 1 || n == 2) {
		return 1;
	}
	int last2 = 1;//��i-2��
	int last1 = 1;//��i-1��
	int result = 0;
	for (int i = 3; i <= n; i++) {      //ÿ��ѭ����Ҫ����ǰһ����ǰ�����ֵ
		result = last1 + last2;
		last2 = last1;
		last1 = result;
	}
	return result;
}

// �ǵݹ�ʵ��쳲���������
int main() {
	int n = 0;
	printf("����һ������\n");
	scanf("%d", &n);
	int sum = fibonacci2(n);
	printf("%d\n", sum);
	system("pause");
	return 0;
}