/*
** 从一个数组挑选出若干个数，使得他们的和等于某个值
*/
#include <stdio.h>

void print_sub_seq(int arr[],int count,int K[]){
	int i = 0;
	while(i < count){
		if(K[i] == 1)
			printf("%4d",arr[i]);
		i++;
	}
	printf("\n");
}

void select(int arr[],int cursor_sum,int sum,int count,int cursor_index,int K[]){
	//recursive out
	if(cursor_index >= count || cursor_sum > sum){
		return;
	}
	//gotta
	if(arr[cursor_index] + cursor_sum == sum){
		K[cursor_index] = 1;
		//print the seq
		print_sub_seq(arr,count,K);
	}
	else{
		//01-bag,recursively.
		//select cursor_index
		K[cursor_index] = 1;
		select(arr,cursor_sum + arr[cursor_index],sum,count,cursor_index + 1,K);
		//do not select cursor_index
		K[cursor_index] = 0;
		select(arr,cursor_sum,sum,count,cursor_index + 1,K);
	}
}

int main(void){
	int arr[] = {12,24,22,58,47,11,19,28,33,67,81,34,27,41,50,36,88,51,21,14};
	int count = sizeof(arr)/sizeof(int);
	int K[20] = {0};
	select(arr,0,100,count,0,K);
	return 0;
}
