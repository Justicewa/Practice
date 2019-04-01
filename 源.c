#include <stdio.h>
#include <stdlib.h>
//交换两个数组的内容
//int main(){
//	char a[] = "renyoutong";
//	char b[] = "gnotuoyner";
//	printf("a: %s\n", a);
//	printf("b: %s\n", b);
//	char c = '0';
//	for (int i = 0; i < 10; i++) {
//		c = a[i];
//		a[i] = b[i];
//		b[i] = c;
//	}
//	printf("a :%s\nb:%s\n", a, b);
//
//	system("pause");
//	return 0;
//}

//分式相加
//#include <stdio.h>
//#include <stdlib.h>
//int main() {
//	int sign = 1;
//	double j=0;                                               //令 j 为分母
//	double sum = 1;
//	for (j=2; j < 101; j++) {
//		sign = (-1)*sign;
//		sum = sum + sign*(1 / j);
//	}
//	printf("结果是:%f\n", sum);
//	system("pause");
//	return 0;
//}

总结9的个数
#include <stdio.h>
#include <stdlib.h>
int main() {
	int j = 0;
	for (int i = 1; i < 101; i++) {
		if (i % 10 == 9 || i%100>=90) {
			 j += 1;	
		}
	}
	printf("一共有%d个数字出现9\n", j);

	system("pause");
	return 0;
}

//9的 个数

int main() {
	int i = 1,k = 0;
	for (i = 1; i <= 100; i++) {
		if ((i % 10 == 9)||(i/9==10)) {
			k += 1;
		}
	}
	printf("9的个数是:%d \n", k);
	system("pause");
	return 0;
}