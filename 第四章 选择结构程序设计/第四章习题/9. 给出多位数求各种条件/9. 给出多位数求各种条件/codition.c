#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int action1(int x) {
	if (x >= 10000 && x <= 99999) {
		x = 5;
		return x;
	}
	if (x >= 1000 && x <= 9999) {
		x = 4;
		return x;
	}
	if (x >= 100 && x <= 999) {
		x = 3;
		return x;
	}
	if (x >= 10 && x <= 99) {
		x = 2;
		return x;
	}
	if (x >= 0 && x <= 9) {
		x = 1;
		return x;
	}
}


int main() {
	int x = 0;
	scanf("%d", &x);
	if (x > 99999) {
		printf("请输入一个小于100000的数！\n");
	}
	int bit = action1(x);
	printf("这是一个%d位数\n", bit);


	system("pause");
	return 0;
}