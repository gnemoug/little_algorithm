/*
** strstr by hand.
*/
#include <stdio.h>
#include <string.h>

char *m_strstr(char *str,char *sub){
	int str_len = strlen(str);
	int sub_len = strlen(sub);
	int i,j;
	for(i=0;i<str_len-sub_len;i++){
		j = 0;
		while('\0' != *sub){
			if(str[i+j] != sub[j])
				break;
			j++;
		}
		if(j == sub_len)
			return str+i;
	}
	return NULL;
}

int main(void){
	char str[] = "sdhfkjsdghshellowdsgfds";
	char sub[] = "hello";
	char *p = m_strstr(str,sub);
	if(NULL == p)
		printf("sub is not in str.\n");
	else
		printf("bingo, sub is in str.\nsub string is :\n%s\n",p);
	return 0;
}
