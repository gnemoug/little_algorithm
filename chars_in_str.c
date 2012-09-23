/*
** 现有两个字符串，一个比较长，一个比较短。
** 编写算法，判断短字符串中的所有字符是不是在长字符串中找到。
*/
#include <stdio.h>
/*
** 先设置一个hash表，存储在short-str中的字符，然后遍历
** long-str，如果long-str中的字符能在hash表中找到，则将hash
** 表的相应为置0，直到long-str的所有字符都遍历完。最后判断
** hash表中的元素的个数是否为0即可。
** 时间复杂度为 O(n+m).
*/
int chars_in_str(char *long_str,char *short_str){
	int hash[26] = {0};
	int char_count = 0;
	int i = 0;
	int index;
	while( *(short_str + i) != '\0'){
		index = *(short_str + i) - 'A';
		if(0 == hash[index]){
			hash[index] = 1;
			char_count++;
		}
		i++;
	}
	i = 0;
	while( *(long_str + i) != '\0'){
		index = *(long_str + i) - 'A';
		if(1 == hash[index]){
			hash[index] = 0;
			char_count--;
			if(0 == char_count)
				break;
		}
		i++;
	}
	if(0 == char_count)
		return 1;
	else
		return 0;
}

int main(){
	char long_str[] = "ABCDEFGHIJKLMN";
	char short_str[] = "BDJAFCZ";
	if(chars_in_str(long_str,short_str))
		printf("YES\n");
	else
		printf("NO\n");
	return 0;
}


