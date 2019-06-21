#include <stdio.h>


void PrintArray(int* array, int size)
{
	for (int i = 0; i < size; ++i)
		printf("%d ", array[i]);
	printf("\n");
}

void Swap(int* pLeft, int* pRight)
{
	int temp = *pLeft;
	*pLeft = *pRight;
	*pRight = temp;
}

void InsertSort(int* array, int size)
{
	for (int i = 1; i < size; ++i)
	{
		// 待插入元素
		int key = array[i];

		// 找key的插入位置：与前面已经排序好的元素从后往前比较
		int end = i - 1;
		while (end >= 0 && key < array[end])
		{
			array[end+1] = array[end];
			end -= 1;
		}

		// 插入元素
		array[end+1] = key;
	}
}

// O(N^1.25  ~ 1.6N^1.25)
void ShellSort(int* array, int size)
{
	int gap = 3;
	while (gap > 0)
	{
		for (int i = gap; i < size; ++i)
		{
			// 待插入元素
			int key = array[i];

			// 找key的插入位置：与前面已经排序好的元素从后往前比较
			int end = i - gap;
			while (end >= 0 && key < array[end])
			{
				array[end + gap] = array[end];
				end -= gap;
			}

			// 插入元素
			array[end + gap] = key;
		}

		gap -= 1;
	}
}

// 时间复杂度：O(N^2)
// 空间复杂度：O(1)
// 稳定性：不稳定
// 缺陷：进行重复比较
void SelectSort(int* array, int size)
{
	for (int i = 0; i < size - 1; i++)
	{
		int maxPos = 0;
		for (int j = 1; j < size - i; ++j)
		{
			if (array[j] > array[maxPos])
				maxPos = j;
		}

		if (maxPos != size-i-1)
			Swap(&array[maxPos], &array[size - i - 1]);
	}
}

// 时间复杂度：O(NlogN)
// 空间复杂度：O(1)
// 稳定性：不稳定
// 
void HeapSort(int* array, int size)
{
	// ...
}


// 冒泡排序
// 时间复杂度：O(N^2)
// 空间复杂度：O(1)
// 稳定性：稳定的
void BubbleSort(int* array, int size)
{
	//...
}


// a  b  c
int GetMiddleIndex(int* array, int left, int right)
{
	int mid = left + ((right - left) >> 1);
	if (array[left] < array[right - 1])
	{
		if (array[mid] < array[left])
			return left;
		else if (array[mid] > array[right - 1])
			return right - 1;
		else
			return mid;
	}
	else
	{
		if (array[mid] > array[left])
			return left;
		else if (array[mid] < array[right - 1])
			return right-1;
		else
			return mid;
	}
}

// [left, right)
int Partion1(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (begin < end)
	{
		// 从左往右找比基准值大的元素，找到之后停止
		while (begin < end && array[begin] <= key)
			begin++;

		// 从右往左找比基准值小的元素，找到之后停止
		while (begin < end && array[end] >= key)
			end--;

		if (begin != end)
			Swap(&array[begin], &array[end]);
	}

	if (begin != right - 1)
		Swap(&array[begin], &array[right - 1]);

	return begin;
}

int Partion2(int* array, int left, int right)
{
	int begin = left;
	int end = right - 1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);

	int key = array[right - 1];

	while (begin < end)
	{
		// 从前往后找比基准值大的元素，找到后填充end位置的坑
		while (begin < end && array[begin] <= key)
			begin++;

		// 填充end位置的坑
		if (begin < end)
		{
			array[end] = array[begin];
			end--;
		}

		// 从后往前找比基准值小的元素，找到后填充begin位置的坑
		while (begin < end && array[end] >= key)
			end--;

		if (begin < end)
		{
			array[begin] = array[end];
			begin++;
		}
	}

	array[begin] = key;
	return begin;
}

int Partion3(int* array, int left, int right)
{
	int cur = left;
	int prev = cur-1;
	int mid = GetMiddleIndex(array, left, right);
	Swap(&array[mid], &array[right - 1]);
	int key = array[right - 1];


	while (cur < right)
	{
		if (array[cur] < key && ++prev != cur)
			Swap(&array[cur], &array[prev]);

		++cur;
	}

	if (++prev != right)
		Swap(&array[prev], &array[right - 1]);

	return prev;
}

