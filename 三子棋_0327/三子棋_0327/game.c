#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu(){
	printf("+++++++++++++++++\n");
	printf("1.��ʼ��Ϸ\n");
	printf("0.������Ϸ\n");
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
	printf("�������\n");

	while (1){
		printf("��������������(row col)\n");
		int row = 0, col = 0;
		scanf("%d %d", &row, &col);
		if (row < 0 || row >= MAX_ROW || col<0 || col>MAX_COL){
			printf("������������,���������\n");
			continue;
		}
		if (chess_board[row][col] != ' '){
			printf("��λ���ѱ�ռ��!\n");
			continue;
		}
		chess_board[row][col] = 'x';
		break;
	}

	printf("������ӽ���\n");
}

void ComputerMove(){
	printf("��������!\n");
	while (1){
		int row = rand() % 3;
		int col = rand() % 3;
		if (chess_board[row][col] != ' '){
			continue;
		}
		chess_board[row][col] = 'o';
		break;
	}
	printf("�����������!\n");
}

//������˷���1 ���򷵻�0
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

// xΪ��һ�ʤ
// oΪ���Ի�ʤ
// q��ʾ����
// ' 'ʤ��δ��
char WinnerCheck(){
	//�г���
	for (int row = 0; row < MAX_ROW; ++row){
		if (chess_board[row][0] == chess_board[row][1] && chess_board[row][0] == chess_board[row][2]){
			return chess_board[row][0];
		}
	}
	//�г���
	for (int col = 0; col < MAX_COL; ++col){
		if (chess_board[0][col] == chess_board[1][col] && chess_board[0][col] == chess_board[2][col]){
			return chess_board[0][col];
		}
	}
	//�Խǳ���
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
	//1. ��ʼ������
	Init();
	char winner = ' ';
	while (1){
		//2. ��ӡ����
		Print();
		//3. �������
		PlayerMove();
		//4. ���ʤ��
		winner = WinnerCheck();
		if (winner != ' '){
			break;
		}
		//5. ��������
		ComputerMove();
		//6. ���ʤ��
		winner = WinnerCheck();
		if (winner != ' '){
			break;
		}
		system("cls");
	}
	
	Print();
	if (winner == 'x'){
		printf("��Ӯ��!\n");
	}
	else if (winner == 'o'){
		printf("������!\n");
	}
	else if (winner == 'q'){
		printf("ƽ��!\n");
	}
	else{
		printf("����BUG!\n");
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
			printf("������������!\n");
		}
	}

	system("pause");
	return 0;
}