#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	float a, b, t;
	scanf("%f%f", &a, &b);
	if (a > b) {
		t = a;
		a = b;
		b = t;
	}
	printf("%f,%f\n", a, b);
	system("pause");
	return 0;
}