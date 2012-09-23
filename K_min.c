/*
** 获取一个序列中最小的K个数。
** 对K个数建立一个小顶堆，然后逐渐的从堆中取出K个数。
*/
#include <stdio.h>

/*
** @params : arr -- 原始序列
** @params : index -- 要挑证的序列的根节点下标
** @params : count -- 序列中元素的个数
** @describ :
** 维护序列arr为一个小顶堆：
**	1.寻找孩子节点中较小的一个
**	2.如果根节点比较小的孩子小，结束循环
**	3.如果根节点比较小的孩子大，那么交换根节点和较大孩子节点的值
**  4.重复以上步骤
*/
static void heap_adjust(int arr[],int index,const int count){
	int tmp,child_index;
	for(tmp = arr[index];2*index+1 < count;index = child_index){
		child_index = 2*index + 1;
		/*选择孩子节点中较小的一个*/
		if(child_index + 1 < count && arr[child_index + 1] < arr[child_index])
			++child_index;
		/*如果根节点比较小孩子节点小，则结束循环*/
		if(tmp < arr[child_index])
			break;
		else /*如果根节点比孩子节点大，那么交换他们的值，保证根节点最小*/
			arr[index] = arr[child_index];
		//将原来的根节点插入到相应的位置中
		arr[child_index] = tmp;
	}
}
void K_min(int arr[],const int count,const int K){
	int i,min;
	/*建立小顶堆*/
	for(i = count/2 - 1;i>=0;i--)
		heap_adjust(arr,i,count);
	/*一次筛选出最小的元素*/
	for(i=0;i<K;i++){
		min = arr[0];
		printf("%4d",min);
		arr[0] = arr[count - i -1];
		heap_adjust(arr,0,count -i -1);
	}
	printf("\n");
}

int main(){
	int arr[] = {13,14,94,33,82,25,59,94,65,23,45,27,73,25,39,10};
	K_min(arr,sizeof(arr)/sizeof(int),7);
	return 0;
}


















