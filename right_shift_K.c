/*
** 将一个含有N个元素的数组循环右移K位。
** 要求： 时间复杂度为O(N),且之允许使用两个附加变量
*/
#include <stdio.h>

/*
** 时间复杂度为O(N*K).
*/
void right_shift_k(int arr[],int N,int K){
	int rear;
	int i;
	while(K--){
		rear = arr[N-1];
		for(i=N-1;i>0;i--)
			arr[i] = arr[i-1];
		arr[0] = rear;
	}
}
/*
** 将数组arr的元素，从start到end逆置。
** 如： arr = {1,2,3,4,5,6}; start = 2, end = 5.
** 则执行完本程序后arr为：
** 	    arr = {1,2,6,5,4,3};
*/
void reverse(int arr[],int start,int end){
	int tmp;
	while(start < end){
		tmp = arr[end];
		arr[end] = arr[start];
		arr[start] = tmp;
		start++;
		end--;
	}
}
/*
** 时间复杂度为O(N).
** 变换过程如下：
** arr = {1,3,5,7,9,11,13,17,19,2,5,8}; N = 12 ,K = 3.
** 先逆置1，3，5，7，9，11，13，17，19：
** 		arr = {19,17,13,11,9,7,5,3,1,2,5,8}
** 再逆置2，5，8：
**		arr = {19,17,13,11,9,7,5,3,1,8,5,2}
** 最后全部逆置:
**		arr = {2,5,8,1,3,5,7,9,11,13,17,19}
** 完成右移操作。
*/
void super_right_shift_k(int arr[],int N,int K){
	K %= N;
	reverse(arr,0,N-K-1);
	reverse(arr,N-K,N-1);
	reverse(arr,0,N-1);
}
void print_arr(int arr[],int N){
	int i;
	for(i=0;i<N;i++)
		printf("%5d",arr[i]);
	printf("\n");
}

int main(){
	int arr[] = {1,3,5,7,9,11,13,17,19,2,5,8};
	print_arr(arr,sizeof(arr)/sizeof(int));
	//right_shift_k(arr,sizeof(arr)/sizeof(int),2);
	super_right_shift_k(arr,sizeof(arr)/sizeof(int),3);
	printf("Right shift 3 blocks.\n");
	print_arr(arr,sizeof(arr)/sizeof(int));
	return 0;
}
