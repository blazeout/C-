#include<stdio.h>
#include<stdlib.h>

// ����������ʱ���� ����������
int main() {
	int a = 10;
	int b = 20;
	// ʹ�üӷ��������Խ���
	 /*a = a + b;
	 b = a - b;
	 a = a - b;*/
	 // ���� int �ĸ��ֽ� ֻ������ʾ21��9ǧ�� ���һ��ֵ��10�� ����һ��ֵ��20�ھͻ����������
	 // ��������ʹ�ð�λ�������� ��ͬΪ0 ��ͬΪ1
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}