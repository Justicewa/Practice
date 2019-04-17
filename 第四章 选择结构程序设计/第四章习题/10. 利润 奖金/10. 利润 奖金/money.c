#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

//£®1£©”√if”Ôæ‰±‡–¥≥Ã–Ú
int main(){
	double I = 0,award=0;
	scanf("%lf",&I);
	if (I <= 100000) {
		award = I * 0.1;
		printf("%f", award);
	}
	if (I > 100000 && I <= 200000) {
		award = 100000 * 0.1 + (I - 100000)*0.075;
		printf("%f", award);
	}
	if (I > 200000 && I <= 400000) {
		award = 100000 * 0.1 + 100000 * 0.075 + (I - 200000)*0.05;
		printf("%f", award);
	}
	if (I > 400000 && I <= 600000) {
		award = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + (I - 400000)*0.03;
		printf("%f", award);
	}
	if (I > 600000 && I <= 1000000) {
		award = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + (I - 600000)*0.015;
		printf("%f", award);
	}
	if (I > 600000 && I <= 1000000) {
		award = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 + (I - 600000)*0.015;
		printf("%f", award);
	}
	if (I > 1000000) {
		award = 100000 * 0.1 + 100000 * 0.075 + 200000 * 0.05 + 200000 * 0.03 +400000*0.015+(I-1000000)*0.01;
		printf("%f", award);
	}
	system("pause");
	return 0;
}

char a(int x) {

}

int main() {
	double I = 0, award = 0;
	scanf("%lf", &I);
	swtich(){
		case ''
	}
}