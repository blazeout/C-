#include<stdio.h>
#include<stdlib.h>
// ʵ��һ������ ��ӡ�˷��ھ��� 
void printTable(int num) {
	for (int  i = 1; i <=num; i++)
	{
		for (int j = 1; j <= i; j++) {
			printf("%d * %d = %d\t", j, i, i*j);
		}
		printf("\n");
	}

}
int main() {
	int num = 0;
	printf("������һ������:\n");
	scanf_s("%d", &num);
	printTable(num);
	system("pause");
	return 0;
}