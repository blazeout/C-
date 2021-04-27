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
	// count ��ʾ������λ�õ���Χ�ĵ��׸���
	int count = 0;
	for (int r = row - 1; r <= row + 1; r++) {
		for (int c = col - 1; c <= col + 1; c++) {
			if (r<0 || r>MAX_ROW || c<0 || c>MAX_COL) {
				// ���겻�Ϸ� ֱ������
				continue;
			}
			if (r == row && c == col) {
				// �м��λ�ò���Ҫ�ж�
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
		// ��ӡ��ͼ
		int row = 0;
		int col = 0;
		// ����������ַ������
		printf("������һ������: (row col) \n");
		scanf("%d %d", &row, &col);
		// �ж��������������Ƿ�Ϸ�
		if (row<0 || row>MAX_ROW || col<0 || col>MAX_COL) {
			printf("����������겻�Ϸ�,����������!\n");
			continue;
		}
		if (showMap[row][col] != '*') {
			printf("�������λ���Ѿ�������! ����������!\n");
			continue;
		}
		// �ж�����Ƿ����
		if (mineMap[row][col] == '1') {
			printf("�������� game over\n");
			break;
		}
		// ���µ�ͼ
		updateMap(showMap, mineMap, row, col);
		openedCount++;
		if (openedCount == MAX_ROW * MAX_COL - MINE_COUNT) {
			printf("��ϲ�����ڻ�ʤ��!\n");
		}
	}
	system("pause");
	return 0;
}