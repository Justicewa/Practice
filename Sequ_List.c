#include "Seq_List.h"
#include <stdio.h>
#include <malloc.h>
#include <assert.h>

void SeqListInit(SeqList* ps,int capacity){
	ps->_array = (DataType*)malloc(sizeof(DataType)*capacity);
	if (ps->_array == NULL){
		assert(0);
		return;
	}
	ps->_capacity = capacity;
	ps->_size = 0;
}

void SeqListPushBack(PSeq ps, DataType data){
	assert(ps);
	
	//顺序表满

	ps->_array[ps->_size] = data;
	ps->_size++;
}
void SeqListPopBack(PSeq ps){
	assert(ps);
	if (SeqListEmpty(ps)){
		return;
	}
	ps->_size--;
}

void SeqListPushFront(PSeq ps, DataType data){
	assert(ps);
	//CheckCapacity(ps);
	//将顺序表中所有元素统一向后搬移一个位置
	for (int i = ps->_size - 1; i >= 0; i--){
		ps->_array[i + 1] = ps->_array[i];
	}
	//插入元素
	ps->_array[0] = data;
	++ps->_size;
}
void SeqListPopFront(PSeq ps){
	assert(ps);
	if (SeqListEmpty(ps)){
		return;
	}
	for (int i = 1; i < ps->_size; ++i){
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}


void SeqListInsert(PSeq ps, int pos, DataType data){
	assert(ps);
	if (pos<0 || pos>ps->_size){
		return;
	}
	//CheckCapacity
	for (int i = ps->_size - 1; i >= pos; i--){
		ps->_array[i + 1] = ps->_array[i];
	}
	ps->_array[pos] = data;
	ps->_size++;
}

void SeqListErase(PSeq ps, int pos){
	assert(ps);
	if (pos < 0 || pos >= ps->_size){
		return;
	}
	for (int i = pos + 1; i < ps->_size; ++i){
		ps->_array[i - 1] = ps->_array[i];
	}
	ps->_size--;
}

int SeqListFind(PSeq ps, DataType data){
	assert(0);
	for (int i = 0; i < ps->_size; ++i){
		if (ps->_array[i] == data){
			return i;
		}
	}
	return -1;
}

int SeqListSize(PSeq ps){
	assert(ps);
	return ps->_size;
}

int SeqListCapacity(PSeq ps){
	assert(ps);
	return ps->_capacity;
}

void SeqListClear(PSeq ps){
	assert(ps);
	ps->_size = 0;
}

int SeqListEmpty(PSeq ps){
	assert(ps);
	return 0 == ps->_size;

}

void SeqListRemove(PSeq ps, DataType data){
	SeqListErase(ps, SeqListFind(ps, data));
}

void SeqListCheckCapacity(PSeq ps){
	assert(ps);
	if (ps->_size == ps->_capacity){
		int newCapacity = ps->_capacity * 2;
		//申请新空间
		int* pTemp = (DataType*)malloc(newCapacity*(newCapacity*sizeof(DataType)));
		if (pTemp == NULL){
			assert(0);
			return;
		}//拷贝元素
		for (int i = 0; i < ps->_size; ++i){
			pTemp[i] = ps->_array[i];
			//释放旧空间
			free(ps->_array);
			//更新参数
			ps->_array = pTemp;
			ps->_capacity = newCapacity;
		}
	}
}

void SeqListDestory(SeqList* ps){
	if (ps->_array){
		free(ps->_array);
		ps->_array=0;
		ps->_capacity = 0;
		ps->_size=0;
	}
}

void SeqListPrint(PSeq ps){
	for (int i = 0; i < ps->_size; ++i){
		printf("%d", ps->_array[i]);
	}
	putchar('\n');
}

void TestSeqList(){
	SeqList s;
	SeqListInit(&s,10);
	SeqListDestory(&s);
	SeqListPushBack(&s, 1);
	SeqListPushBack(&s, 2);
	SeqListPushBack(&s, 3);
	SeqListPushBack(&s, 4);
	SeqListPushBack(&s, 5);
	SeqListPrint(&s);

	SeqListPopBack(&s);
	SeqListPrint(&s);

	SeqListPushFront(&s, 0);
	SeqListPrint(&s);

	SeqListPopFront(&s);
	SeqListPrint(&s);
}
int main(){

	TestSeqList();
		return 0;
	}