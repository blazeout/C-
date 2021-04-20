#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void  menu() {

	printf("============================\n");
	printf("====欢迎来到猜数字游戏=====\n");
	printf("=====输入1表示开始========\n");
	printf("======输入0表退出========\n");

}
void game() {
	int random = rand() % 100 + 1;
	int number;
	printf("请输入一个整数\n");
	while (1) {
		scanf("%d", &number);
		if (number > random) {
			printf("高了\n");
		}
		else if (number < random) {
			printf("低了\n");
		}
		else {
			printf("恭喜你答对了");
				break;
		}
	}
}
int main() {
	int num = 0;
	srand((unsigned int)time(0));
	// rand函数为假随机 需要每次设置不一样的时间种子才能每一次随机生成的数字不一样 故使用时间戳当做种子
	while (1) {
		menu();
		printf("请输入！\n");
		scanf("%d", &num);
		if (num == 1) {
			game();
		}
		else if (num == 0) {
			printf("再见了您！\n");
			break;
		}
		else {
			printf("您输入的有误! \n");
		}
	}
	return 0;
}