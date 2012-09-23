/*
** 快速选择算法。
** copyright@ mark allen weiss 
** origin from 《数据结构与算法分析：C语言实现》
** 将一个序列中的第K小的元素放在K位置，由于数组是从下标0开始，
** 所以本例中是将其放在K-1位置上。
*/
#include <stdio.h>

void swap(int *a,int *b){
	int tmp = *a;
	*a = *b;
	*b = tmp;
}
/*
** @params : arr -- 待选择序列
** @params : left -- 子序列的最左下标
** @params : right -- 子序列的最右下标
** @describe :
** 	原地对序列进行分区。将left到right之间的元素重新排列
**  所有大于枢纽单元的元素放在后面，小于枢纽单元的元素
**	放在左面。然后返回中间枢纽元素的下标
*/
static int partition(int arr[],int left,int right){
	int index = left;
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
** @params : arr -- 待选择序列
** @params : k -- 要选择的第k个最小的元素
** @params : left -- 子序列的最左下标
** @params : right -- 子序列的最右下标
** @describe :
** 	选择序列arr中第k个元素。
** 		1.首先，子序列arr中的某一个元素作为pivot(枢纽元素).
** 		2.将子序列重新排序，排序完成后，pivot元素处在序列的中间位置。
** 		3.如果此时 k = index + 1 (index为此时pivot元素在序列中的下标)，
** 			那么arr[index]即是要寻找的元素。因为所有下标小于index的
** 			元素的值都小于arr[index]
** 		4.如果此时 k > index + 1,那么要找的元素在右侧的子序列中，递归地
** 			寻找即可。
** 		5.对称地，如果此时 k < index + 1,那么要找的元素在左侧的子序列中，
** 			然后递归地在左侧的子序列中寻找即可。
*/
int Q_select(int arr[],int k,int left,int right){
	if(left >= right)
		return arr[k-1];
	/*重新对arr分区，寻找枢纽元素的下标index*/
	int index = partition(arr,left,right);
	/*在左侧的子序列中递归地寻找*/
	if(k < index + 1)
		return Q_select(arr,k,left,index - 1);
	else if(k > index + 1)//在右侧的子序列中递归的寻找
		return Q_select(arr,k,1 + index,right);
	else //arr[index]即是要寻找的元素
		return arr[index];
}

int main(){
	int arr[] = {13,14,94,33,82,25,59,94,65,23,45,27,73,25,39,10};
	int e = Q_select(arr,3,0,sizeof(arr)/sizeof(int) - 1);
	printf("The %dth smallest emelemt is %5d\n",3,e);
	return 0;
}

