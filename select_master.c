#include <stdio.h>
/*
** 问题描述：选首领.有n个人围成一圈，并从0到n-1标好标签，
** 从第0个人开始(从1～3)报数，每次报数为3的人退出圈子，
** 求最后剩下那个人。
*/

int hash[100];
static int cursor_count;
/*
** 用hash数组座位标志位来做。
** 缺点：复杂度高.
** 发散：用循环链表实现会好一点
*/
void select_master(int count){
	int index = 1;
	long number = 1;
	while(1){
		if(cursor_count == 1)
			break;
		if(0 == hash[index]){
			index = (index + 1) % (count + 1);
			if(index == 0)
				index++;
			continue;
		}
		if(0 == number % 3){
			hash[index] = 0;
			cursor_count--;
		}
		index = (index + 1) % (count + 1);
		if(index == 0)
			index++;
		number = (number + 1) % 4;
		if(number == 0)
			number++;
	}
	//print it.
	for(index = 1;index <= count;index++)
		if(hash[index] == 1)
			printf("%4d last finnaly.\n",index);
}
int main(void){
	int count = 100;
	cursor_count = 100;
	int i;
	for(i = 1;i <= count;i++)
		hash[i] = 1;
	select_master(count);
	return 0;
}

