#define NUM 13
#define FETCH 1000
#define RATE 0.0171
#include <stdio.h>
#include <stdlib.h>

//쳲���������
//int main() {
//	int i;
//	long fib[NUM] = { 1, 1 };//���ڱ������ӵĳ�ʼ���ݺ�ÿ�µ�����
//	for (i = 2; i < NUM; i++) {
//		fib[i] = fib[i - 1] + fib[i - 2];
//	}
//	for (i = 0; i < NUM; i++) {
//		printf("��%d�µ�����������:  %d\n",i, fib[i]);
//	}
//
//	system("pause");
//	return 0;
//}

//���д������
//int main() {
//	double corpus[49];
//	int i;
//	corpus[48] = (double)FETCH;
//	for (i = 47; i > 0; i--) {
//		corpus[i] = (corpus[i + 1] + FETCH) / (1 + RATE / 12);
//	}
//	for (i = 48; i > 0; i--) {
//		printf("%d����ĩ��������: %.2f\n", i, corpus[i]);
//	}
//
//	system("pause");
//	return 0;
//}

//��ŵ��
move(int n, int x, int y, int z) {
	if (n == 1) {
		printf("%c-->%c\n", x, z);
	}
	else {
		move(n - 1, x, y, z);
		printf("%c-->%c\n", x, z);
		{
			getchar(); }
		move(n - 1, y, x, z);
	}
	}

int main() {


	system("pause");
	return 0;
}