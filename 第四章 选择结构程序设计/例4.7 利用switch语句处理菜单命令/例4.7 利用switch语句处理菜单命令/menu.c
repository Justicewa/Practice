#include <stdio.h>
#include <stdlib.h>

void action1(int x, int y) {
	printf("x+y=%d\n",x+y);
}
void action2(int x, int y) {
	printf("x*y=%d\n", x*y);
}
int main() {
	char ch;
	int a = 5, b = 3;
	ch = getchar();
	switch (ch){
	case 'a' :
	case 'A': action1(a, b); break;
	case 'b' :
	case 'B': action2(a, b); break;
	default : putchar('\a');
	}
	system("pause");
	return 0;
};