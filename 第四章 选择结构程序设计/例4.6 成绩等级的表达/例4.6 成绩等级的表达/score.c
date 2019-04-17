#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	char grade;
	scanf("%c", &grade);
	printf("You score is ");
	switch (grade) {
	case 'A': printf("85~100\n"); break;
	case 'B': printf("70~84\n"); break; 
	case 'C': printf("60~69\n"); break;
	case 'D': printf("<60\n"); break;
	default: printf("ÊäÈëÊý¾Ý´íÎó\n");
	}
	system("pause");
	return 0;
}