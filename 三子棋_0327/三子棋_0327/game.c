#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu(){
	printf("+++++++++++++++++\n");
	printf("1.开始游戏\n");
	printf("0.结束游戏\n");
	printf("+++++++++++++++++\n");
	int choise = 0;
	scanf("%d", &choise);
	return choise;
}

#define MAX_ROW 3
#define MAX_COL 3

char chess_board[MAX_ROW][MAX_COL];

void Init(){
	for (int row = 0; row < MAX_ROW; ++row) {
		for (int col = 0; col < MAX_COL; ++col){
			chess_board[row][col] = ' ';
		}
	}
	srand((unsigned int)time(0));
}

void Print(){
	for (int row = 0; row < MAX_ROW; ++row) {
		printf("| %c | %c | %c |\n", chess_board[row][0], chess_board[row][1], chess_board[row][2]);
		if (row != MAX_ROW - 1){
			printf("|---|---|---|\n");
		}
	}
	
	//TODO
	//system("pause");
}

void PlayerMove(){
	printf("玩家落子\n");

	while (1){
		printf("请输入落子坐标(row col)\n");
		int row = 0, col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col<0 || col>MAX_COL){
			printf("输入坐标有误,请从新输入\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("该位置已被占用!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}

	printf("玩家落子结束\n");
}

void ComputerMove(){
	printf("电脑落子!\n");
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("电脑落子完毕!\n");
}

//如果满了返回1 否则返回0
int IsFull(){
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			if (chess_board[row][col] == ' '){
				return 0;
			}
		}
	}
	return 1;
}

// x为玩家获胜
// o为电脑获胜
// q表示和棋
// ' '胜负未分
char WinnerCheck(){
	//行成线
	for (int row = 0; row < MAX_ROW; ++row){
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//列成线
	for (int col = 0; col < MAX_COL; ++col){
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//对角成线
	if (chess_board[0][0] == chess_board[1][1] && chess_board[0][0] == chess_board[2][2]){
		return chess_board[0][0];
	}
	if (chess_board[0][2] == chess_board[1][1] && chess_board[0][2] == chess_board[2][0]){
		return chess_board[0][2];
	}
	if (IsFull()){
		return 'q';
	}
	return ' ';
}

void Game(){
	//1. 初始化棋盘
	Init();
	char winner = ' ';
	while (1){
		//2. 打印棋盘
		Print();
		//3. 玩家落子
		PlayerMove();
		//4. 检测胜负
		winner = WinnerCheck();
		if (winner != ' '){
			break;
		}
		//5. 电脑落子
		ComputerMove();
		//6. 检测胜负
		winner = WinnerCheck();
		if (winner != ' '){
			break;
		}
		system("cls");
	}
	
	Print();
	if (winner == 'x'){
		printf("您赢了!\n");
	}
	else if (winner == 'o'){
		printf("您输了!\n");
	}
	else if (winner == 'q'){
		printf("平局!\n");
	}
	else{
		printf("代码BUG!\n");
	}
	
}

int main(){
	
	while (1){
		int choice = Menu();
		if (choice == 1){
			Game();
		}
		else if(choice == 0){
			printf("goodbye\n");
			break;
		}
		else {
			printf("您的输入有误!\n");
		}
	}

	system("pause");
	return 0;
}