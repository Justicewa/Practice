#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu(){
	printf("****************\n");
	printf("**1.开始游戏！**\n");
	printf("**0.游戏结束！**\n");
	printf("****************\n");
	printf("输入一个1-100的数\n");
	printf("****************\n");
	int choise = 0;
	scanf("%d", &choise);
	return choise;
}

void Game() {
	//1.随机生成一个数字(1-100)
	int to_guess = rand() % 100 + 1;
	//2.提示用户输入一个数字
	while (1){
		printf("请输入一个数字:\n");
		int num = 0;
		scanf("%d", &num);
		//3.拿用户的数字与要找的数进行比较,根据比较给予用户提示
		if (num < to_guess) {
			printf("低了!\n");
		}
		else if (num>to_guess) {
			printf("高了!\n");
		}
		else{
			printf("恭喜您,答对了!\n");
			break;
		}
	}
}

int main(){
	
	//srand() 这是随机种子,产生一个


	//时间戳
	//time的返回值类型是一个 time_t 有符号的64位有符号整数
	//srand 参数 是 无符号32位整数
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