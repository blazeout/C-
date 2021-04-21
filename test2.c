#include<stdio.h>
#include<stdlib.h>
// 写一个函数交换两个整数的内容
// 若是写成 int a， int b 则可能无用 因为形参的改变交换，对于实参来说没什么用
void swap(int* a, int* b) {// 此处int* 为指针类型
	int temp = *a;
	*a = *b;
	*b = temp; //此三处*为解引用操作 根据传进来的a，b的地址 解引用找到 并且操作 a和b的值
}
int main() {
	int a = 10;
	int b = 20;
	swap(&a, &b);// 传入地址进去 
	printf("a = %d \n", a);
	printf("b = %d \n", b);
	system("pause");
	return 0;
}