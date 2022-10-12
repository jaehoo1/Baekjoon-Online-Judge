# include <stdio.h>
# include <string.h>

int main(void) {
	char str[51];
	int len, i, left, right;
	scanf("%s", str);
	len=strlen(str);
	for(i=0 ; str[i]!='U' ; i++);
	left=i;
	for(i=len-1 ; str[i]!='F' ; i--);
	right=i;
	for(i=0 ; i<left ; i++)
		printf("-");
	printf("U");
	for(i=left+1 ; i<right ; i++)
		printf("C");
	printf("F");
	for(i=right+1 ; i<len ; i++)
		printf("-");
	return 0;
}