#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//Ĭ�Ϸ���1 ������������ֵ��0 ����������
//int IsOdd(int x) {
//	if (x % 2 == 0) {
//		return 0;
//	}
//	return 1;
//}

int main() {
	int num = 0;
	int result = 0;

	result = num++;
	printf("num=%d\n", num);
	printf("result=%d\n", result);

	system("pause");
	return 0;
}