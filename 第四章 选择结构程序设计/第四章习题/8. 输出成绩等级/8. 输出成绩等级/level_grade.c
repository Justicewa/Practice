#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	int grade = 0;
	scanf("%d", &grade);
	if (grade >= 90 && grade<= 100 ) {
		printf("You level is :A\n");
	}
	if (grade <= 89 && grade >= 80) {
		printf("You level is :B\n");
	}
	if (grade <= 79 && grade >= 70) {
		printf("You level is :C\n");
	}
	if (grade <= 69 && grade >= 60) {
		printf("You level isD :\n");
	}
	if (grade < 60 ) {
		printf("You level isE :\n");
	}
	system("pause");
	return 0;
}