#include <stdio.h>
#include <stdlib.h>

//百钱买鸡
//经过读题得知约束条件是通过鸡和钱的总数确定的.
int main() {
	int x, y, z;// 公鸡5元,母鸡3元,小鸡.
	for (x = 0; x < 21; x++) {
		for (y = 0; y < 34; y++){
			z = 100 - x - y;// 这一步的意思是什么?
			if (z % 3 == 0 && x * 5 + y * 3 + z / 3 == 100) {
				printf("公鸡: %d\n,母鸡: %d\n,小鸡: %d\n",x,y,z);
			}
		}
	}

	system("pause");
	return 0;
}
// 太笨了 不搞