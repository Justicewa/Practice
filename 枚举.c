#include <stdio.h>
#include <stdlib.h>

//��Ǯ��
//���������֪Լ��������ͨ������Ǯ������ȷ����.
int main() {
	int x, y, z;// ����5Ԫ,ĸ��3Ԫ,С��.
	for (x = 0; x < 21; x++) {
		for (y = 0; y < 34; y++){
			z = 100 - x - y;// ��һ������˼��ʲô?
			if (z % 3 == 0 && x * 5 + y * 3 + z / 3 == 100) {
				printf("����: %d\n,ĸ��: %d\n,С��: %d\n",x,y,z);
			}
		}
	}

	system("pause");
	return 0;
}
// ̫���� ����