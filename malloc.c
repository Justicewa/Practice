#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

#if 0
int main(){
	int i, n;
	char* buffer;
	printf("How long do you want the string?");
	scanf("%d", &i);
	buffer = (char*)malloc(i + 1);
	if (buffer == NULL){
		return -1;
	}
	for (n = 0; n < i; n++){
		buffer[n] = rand() % 26 + 'a';
		buffer[i] = '\0';
	}
	printf("Random string:%s\n", buffer);
	free(buffer);
		
	system("pause");
	return 0;
}
#else 

int main(){

}

#endif

}