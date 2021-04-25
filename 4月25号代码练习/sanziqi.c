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
		printf("������������\n");
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		if (row >= MAX_ROW || row < 0 || col >= MAX_COL || col < 0) {
			printf("�������������������������\n");
			continue;
		}
		if (arr[row][col] != ' ') {
			printf("�������λ������������������!\n");
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
// �˴��涨����1 ��ʾ�������� ����0��ʾ����δ��
int isFull(char arr[MAX_ROW][MAX_COL]) {
	for (int row = 0; row < MAX_ROW; row++) {
		for (int col = 0; col < MAX_COL; col++) {
			// ��������, ������û�пո�. �пո����û��
			if (arr[row][col] ==' ' ) {
				return 0;
			}
		}
	}
	return 1;//ȫ���������˶�û�ÿո��ʾ����
}
// �涨����'x'��ʾΪ��һ�ʤ 'o'��ʾΪ���Ի�ʤ 'q'��ʾ˫���;� ' '��ʾ�廹û���������
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
	// �ж������еĶԽ��ߺ��к���֮���Ҫ�ж��Ƿ�Ϊ����
	if (isFull(arr)) {
		return 'q';
	}
	return ' ';
}
int main() {
	// 1.����һ��3x3�Ķ�ά����
	char arr[MAX_ROW][MAX_COL];
	// 2. ��ӡһ������
	init(arr);
	char winner = ' ';
	while (1) {
		printchess(arr);
		// �涨 'x'��ʾ������� 'o'��ʾ����������� ' '��ʾ��û�����ӵĵط�
		// 3.��ҽ������� ���������һ��(row,col)��������
		playerMove(arr);
		// 4.�ж��Ƿ��ʤ 
		 winner = isWin(arr);
		if (winner != ' ') {
			// �ʹ�����Ϸ������
			break;
		}
		// 5.��������������Ӳ���'o'��ʾ
		computerMove(arr);
		// 6.�ж��Ƿ��ʤ
		char winner = isWin(arr);
		if (winner != ' ') {
			// �ʹ�����Ϸ������
			break;
		}
	}
	if (winner == 'x') {
		printf("��ϲ��Ӯ��\n");
	}
	else if (winner == 'o') {
		printf("�����bro���˹����ϵĴ�Ӯ\n");
	}
	else {
		printf("�㾹Ȼ���˹����Ϻ�����...\n");
	}
	system("pause");
	return 0;
}