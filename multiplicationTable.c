#include<stdio.h>
#include<stdlib.h>
// 实现一个函数 打印乘法口诀表 
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
	printf("请输入一个整数:\n");
	scanf_s("%d", &num);
	printTable(num);
	system("pause");
	return 0;
}