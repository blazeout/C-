#include<stdio.h>
#include<stdlib.h>
int nk(int n, int k) {
	if (k == 0) {
		return 1;
	}
	return n * nk(n, k - 1);
}
int main() {
	int n = 0;
	int k = 0;
	scanf_s("%d%d", &n, &k);
	int ret = nk(n, k);
	printf("½á¹ûÎª%d\n", ret);
	system("pause");
	return 0;
}