#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10
void init(char showMap[MAX_ROW][MAX_COL], char mineMap[MAX_ROW][MAX_COL]) {
	memset(showMap, '*', MAX_ROW * MAX_COL);
	memset(mineMap, '0', MAX_ROW * MAX_COL);
	srand( (unsigned int) time(0));
	int count = 0;
	while (count < MINE_COUNT)
	{
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (mineMap[row][col] == '1') {
			continue;
		}
		mineMap[row][col] = '1';
		count++;
	}
}
void printMap(char map[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_ROW; col++) {
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}

void updateMap(char showMap[MAX_ROW][MAX_COL],
	char mineMap[MAX_ROW][MAX_COL],int row, int col) {
	// count 表示翻开的位置的周围的地雷个数
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r<0 || r>MAX_ROW || c<0 || c>MAX_COL) {
				// 坐标不合法 直接跳过
				continue;
			}
			if (r == row && c == col) {
				// 中间的位置不需要判断
				continue;
			}
			if (mineMap[r][c] == '1') {
				count++;
			}
		}
	}
	showMap[row][col] = '0' + count;
}
int main() {
	char showMap[MAX_ROW][MAX_COL] = { 0 };
	char mineMap[MAX_ROW][MAX_COL] = { 0 };
	init(showMap, mineMap);
	int openedCount = 0;
	while (1) {
		system("cls");
		printMap(showMap);
		// 打印地图
		int row = 0;
		int col = 0;
		// 让玩家输入地址来翻开
		printf("请输入一个坐标: (row col) \n");
		scanf("%d %d", &row, &col);
		// 判断玩家输入的坐标是否合法
		if (row<0 || row>MAX_ROW || col<0 || col>MAX_COL) {
			printf("您输入的坐标不合法,请重新输入!\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("您输入的位置已经翻开了! 请重新输入!\n");
			continue;
		}
		// 判断玩家是否踩雷
		if (mineMap[row][col] == '1') {
			printf("您踩雷了 game over\n");
			break;
		}
		// 更新地图
		updateMap(showMap, mineMap, row, col);
		openedCount++;
		if (openedCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("恭喜您终于获胜了!\n");
		}
	}
	system("pause");
	return 0;
}