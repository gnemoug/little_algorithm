#include <stdio.h>
/*
** 求1到n的所有素数。
*/

int hash[999] = {0};

void get_primes(int max_value){
	int i = 3,j = 2;
	while(i <= max_value){
		//if hash == 0,not filtered out
		if(0 == hash[i]){
			j = 2;
			while(j < i){
				if(0 == i % j)
					break;
				j++;
			}
			if(j < i)
				hash[i] = 0;
			else
				hash[i] = 1;
		}
		else{ //i is a prime number,filter m if m = j*i.
			j = 2;
			while(j * i <= max_value){
				hash[j * i] = 0;
				j++;
			}
		}
		i++;
	}
}

void print_primes(int count){
	int i = 1;
	for(;i <= count;i++){
		if(1 == hash[i])
			printf("%5d\n",i);
	}
}
int main(void){
	int max = 100;
	hash[1] = 0;
	hash[2] = 1;
	hash[3] = 1;
	get_primes(max);
	print_primes(max);
	return 0;
}
