#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

////查重函数 
//int checkpoint(int* player, int n){
//	int res = 0;
//	int i = 0;
//	for (; i < n; ++i){
//		res |= 1 << player[i];
//	}
//	return res == 0x3e;
//}
//
////遍历的过程就是给数组赋值的过程 然后if里面是其中的一种情况
//int main(){
//	int str[5] = { 0 };
//	for (str[0] = 1; str[0] < 6; ++str[0]){
//		for (str[1] = 1; str[1] < 6; ++str[1]){
//			for (str[2] = 1; str[2] < 6; ++str[2]){
//				for (str[3] = 1; str[3]<6; ++str[3]){
//					for (str[4] = 1; str[4] < 6; ++str[4]){
//							//A选手说：B第二，我第三；
//							//B选手说：我第二，E第四；
//							//C选手说：我第一，D第二；
//							//D选手说：C最后，我第三；
//							//E选手说：我第四，A第一；
//						if (   (str[1] == 2) + (str[0] == 3) == 1 && (str[1] == 2) + (str[4] == 4) == 1
//							&& (str[2] == 1) + (str[3] == 2) == 1 && (str[2] == 5) + (str[3] == 3) == 1
//							&& (str[4] == 4) + (str[0] == 1) == 1 && checkpoint(str,5) ){
//							printf(" a的名次是:%d\n b的名次是:%d\n c的名次是:%d\n d的名次是:%d\n e的名次是:%d\n"
//								, str[0], str[1], str[2], str[3], str[4]);
//
//						}
//					}
//				}
//			}
//		}
//	}
//
//	system("pause");
//	return 0;
//}


int main(){
	char murder='A';
		//A说：不是我。
		//B说：是C。
		//C说：是D。
		//D说：C在胡说
	for (murder; murder <= 'D'; ++murder){
		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3){
			printf("凶手是%c\n", murder);
		}
	}

	system("pause");
	return 0;
}


#include <stdio.h>
#include <stdlib.h>

int main(){

	int a[20][20] = { 0 };
	for (int i = 1; i < 6; i++){
		for (int j = 1; j < i; j++){
			if (i == 1){
				printf("%d \n", a[1][1] = 1);
			}
			else{
				if ((j == 1) || (i == j)){
					printf("%d ", a[i][j] = 1);
				}
				else{
					printf("%d ", a[i][j] = a[i - 1][j - 1] + a[i - 1][j]);
				}
			}
		}
		putchar('\n');
	}

	system("pause");
	return 0;
}