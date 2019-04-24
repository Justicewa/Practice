#include <stdio.h>
#include <stdlib.h>
#include "muji.h"

void SeqListInit(PSeq ps, int capacity){
	ps->array = (DataType*)malloc(ps->size * sizeof(DataType));
	if (ps->array = NULL){
		return -1;
	}
	ps->capacity = MAX;
	ps->size = 0;

}

void SeqListInsert(PSeq ps, int pos, DataType data){
	if (pos<0 || pos>ps->capacity){
		return -1;
	}
	if (ps->size > ps->capacity){
		
	}

}

int main(){
	void SeqListInit(PSeq ps, int capacity);

	system("pause");
	return 0;
}