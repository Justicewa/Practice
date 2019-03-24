#include <stdio.h>
#include <stdlib.h>

int main(){
	int a[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9 };
	int to_find = 11;
	int mid;
	int left = 0;
	int right = sizeof(a) / sizeof(a[0]) - 1;
	while (left <= right) {
		mid = left + (right - left) / 2;
		if (a[mid] > to_find) {
			right = mid - 1;
		}
		else if (a[mid] < to_find) {
			left = mid + 1;
		}
		else{
			break;
		}
	}
	if (left <= right) {
		printf("找到了!\n");
	}
	else{
		printf("没有找到!\n");
	}

	system("pause");
	return 0;
}