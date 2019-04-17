#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main(){
	int a[4];
	scanf("%d %d %d %d", &a[0], &a[1], &a[2], &a[3]);
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4 - i - 1; j++) {
			if (a[j]>a[j + 1]) {
				int t = a[j];
				a[j] = a[j + 1];
				a[j + 1] = t;
			}
		}
	}
	printf("%d %d %d %d\n", a[0],a[1],a[2],a[3]);
	system("pause");
	return 0;
}