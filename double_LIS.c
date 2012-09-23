/*
** 问题描述：
** 从一列数中筛除尽可能少的数，使得从左往右看，这些数是从小到大再从大到小的
** 抽象：
** 双端LIS问题，用动态规划的思想解决。
*/

#include <stdio.h>

#define MAX_NUM  (1U<<31)

int main(void){
	int i,n,low,high,mid,max;

	printf("Input how many numbers there are: ");
	scanf("%d",&n);
	double a[n],b[n],c[n],inc[n];
	printf("Please input the numbers:\n");
	for(i = 0;i < n;i++)
		scanf("%lf",&a[i]);
	for(i = 0;i < n;i++)
		inc[i] = (unsigned)MAX_NUM;
	for(i = 0;i < n;i++){
		low = 0;
		high = i;
		while(low < high){
			mid = low + (high - low) / 2;
			if(inc[mid] < a[i])
				low = mid + 1;
			else
				high = mid;
		}
		b[i] = low + 1;
		inc[low] = a[i];
	}
	for(i = 0;i < n;i++)
		inc[i] = (unsigned)MAX_NUM;
	for(i = n-1;i >= 0;i--){
		low = 0;
		high = i;
		while(low < high){
			mid = low + (high - low) / 2;
			if(inc[mid] < a[i])
				low = mid + 1;
			else
				high = mid;
		}
		c[i] = low + 1;
		inc[low] = a[i];
	}
	max = 0;
	for(i = 0;i < n;i++)
		if(b[i] + c[i] > max)
			max = b[i] + c[i];
	printf("%d numbers should be erased at least.\n",n+1-max);

	return 0;
}
















