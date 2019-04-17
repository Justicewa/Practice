#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int action1(int x) {
	int y = x;
	return(y);
}

int action2(int x) {
	int y = 2 * x - 1;
	return y;
}

int action3(int x) {
	int y = 3 * x - 11;
	return y;
}

int main() {
	int x;
	scanf("%d", &x);
	if (x < 1) {
		int z = action1(x);
		printf("%d\n", z);
	}
	if (x < 10 && x >= 1 ) {
		int z = action2(x);
		printf("%d\n", z);
	}
	if (x >= 10 ) {
		int z = action3(x);
		printf("%d\n", z);
	}
	system("pause");
	return 0;
}