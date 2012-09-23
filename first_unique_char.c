/*
** Find first unique char in a string.
*/
#include <stdio.h>
#define TABLE_SIZE 256

char find_first_unique_char(char *str){
	if('\0' == *str)
		return '\0';
	int hash_table[TABLE_SIZE] = {0};
	char *p = str;
	while('\0' != *p){
		hash_table[*(p++)]++;
	}
	p = str;
	while('\0' != *p){
		if(1 == hash_table[*p])
			return *p;
		p++;
	}
}

int main(){
	char str[] = "this is a unique string.";
	char c = find_first_unique_char(str);
	if(c != '\0')
		printf("The first unique char in string %s is : %c\n",str,c);
	else
		printf("Not found.\n");
	return 0;
}
