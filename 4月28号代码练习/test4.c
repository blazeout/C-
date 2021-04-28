#include<stdio.h>
#include<stdlib.h>

// 不允许创建临时变量 交换两个数
int main() {
	int a = 10;
	int b = 20;
	// 使用加法减法可以交换
	 /*a = a + b;
	 b = a - b;
	 a = a - b;*/
	 // 但是 int 四个字节 只能最大表示21亿9千万 如果一个值是10亿 另外一个值是20亿就会有溢出风险
	 // 所以我们使用按位异或操作符 相同为0 不同为1
	a = a ^ b;
	b = a ^ b;
	a = a ^ b;
	printf("a=%d b=%d\n", a, b);
	system("pause");
	return 0;
}