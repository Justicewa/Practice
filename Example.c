#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//��3.1 �¶ȵ�ת��

//int main() {
//	double c;
//	double f;
//	printf("������һ�������¶�: \n");
//	scanf("%lf", &f);
//	c = (5.0 / 9)*(f - 32); //������5.0 ��Ϊ5/9=0
//	printf("��Ӧ�����϶���:%lf \n",c);
//
//	system("pause");
//	return 0;
//}

//��3.2 

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

//��3.3 ��Сд��ĸ��ת��

//int main() {
//	char c1='A', c2;
//	c2 = c1 + 32;
//	printf("%c\n", c2);
//
//	system("pause");
//	return 0;
//}

//��3.4  �����������

//int main(){
//	double a, b, c;
//	double s,area;
//	printf("�����������߳�:\n");
//	scanf("%lf %lf %lf", &a, &b, &c);
//	s = (a + b + c) / 2;
//	area = sqrt(s*(s - a)*(s - b)*(s - c));
//	printf("���������Ϊ: %f\n", area);
//
//	system("pause");
//	return 0;
//}

//��3.5 ��һԪ���η��̵ĸ� 

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

//��3.8 purchar()������

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

//��3.10 �ڼ�������������һ����д��ĸ �����Ӧ��Сд��ĸ

int main(){
	char a;
	a = getchar();
	a = a + 32;
	printf("��Ӧ��Сд��ĸ��:%c\n", a);

	system("pause");
	return 0;
}



