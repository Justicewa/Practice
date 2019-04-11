#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int Menu(){
	printf("*********************\n");
	printf("*****1.开始游戏!*****\n");
	printf("*****0.结束游戏!*****\n");
	printf("*********************\n");
	printf("***请输入您的选择!***\n");
	int choice = 0;
	scanf("%d", &choice);
	return choice;
}

#define MAX_ROW 9
#define MAX_COL 9
#define MINE_COUNT 10

void Init(char Show_Map[MAX_ROW][MAX_COL], char Mine_Map[MAX_ROW][MAX_COL]){
	//1.对于show_map 全都设置为 *
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			Show_Map[row][col] = '*';
		}
	}
	//2.对于mine_map,需要随机生成若干个地雷
	//  0表示不是地雷,1表示是地雷;
	for (int row = 0; row < MAX_ROW; ++row){
		for (int col = 0; col < MAX_COL; ++col){
			Mine_Map[row][col] = '0';
		}
	}
	int n = MINE_COUNT;
	while (n>0){
		//生成一组随机坐标
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
	//不光打印格子 还打印坐标
	//先打印第一行
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
	//根据当前位置判定当前位置周围八个格子周围有几个地雷,并更新到show_map中
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
	//得到了地雷个数
	//假设count为2 ,实际想看到的是字符'2', 也就是assic码里面的
	show_map[row][col] = '0'+ count;
}

void Game(){
	//1.创建地图,并初始化
	char Show_Map[MAX_ROW][MAX_COL];
	char Mine_Map[MAX_ROW][MAX_COL];
	Init(Show_Map, Mine_Map);
	//已经翻开的空格的个数
	int blank_count_already_show = 0;
	while (1){
		//打印地图
		PrintMap(Show_Map);
		//PrintMap(Mine_Map);
		printf("请输入一组坐标(row,col):\n");
		//输入坐标 并进行检测
		int row = 0;
		int col = 0;
		scanf("%d %d", &row, &col);
		//清屏
		system("cls");
		if (row < 0 || row >= MAX_ROW || col < 0 || col >= MAX_COL){
			printf("您的输入非法,重新输吧!\n");
			continue;
		}
		if (Show_Map[row][col] != '*'){
			printf("该位置已经翻开了!\n");
			continue;
		}
		if (Mine_Map[row][col] == '1'){
			printf("踩中地雷啦!!!\n");
			PrintMap(Mine_Map);
			break;
		}
		//判定游戏是否胜利
		// 非地雷都翻开了
		++blank_count_already_show;
		if (blank_count_already_show == MAX_ROW*MAX_COL - MINE_COUNT){
			printf("游戏胜利!\n");
			PrintMap(Mine_Map);
			break;
		}
		//统计当前位置周围雷的个数
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
			printf("您的输入有误!\n");
		}
	}

	system("pause");
	return 0;
}