#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu(){
	printf("****************\n");
	printf("**1.��ʼ��Ϸ��**\n");
	printf("**0.��Ϸ������**\n");
	printf("****************\n");
	printf("����һ��1-100����\n");
	printf("****************\n");
	int choise = 0;
	scanf("%d", &choise);
	return choise;
}

void Game() {
	//1.�������һ������(1-100)
	int to_guess = rand() % 100 + 1;
	//2.��ʾ�û�����һ������
	while (1){
		printf("������һ������:\n");
		int num = 0;
		scanf("%d", &num);
		//3.���û���������Ҫ�ҵ������бȽ�,���ݱȽϸ����û���ʾ
		if (num < to_guess) {
			printf("����!\n");
		}
		else if (num>to_guess) {
			printf("����!\n");
		}
		else{
			printf("��ϲ��,�����!\n");
			break;
		}
	}
}

int main(){
	
	//srand() �����������,����һ��


	//ʱ���
	//time�ķ���ֵ������һ�� time_t �з��ŵ�64λ�з�������
	//srand ���� �� �޷���32λ����
	srand((unsigned int)time(0));
	while (1) {
		int choise = Menu();
		if (choise == 1) {
			Game();
		}else if(choise==0){
			printf("Game over!\n");
			break;
		}
		else{
			printf("Wrong number!\n");
			break;
		}
	}

	system("pause");
	return 0;
}