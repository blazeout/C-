#include<stdio.h>
#include<stdlib.h>
// дһ������������������������
// ����д�� int a�� int b ��������� ��Ϊ�βεĸı佻��������ʵ����˵ûʲô��
void swap(int* a, int* b) {// �˴�int* Ϊָ������
	int temp = *a;
	*a = *b;
	*b = temp; //������*Ϊ�����ò��� ���ݴ�������a��b�ĵ�ַ �������ҵ� ���Ҳ��� a��b��ֵ
}
int main() {
	int a = 10;
	int b = 20;
	swap(&a, &b);// �����ַ��ȥ 
	printf("a = %d \n", a);
	printf("b = %d \n", b);
	system("pause");
	return 0;
}