void QuickSort(int* array, int left, int right)
{
	if (right - left < 16)
		InsertSort(array, right - left);
	else
	{
		// 按照基准值将区间分割成左右两部分
		// 左侧小于基准值 基准值 右侧大于基准值
		int div = Partion1(array, left, right);
		QuickSort(array, left, div);
		QuickSort(array, div+1, right);
	}
}

#include "Stack.h"
void QuickSortNor(int* array, int size)
{
	int left = 0;
	int right = size;
	Stack s;
	StackInit(&s);
	StackPush(&s, right);
	StackPush(&s, left);

	while (!StackEmpty(&s))
	{
		left = StackTop(&s);
		StackPop(&s);
		right = StackTop(&s);
		StackPop(&s);

		if (right - left > 1)
		{
			int div = Partion3(array, left, right);

			// 保存右半部分区间
			StackPush(&s, right);
			StackPush(&s, div + 1);

			// 保存左半部分区间
			StackPush(&s, div);
			StackPush(&s, left);
		}
	}
}


void SelectSortOP(int* array, int size)
{
	// []
	int begin = 0;
	int end = size-1;

	while (begin < end)
	{
		int maxPos = begin;
		int minPos = begin;

		int index = begin + 1;
		while (index <= end)
		{
			if (array[index] > array[maxPos])
				maxPos = index;

			if (array[index] < array[minPos])
				minPos = index;

			++index;
		}

		if (maxPos != end)
			Swap(&array[maxPos], &array[end]);

		// 注意：如果在放大元素之前，小元素刚好在end的位置
		//必须更新minPos的位置  因为小元素位置已经发生改变
		if (minPos == end)
			minPos = maxPos;

		if (minPos != begin)
			Swap(&array[minPos], &array[begin]);

		begin++;
		end--;
	}
}


#include <malloc.h>
#include <assert.h>
#include <string.h>

void MergeData(int* array, int left, int mid, int right, int* temp)
{
	int begin1 = left, end1 = mid;
	int begin2 = mid, end2 = right;
	int index = left;

	while (begin1 < end1 && begin2 < end2)
	{
		if (array[begin1] < array[begin2])
			temp[index++] = array[begin1++];
		else
			temp[index++] = array[begin2++];
	}

	while (begin1 < end1)
		temp[index++] = array[begin1++];

	while (begin2 < end2)
		temp[index++] = array[begin2++];
}

void _MergeSort(int* array, int left, int right, int* temp)
{
	if (right - left > 1)
	{
		int mid = left + ((right - left) >> 1);
		// [left, mid)
		// [mid, right)
		_MergeSort(array, left, mid, temp);
		_MergeSort(array, mid, right, temp);
		MergeData(array, left, mid, right, temp);
		memcpy(array+left, temp+left, sizeof(int)*(right-left));
	}
}

void MergeSort(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	_MergeSort(array, 0, size, temp);

	free(temp);
}

void MergeSortNor(int* array, int size)
{
	int* temp = (int*)malloc(sizeof(int)*size);
	if (NULL == temp)
	{
		assert(0);
		return;
	}

	int gap = 1;
	while (gap < size)
	{
		for (int i = 0; i < size; i += 2 * gap)
		{
			int left = i;
			int mid = left + gap;
			int right = mid + gap;

			if (mid >= size)
				mid = size;

			if (right >= size)
				right = size;
			MergeData(array, left, mid, right, temp);
		}

		memcpy(array, temp, sizeof(int)*size);
		gap *= 2;
	}
	
	free(temp);
}

// 时间复杂度：O(N)--->N代表元素个数
// 空间复杂度：O(M)--->M:数据范围
void CountSort(int* array, int size)
{
	// 1. 找数据范围
	int minValue = array[0];
	int maxValue = array[0];
	for (int i = 1; i < size; ++i)
	{
		if (array[i] > maxValue)
			maxValue = array[i];

		if (array[i] < minValue)
			minValue = array[i];
	}

	int range = maxValue - minValue + 1;
	//int* pCount = calloc(range, sizeof(int));
	int* pCount = (int*)malloc(sizeof(int)*range);
	memset(pCount, 0, sizeof(int)*range);

	if (NULL == pCount)
	{
		assert(0);
		return;
	}

	// 统计每个元素出现的次数
	for (int i = 0; i < size; ++i)
		pCount[array[i]-minValue]++;

	// 排序(对pCount中的元素进行回收)
	int index = 0;
	for (int i = 0; i < range; ++i)
	{
		while (pCount[i])
		{
			array[index++] = i + minValue;
			pCount[i]--;
		}
	}

	free(pCount);
}

