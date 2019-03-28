#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//例3.1 温度的转换

//int main() {
//	double c;
//	double f;
//	printf("请输入一个华氏温度: \n");
//	scanf("%lf", &f);
//	c = (5.0 / 9)*(f - 32); //必须是5.0 因为5/9=0
//	printf("对应的摄氏度是:%lf \n",c);
//
//	system("pause");
//	return 0;
//}

//例3.2 

//int main() {
//	double p0 = 1000, r1 = 0.0036, r2 = 0.0225, r3 = 0.0198, p1, p2, p3;
//	p1 = p0*(1 + r1);
//	p2 = p0*(1 + r2);
//	p3 = p0*(1 + r3 / 2)*(1 + r3 / 2);
//	printf("p1=%f\np2=%f\np3=%f\n", p1, p2, p3);
//
//	system("pause");
//	return 0;
//}

//例3.3 大小写字母的转换

//int main() {
//	char c1='A', c2;
//	c2 = c1 + 32;
//	printf("%c\n", c2);
//
//	system("pause");
//	return 0;
//}

//例3.4  求三角形面积

//int main(){
//	double a, b, c;
//	double s,area;
//	printf("请输入三个边长:\n");
//	scanf("%lf %lf %lf", &a, &b, &c);
//	s = (a + b + c) / 2;
//	area = sqrt(s*(s - a)*(s - b)*(s - c));
//	printf("三角形面积为: %f\n", area);
//
//	system("pause");
//	return 0;
//}

//例3.5 求一元二次方程的根 

//int main() {	
//	double a, b, c;
//	double p, q;
//	scanf("%lf %lf %lf", &a, &b, &c);
//	p = (-1)*b/(2*a);
//	q = (sqrt(b*b - 4 * a*c)) / (2 * a);
//	printf("The first answer is:%f\nThe second answer is:%f\n", p + q, p - q);
//
//	system("pause");
//	return 0;
//}

//例3.8 purchar()的运用

//int main(){
//	char a = 'B', b = 'O', c = 'Y';
//	putchar(a);
//	putchar(b);
//	putchar(c);
//	putchar('\n');
//
//	system("pause");
//	return 0;
//}

//例3.10 在键盘上任意输入一个大写字母 输出对应的小写字母

int main(){
	char a;
	a = getchar();
	a = a + 32;
	printf("对应的小写字母是:%c\n", a);

	system("pause");
	return 0;
}



