#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu(){
	printf("*********************\n");
	printf("*****1.��ʼ��Ϸ!*****\n");
	printf("*****0.������Ϸ!*****\n");
	printf("*********************\n");
	printf("***����������ѡ��!***\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char Show_Map[MAX_ROW][MAX_COL], char Mine_Map[MAX_ROW][MAX_COL]){
	//1.����show_map ȫ������Ϊ *
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			Show_Map[row][col] = '*';
		}
	}
	//2.����mine_map,��Ҫ����������ɸ�����
	//  0��ʾ���ǵ���,1��ʾ�ǵ���;
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			Mine_Map[row][col] = '0';
		}
	}
	int n = MINE_COUNT;
	while (n>0){
		//����һ���������
		int row = rand() % MAX_ROW;
		int col = rand() % MAX_COL;
		if (Mine_Map[row][col] == '1'){
			continue;
		}
		Mine_Map[row][col] = '1';
		--n;
	}
}

void PrintMap(char map[MAX_ROW][MAX_COL]){
	//�����ӡ���� ����ӡ����
	//�ȴ�ӡ��һ��
	printf("    ");
	for (int col = 0; col < MAX_COL; ++col){
		printf("%d ", col);
	}
	putchar('\n');
	printf("   ------------------\n");
	for (int row = 0; row < MAX_ROW; ++row){
		printf(" %d| ", row);
		for (int col = 0; col < MAX_COL; ++col){
			printf("%c ", map[row][col]);
		}
		printf("\n");
	}
}
		
void UpdateShowMap(int row, int col, char show_map[MAX_ROW][MAX_COL],char mine_map[MAX_ROW][MAX_COL]){
	//���ݵ�ǰλ���ж���ǰλ����Χ�˸�������Χ�м�������,�����µ�show_map��
	int count = 0;
	if (row-1< MAX_ROW && col-1<MAX_COL && row - 1 >= 0 && col - 1 >= 0 && mine_map[row - 1][col - 1] == '1'){
		++count;
	}
	if (row - 1< MAX_ROW && col <MAX_COL && row - 1 >= 0 && col >= 0 && mine_map[row - 1][col] == '1'){
		++count;
	}
	if (row - 1< MAX_ROW && col + 1<MAX_COL && row - 1 >= 0 && col + 1 >= 0 && mine_map[row - 1][col + 1] == '1'){
		++count;
	}
	if (row < MAX_ROW && col - 1<MAX_COL && row >= 0 && col - 1 >= 0 && mine_map[row][col - 1] == '1'){
		++count;
	}
	if (row < MAX_ROW && col + 1<MAX_COL && row >= 0 && col + 1 >= 0 && mine_map[row][col + 1] == '1'){
		++count;
	}
	if (row + 1< MAX_ROW && col - 1<MAX_COL && row + 1 >= 0 && col - 1 >= 0 && mine_map[row + 1][col - 1] == '1'){
		++count;
	}
	if (row + 1< MAX_ROW && col <MAX_COL && row + 1 >= 0 && col >= 0 && mine_map[row + 1][col] == '1'){
		++count;
	}
	if (row + 1< MAX_ROW && col + 1<MAX_COL && row + 1 >= 0 && col + 1 >= 0 && mine_map[row + 1][col + 1] == '1'){
		++count;
	}
	//�õ��˵��׸���
	//����countΪ2 ,ʵ���뿴�������ַ�'2', Ҳ����assic�������
	show_map[row][col] = '0'+ count;
}

void Game(){
	//1.������ͼ,����ʼ��
	char Show_Map[MAX_ROW][MAX_COL];
	char Mine_Map[MAX_ROW][MAX_COL];
	Init(Show_Map, Mine_Map);
	//�Ѿ������Ŀո�ĸ���
	int blank_count_already_show = 0;
	while (1){
		//��ӡ��ͼ
		PrintMap(Show_Map);
		//PrintMap(Mine_Map);
		printf("������һ������(row,col):\n");
		//�������� �����м��
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//����
		system("cls");
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("��������Ƿ�,�������!\n");
			continue;
		}
		if (Show_Map[row][col] != '*'){
			printf("��λ���Ѿ�������!\n");
			continue;
		}
		if (Mine_Map[row][col] == '1'){
			printf("���е�����!!!\n");
			PrintMap(Mine_Map);
			break;
		}
		//�ж���Ϸ�Ƿ�ʤ��
		// �ǵ��׶�������
		++blank_count_already_show;
		if (blank_count_already_show == MAX_ROW*MAX_COL - MINE_COUNT){
			printf("��Ϸʤ��!\n");
			PrintMap(Mine_Map);
			break;
		}
		//ͳ�Ƶ�ǰλ����Χ�׵ĸ���
		UpdateShowMap(row,col,Show_Map,Mine_Map);
	}
}

int main(){
	int choice = Menu();
	while (1){
		if (choice == 1){
			Game();
		}
		else if (choice == 0){
			printf("Game over!\n");
			break;
		}
		else{
			printf("������������!\n");
		}
	}

	system("pause");
	return 0;
}