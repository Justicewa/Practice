#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int main(){
	int i = 0, j = 0;
	printf("������һ��С��1000������");
	scanf("%d", &i);
	if (i <= 1000){
		j = sqrt(i);
		printf("%d", j);
	}
	else{
		printf("������һ��С��1000����\n");
	}
	system("pause");
	return 0;
}