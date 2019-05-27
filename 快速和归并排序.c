void Swap(int array[], int a, int b){
	int t = array[a];
	array[a] = array[b];
	array[b] = t;
}


/*
快速排序
	1.选择基准值
		1.选最边上
		2.随机	3.三数取中,把基准值交换到边上
	2.遍历整个区间,做 Partition ,小左大右
		1.Hover	2.挖坑	3.前后下标
	3.针对左右两个区间,分治算法
		直到区间的size == 0 || size == 1(有序)
*/

/*
				最好					平均					最坏
时间复杂度		O(n * log(n))			O(n * log(n))			O(n^2)
空间复杂度		O(log(n))				O(log(n))				O(n)	
稳定性:不稳定			
*/

//快排大框架
void QuickSortInner(int array[], int left, int right){
	if(left >= right){
		return;
	}
	
	
	
	//1.确定基准值,选择最后面的数作为基准值,为 pivot = array[right]
	//2.遍历区间,左小右大两部分,并返回最终基准值所在的下标
	int d = Partition(array, left, right);
	//3.分治两个小区间
	QuickSortInner(array,left,d-1);
	QuickSortInner(array,d+1,right);
}

/*
Partition实现
1.Hover [left, begin] <= pivot
2.挖坑	[end, right] >= pivot
3.前后下标
*/

/*
				最好					平均					最坏
时间复杂度		O(n * log(n))			O(n * log(n))			O(n^2)
空间复杂度		O(log(n))				O(log(n))				
*/

int Partition_1(int array[], int left, int right){
	int begin = left; //[left, begin] 保证 <= pivot
	int end = right;  //[end, right] 保证 >= pivot
	int pivot = array[right];
	
	while(begin < end){
		while(begin < end && array[begin] <= pivot){
			begin++;
		}
		
		while(begin < end && array[end] >= pivot){
			end--;
		}
		Swap(array, begin, end);
	}
	Swap(array, begin, right);
	
	return begin;
}

int Partition_2(int array[], int left, int right){
	int begin = left;
	int end = right;
	int pivot = array[right];
	
	while(begin < end){
		while(begin < end && array[begin] <= pivot){
			begin++;
		} 
		
		array[end] = array[begin];
		
		while(begin < end && array[end] >= pivot){
			end--;
		}
		array[begin] = array[end];
	}
	array[begin] = pivot;
	
	return begin;
}

int Partition_3(int array[], left, right){
	int d = left;
	for(int i = left; i<=right; ++i){
		if(array[i] < array[right]){
			Swap(array, i, d);
			d++;
		}
	}
	Swap(array, d, right);
	
	return d;
	
}


/*
归并排序
	1.平均切割区间
	2.分治处理左右两个区间
		直到 size == 1 || size == 0
	3.合并两个有序数组
*/

/*
时间复杂度	O(n * log(n))
空间复杂度 O(n)
稳定性:稳定
*/

void Merge(int array[], int low, int mid, int high, int extra[]){
	
	int i = low;
	int j = mid;
	int k = low;
	
	while(i < mid && j < high){
		if(array[i] <= array[j]){
			extra[k++] = array[i++];
		}else{
			extra[k++] = array[j++];
		}
	}
	while(i < mid){
		extra[k++] = array[i++];
	}
	while(i < high){
		extra[k++] = array[j++];
	}
	for(int x = low; x < high; x++){
		array[x] = extra[x];
	}
	
}

void MergeSortInner(int array[],int low, int high, int extra[]){
	if(low >= high){
		return;
	}
	
	if(low + 1 == high){
		return;
	}
	
	int mid = low + (high - low) / 2;
	MergeSortInner(array, low, mid, extra);
	MergeSortInner(array, mid, high, extra);
	
	Merge(array, low, mid, high, extra);
	
}

void MergeSort(int array[], int size){
	int* extra = (int*)malloc(sizeof(int)*size);
	MergeSortInner(array, 0, size);
	free(extra);
}
















































