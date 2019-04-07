#define NUM 13
#define FETCH 1000
#define RATE 0.0171
#include <stdio.h>
#include <stdlib.h>

//斐波那契数列
//int main() {
//	int i;
//	long fib[NUM] = { 1, 1 };//用于保存兔子的初始数据和每月的总数
//	for (i = 2; i < NUM; i++) {
//		fib[i] = fib[i - 1] + fib[i - 2];
//	}
//	for (i = 0; i < NUM; i++) {
//		printf("第%d月的兔子总数是:  %d\n",i, fib[i]);
//	}
//
//	system("pause");
//	return 0;
//}

//银行存款问题
//int main() {
//	double corpus[49];
//	int i;
//	corpus[48] = (double)FETCH;
//	for (i = 47; i > 0; i--) {
//		corpus[i] = (corpus[i + 1] + FETCH) / (1 + RATE / 12);
//	}
//	for (i = 48; i > 0; i--) {
//		printf("%d月月末本利共计: %.2f\n", i, corpus[i]);
//	}
//
//	system("pause");
//	return 0;
//}

//汉诺塔
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