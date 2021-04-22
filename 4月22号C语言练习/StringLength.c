#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
// 用递归和非递归实现strlen函数
int myStrlen1(char arr[]) {
	if (arr[0] == '\0') {
		return 0;
	}
	return 1 + myStrlen1(1 + arr);
}
int myStrlen2(char* arr) {
	int count = 0;
	while (arr[count] != '\0') {
		count++;
	}
		return count;
}
int main() {
	char arr[100] = "";
	printf("请输入字符串\n");
	scanf("%s", &arr);
	printf("字符串的长度为%d\n", myStrlen2(arr));
	system("pause");
	return 0;
}