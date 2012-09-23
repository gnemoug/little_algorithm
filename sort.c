/*
** 常见的排序。
*/
#include <stdio.h>
#include <stdlib.h>

/*
** @params : arr -- 待排序序列
** @params : count -- 序列中元素个数
** @describe :
**   1.比较相邻的元素，如果第一个比第二个大，就交换他们两个。
**   2.对每一对相邻元素做同样的工作，从开始第一对到结尾的最后一对。
**	   每一次bubble出一个最大的元素。
**   3.针对所有元素重复上述步骤，直到最后一个。
**   4.持续每次对越来越少的元素重复上面的步骤，知道没有任何一对数字要比较。
*/
void bubble_sort(int arr[],const int count){
	int i,j,tmp;
	for(i=count;i>0;i--){
		for(j=0;j<i-1;j++){
			/*If arr[j] > arr[j+1] ,bubble a elem.*/
			if(arr[j] > arr[j+1]){
				tmp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = tmp;
			}
		}
	}
}
/*
** @params : arr -- 待排序序列
** @params : count -- 序列中元素个数
** @describe :
**   1.从第一个元素开始，该元素可以认为已经排好序。
**   2.取出下一个元素，在已经排序的元素序列中从后向前扫描
**   3.如果该元素(已排序部分)大于新元素，将该元素移到下一位置
**   4.重复步骤3，知道找到已排序部分的某元素小于或者等于新元素的位置。
**   5.将新元素插入到该位置后
**   6.重复步骤2～5
*/
void insertion_sort(int arr[],const int count){
	int index,j;
	int tmp;
	for(index=1;index<count;index++){
		tmp = arr[index];
		for(j=index;j>0 && arr[j-1]>tmp;j--)
			arr[j] = arr[j-1];
		arr[j] = tmp;
	}
}
/*
** @params : arr -- 待排序序列
** @params : n -- 序列中元素的个数
** @describe :
**   希尔排序将一个序列分割为若干个子序列，然后对每个序列排序。
**   然后逐步缩小步长,当步长为1时，序列基本就排好序来，然后就
**   是简单的插入排序了。
*/
void shell_sort(int arr[],int n){
	int i,j,increament;
	int tmp;
	for(increament=n/2;increament>0;increament/=2){
		for(i=increament;i<n;i++){
			tmp = arr[i];
			for(j=i;j>=increament;j-=increament){
				if(tmp<arr[j-increament])
					arr[j] = arr[j-increament];
				else
					break;
			}
			arr[j] = tmp;
		}
	}
}
/*
** @params ： arr -- 待排序数组
** @params ： count -- 数组的长度
** @params ： index -- 要调整的子树的根
** @describe ：
** 		1.寻找孩子节点中较大的一个
** 		2.如果根节点比较大的孩子大，结束循环
** 		3.如果根节点比较大的孩子小，那么交换根节点和较大孩子节点的值
** 		4.重复以上步骤，知道遇到叶子节点
*/
static void heap_adjust(int arr[],int index,const int count){
	int tmp,child_index;
	for(tmp = arr[index];2*index+1<count;index=child_index){
		child_index = 2*index + 1;
		/*选择孩子节点中较大的一个*/
		if(child_index + 1 < count && arr[child_index + 1] > arr[child_index])
			++child_index;
		/*如果根节点比孩子节点大，直接跳出循环*/
		if(tmp > arr[child_index])
			break;
		else /*如果根节点比孩子节点小，则交换他们的值，是根节点保持最大*/
			arr[index] = arr[child_index];
		//将原来的根节点插入到相应的位置中
		arr[child_index] = tmp;
	}
}
void print_arr(int arr[],const int count);
/*
** @params : arr -- 待排序序列
** @params : count -- 序列中元素个数
** @describe :
**		1.建立堆
**		2.从堆中依次筛选出元素
*/
void heap_sort(int arr[],const int count){
	int i,tmp;
	/*建立大顶堆*/
	for(i=count/2-1;i>=0;i--)
		heap_adjust(arr,i,count);
	/*依次筛选出最大的元素*/
	for(i=count-1;i>0;i--){
		tmp = arr[0];
		arr[0] = arr[i];
		arr[i] = tmp;
		heap_adjust(arr,0,i);
	}
}
/*
** @params : arr -- 待排序序列
** @params : tmp_arr -- 临时存储序列
** @params : left -- 左半部分的开始下标
** @params : center -- 右半部分的开始下标
** @params : right -- 右半部分的结束下标
** @describe ： 
** 	对并排序的最核心操作，将两个子序列归并。
*/
void merge(int arr[],int tmp_arr[],int left,int center,int right){
	int i,elem_count,tmp_index;
	int left_end = center - 1;
	tmp_index = left;
	elem_count = right - left + 1;
	/*main loop*/
	while(left <= left_end && center <= right){
		if(arr[left] <= arr[center])
			tmp_arr[tmp_index++] = arr[left++];
		else
			tmp_arr[tmp_index++] = arr[center++];
	}
	/*Copy the left rest*/
	while(left <= left_end)
		tmp_arr[tmp_index++] = arr[left++];
	/*Copy the right rest*/
	while(center <= right)
		tmp_arr[tmp_index++] = arr[center++];
	/*将临时数组复制到原来的序列中*/
	for(i=0;i<elem_count;i++,right--)
		arr[right] = tmp_arr[right];
}
/*
** @params : arr -- 待排序序列
** @params : tmp_arr -- 临时存储序列
** @params : left -- 子序列的最左下标
** @params : right -- 子序列的最右下标
** @describe :
** 	归并排序的递归操作。
*/
void m_sort(int arr[],int tmp_arr[],const int left,const int right){
	int center;
	if(left < right){
		center = (left + right) / 2;
		/*先归并左边一半序列*/
		m_sort(arr,tmp_arr,left,center);
		/*再归并右边一半序列*/
		m_sort(arr,tmp_arr,center+1,right);
		/*然后执行归并操作*/
		merge(arr,tmp_arr,left,center+1,right);
	}
}
/*
** @params : arr -- 待排序序列
** @params : count -- 序列中元素个数
** @describe : 
** 	归并排序的具体工作原理如下(假定序列有count个元素)：
**		1.将序列每相邻的两个元素进行归并操作，形成count/2个序列，
**		排序后每个序列包含两个元素。
**		2.将上述序列再次归并，形成count/2个序列，每个序列包含四个元素。
**		3.重复步骤2，直到所有元素排序完毕。
*/
void merge_sort(int arr[],const int count){
	int *tmp_arr;
	tmp_arr = (int *)malloc(count * sizeof(arr));
	if(tmp_arr == NULL){
		printf("ERROR! Out of memory.");
		return;
	}
	else{
		/*进入递归子程序*/
		m_sort(arr,tmp_arr,0,count - 1);
		free(tmp_arr);
	}
}
/*交换a和b的值*/
void swap(int *a,int *b){
	if(*a == *b)
		return ;
	*a = *a ^ *b;
	*b = *a ^ *b;
	*a = *a ^ *b;
}
/*
** @params : arr -- 待排序序列
** @params : left -- 子序列的最左下标
** @params : right -- 子序列的最右下标
** @describe : 
** 	原地对序列进行分区。将left到right之间的元素重新排列
**  所有大于枢纽单元的元素放在后面，小于枢纽单元的元素
**	放在左面。然后返回中间枢纽元素的下标
*/
int partition(int arr[],int left ,int right){
	int index = left;
	/*选取首元素作为枢纽元素*/
	int pivot = arr[index];
	swap(&arr[index],&arr[right]);
	int i;
	for(i=left;i<right;i++){
		if(arr[i] < pivot)
			swap(&arr[index++],&arr[i]);
	}
	swap(&arr[right],&arr[index]);
	return index;
}
/*
** @params : arr -- 待排序序列
** @params : left -- 分区的最左下标
** @params : rifht -- 分区的最右下标
** @describe ：
** 	快速排序使用分治法策略把一个序列分为两个子序列。
**		1.从序列中挑出一个元素作为枢纽单元(pivot)
**		2.重新排列序列，将所有比枢纽单元小的元素放在基准
**		元素的前面，比枢纽单元大的元素放在基准元素的后面
**		排列结束之后，该枢纽单元处于序列的中间位置。这个
**		操作成为分区操作(partition()).
**		3.递归地，划分子序列，然后重复上述步骤。
*/
void Q_sort(int arr[],int left,int right){
	if(left >= right)
		return;
	int index = partition(arr,left,right);
	Q_sort(arr,left,index-1);
	Q_sort(arr,index+1,right);
}
/*
** @params : arr -- 待排序序列
** @params : count -- 序列中元素的个数
** @describe : 
**	快速排序的驱动，调用Q_sort()函数，开始排序。
*/
void quick_sort(int arr[],const int count){
	Q_sort(arr,0,count-1);
}
void print_arr(int arr[],const int count){
	int i;
	for(i=0;i<count;i++)
		printf("%4d",arr[i]);
	printf("\n");
}

int main(){
	//int arr[] = {2,7,4,9,1,3,18,24,23};
	int arrs[] = {13,14,94,33,82,25,59,94,65,23,45,27,73,25,39,10};
	//print_arr(arr,sizeof(arr)/sizeof(int));
	//bubble_sort(arr,sizeof(arr)/sizeof(int));
	//insertion_sort(arr,sizeof(arr)/sizeof(int));
	printf("Before quick-sort:\n");
	print_arr(arrs,sizeof(arrs)/sizeof(int));
	//shell_sort(arrs,sizeof(arrs)/sizeof(int));
	//heap_sort(arrs,sizeof(arrs)/sizeof(int));
	//merge_sort(arrs,sizeof(arrs)/sizeof(int));
	quick_sort(arrs,sizeof(arrs)/sizeof(int));
	printf("After quick-sort:\n");
	print_arr(arrs,sizeof(arrs)/sizeof(int));
	//print_arr(arr,sizeof(arr)/sizeof(int));
	return 0;
}
