#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

////���غ��� 
//int checkpoint(int* player, int n){
//	int res = 0;
//	int i = 0;
//	for (; i < n; ++i){
//		res |= 1 << player[i];
//	}
//	return res == 0x3e;
//}
//
////�����Ĺ��̾��Ǹ����鸳ֵ�Ĺ��� Ȼ��if���������е�һ�����
//int main(){
//	int str[5] = { 0 };
//	for (str[0] = 1; str[0] < 6; ++str[0]){
//		for (str[1] = 1; str[1] < 6; ++str[1]){
//			for (str[2] = 1; str[2] < 6; ++str[2]){
//				for (str[3] = 1; str[3]<6; ++str[3]){
//					for (str[4] = 1; str[4] < 6; ++str[4]){
//							//Aѡ��˵��B�ڶ����ҵ�����
//							//Bѡ��˵���ҵڶ���E���ģ�
//							//Cѡ��˵���ҵ�һ��D�ڶ���
//							//Dѡ��˵��C����ҵ�����
//							//Eѡ��˵���ҵ��ģ�A��һ��
//						if (   (str[1] == 2) + (str[0] == 3) == 1 && (str[1] == 2) + (str[4] == 4) == 1
//							&& (str[2] == 1) + (str[3] == 2) == 1 && (str[2] == 5) + (str[3] == 3) == 1
//							&& (str[4] == 4) + (str[0] == 1) == 1 && checkpoint(str,5) ){
//							printf(" a��������:%d\n b��������:%d\n c��������:%d\n d��������:%d\n e��������:%d\n"
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
		//A˵�������ҡ�
		//B˵����C��
		//C˵����D��
		//D˵��C�ں�˵
	for (murder; murder <= 'D'; ++murder){
		if ((murder != 'A') + (murder == 'C') + (murder == 'D') + (murder != 'D') == 3){
			printf("������%c\n", murder);
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