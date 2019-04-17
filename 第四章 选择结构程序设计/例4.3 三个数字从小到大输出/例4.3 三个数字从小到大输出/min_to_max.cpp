#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	float a, b, c, t;
	printf("请输入三个数字\n");
	scanf("%f%f%f", &a, &b, &c);
	if (a < b) {
		t = a;
		a = b;
		b = t;
	}
	if (a < c) {
		t = a;
		a = c;
		c = t;
	}
	if (b < c) {
		t = b;
		b = c;
		c = t;
	}
	printf("%5.2f,%5.2f,%5.2f\n", a, b, c);
	system("pause");
	return 0;
}