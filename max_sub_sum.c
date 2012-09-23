/*
** 求数组连续子序列的最大的和。
*/

#include <stdio.h>

int max_sub_sum(int arr[],const int count){
	int this_sum,max_sum,i;
	this_sum = max_sum = 0;
	for(i = 0;i < count;i++){
		this_sum += arr[i];
		if(this_sum > max_sum)
			max_sum = this_sum;
		else if(this_sum < 0)
			this_sum = 0;
	}
	return max_sum;
}
int main(void){
	int arr[] = {1,-2,5,4,9,10,-2,-7};
	int ret = max_sub_sum(arr,sizeof(arr)/sizeof(int));
	printf("%d\n",ret);
	return 0;
}
