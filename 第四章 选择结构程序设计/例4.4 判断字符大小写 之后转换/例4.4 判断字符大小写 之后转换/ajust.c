#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	char ch;
	printf("请输入一个字母:\n");
	scanf("%c", &ch);
	ch = (ch >= 'A'&&ch <= 'Z'  ) ? (ch + 32) : ch; //这行表达式的作用：如果ch的值为大写字母，则条件表达式的值为（ch+32），即小写字母，否则不变
	printf("%c\n", ch);
	system("pause");
	return 0;
}