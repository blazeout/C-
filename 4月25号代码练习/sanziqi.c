#define _CRT_SECURE_NO_WARNINGS
#include<stdio.h>
#include<stdlib.h>
#define MAX_ROW 3
#define MAX_COL  3
void init(char arr[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			arr[row][col] = ' ';
		}
	}
}

void printchess(char arr[MAX_ROW][MAX_COL]) {
	printf("+---+---+---+\n");
	for (int row = 0; row < MAX_ROW; row++) {
		printf("|");
		for (int col = 0; col < MAX_COL; col++) {
			printf(" %c |", arr[row][col]);
		}
		printf("\n+---+---+---+\n");
	}

}

void playerMove(char arr[MAX_ROW][MAX_COL]) {
	while (1) {
		printf("玩家请进行落子\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {
			printf("您输入的坐标有误请重新输入\n");
			continue;
		}
		if (arr[row][col] != ' ') {
			printf("您输入的位置有子了请重新输入!\n");
			continue;
		}
		arr[row][col] = 'x';
		break;
	}
}

void computerMove(char arr[MAX_ROW][MAX_COL]) {
	while (1) {
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (arr[row][col] != ' ') {
			continue;
		}
		arr[row][col] = 'o';
		break;
	}
}
// 此处规定返回1 表示棋盘满了 返回0表示棋盘未满
int isFull(char arr[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			// 遍历棋盘, 看看有没有空格. 有空格就是没满
			if (arr[row][col] ==' ' ) {
				return 0;
			}
		}
	}
	return 1;//全部遍历完了都没用空格表示满了
}
// 规定返回'x'表示为玩家获胜 'o'表示为电脑获胜 'q'表示双方和局 ' '表示棋还没有下完继续
char isWin(char arr[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		if (arr[row][0] != ' '
			&&arr[row][0] == arr[row][2]
			&& arr[row][0] == arr[row][1]) {
			return arr[row][0];
		}
	}
	for (int col = 0; col < MAX_COL; col++) {
		if (arr[0][col] != ' '
			&&arr[0][col] == arr[2][col]
			&& arr[1][col] == arr[0][col]) {
			return arr[0][col];
		}
	}
	if (arr[0][0] != ' '
		&&arr[0][0] == arr[1][1]
		&& arr[0][0] == arr[2][2]) {
		return arr[0][0];
	}
	if (arr[0][2] != ' '
		&& arr[0][2] == arr[1][1]
		&& arr[0][2] == arr[2][0]) {
		return arr[0][2];
	}
	// 判断完所有的对角线和行和列之后就要判断是否为和棋
	if (isFull(arr)) {
		return 'q';
	}
	return ' ';
}
int main() {
	// 1.创造一个3x3的二维数组
	char arr[MAX_ROW][MAX_COL];
	// 2. 打印一个棋盘
	init(arr);
	char winner = ' ';
	while (1) {
		printchess(arr);
		// 规定 'x'表示玩家落子 'o'表示电脑随机落子 ' '表示还没有落子的地方
		// 3.玩家进行落子 让玩家输入一组(row,col)进行落子
		playerMove(arr);
		// 4.判断是否获胜 
		 winner = isWin(arr);
		if (winner != ' ') {
			// 就代表游戏结束了
			break;
		}
		// 5.电脑随机进行落子并用'o'表示
		computerMove(arr);
		// 6.判断是否获胜
		char winner = isWin(arr);
		if (winner != ' ') {
			// 就代表游戏结束了
			break;
		}
	}
	if (winner == 'x') {
		printf("恭喜你赢了\n");
	}
	else if (winner == 'o') {
		printf("不会吧bro连人工智障的打不赢\n");
	}
	else {
		printf("你竟然和人工智障和棋了...\n");
	}
	system("pause");
	return 0;
}