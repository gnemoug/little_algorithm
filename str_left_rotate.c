/*
** 左旋字符串：把字符串前面的若干个字符移动到字符串的尾部。
** 如 ：abcdef 左旋 3 位 --> defabc
*/
#include <stdio.h>
#include <string.h>

/*
** 将字符串的start到end之间的字符逆置。
** 如： str = "hello world" *start = 'w' *end='d'.
** 则执行完之后：
** 		str = "hello dlrow".
*/
char *reverse(char *start,char *end){
	char tmp;
	char *p = start;
	while(p != NULL && end != NULL && p < end){
		tmp = *end;
		*end = *p;
		*p = tmp;
		p++;
		end--;
	}
	return start;
}

/*
** 左旋字符串，str为要旋转的字符串，nCount为要旋转的字符的个数。
*/
char *str_left_rotate(char *str,int nCount){
	int nlength = strlen(str);
	reverse(str,str + (nCount - 1)); //先旋转前一部分
	reverse(str + nCount,str + (nlength -1));//再旋转后一部分
	reverse(str,str + (nlength -1));//最后全部旋转
	return str;
}

int main(){
	char str[] = "abcdefghijk";
	puts(str_left_rotate(str,3));
	return 0;
}
