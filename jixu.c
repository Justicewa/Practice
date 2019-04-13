#include <stdio.h>
#include <stdlib.h>

int main(){
	int i,j;
	for (i = 1; i <= 7; i++){
		for (j = 1; j <= 2 * i - 1;j++){
			printf("*");
		}
		putchar('\n');
	}
	for (i = 6; i >= 1; i--) {
		for (j = 9; j >= 11 - 2 * i; j--){
			printf("*");
		}
		putchar('\n');
	}

	system("pause");
	return 0;
}


int main() {
	int i, a, b, c;
	for (i = 100; i <= 999; i++) {
		a = i % 10;
		b = i / 10 % 10;
		c = i / 100;
		if ((a*a*a + b*b*b + c*c*c) == i){
			printf("%d\n", i);
		}
	}
	system("pause");
	return 0;
}

int main() {
	int i, j = 1, Sn = 2, sum = 2;;
	for (i = 1; i < 5; i++) {
		j *= 10 ;
		Sn += j*2;
		printf("%d\n", Sn);
		sum += Sn;
	}
	printf("%d", sum);

	system("pause");
	return 0;
}