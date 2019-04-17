#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main() {
	int x, y;
	printf("enter x:");
	scanf("%d", &x);

	//y = -1;
	//if (x != 0 ) {
	//	if (x > 0) {
	//		y = 1;
	//	}
	//}
	//else {
	//	y = 0;
	//}

	y = 0;
	if (x >= 0) {
		if (x > 0) {
			y = 1;
		}
	}
	else {
		y = -1;
	}
	printf("x=%d,y=%d\n", x, y);
	system("pause");
	return 0;
}