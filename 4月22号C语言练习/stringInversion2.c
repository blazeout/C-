#include<stdio.h>
#include<stdlib.h>
// �ݹ鷽�� ���ᡣ������csdn
int myStrlen(char* arr) {
	if (arr[0] == '\0') {
		return 0;
	}
	return 1 + myStrlen(1 + arr);
}
void reverse_string2(char str[]) {
	int len = myStrlen(str);
	char temp = *str;
	*str = *(str + len - 1);
	*(str + len - 1) = '\0';
	if (myStrlen(str) > 0) {
		reverse_string2(str + 1);
	}
	*(str + len - 1) = temp;
}
int  main() {
	char arr[] = "abcdfeg";
	printf("before:%s\n", arr);
	reverse_string2(arr);
	printf("after:%s\n", arr);
	return 0;
}