#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
int main() {
	char ch;
	printf("������һ����ĸ:\n");
	scanf("%c", &ch);
	ch = (ch >= 'A'&&ch <= 'Z'  ) ? (ch + 32) : ch; //���б��ʽ�����ã����ch��ֵΪ��д��ĸ�����������ʽ��ֵΪ��ch+32������Сд��ĸ�����򲻱�
	printf("%c\n", ch);
	system("pause");
	return 0;
}