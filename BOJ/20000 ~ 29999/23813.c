# include <stdio.h>
# include <string.h>

void rotate(char *str) {
	int i, len=strlen(str);
	char tmp=str[len-1];
	for(i=len-1 ; i>0 ; i--)
		str[i]=str[i-1];
	str[0]=tmp;
	str[len]=0;
}

int main(void) {
	long long sum=0;
	int i, len;
	char str[11];
	scanf("%s", str);
	len=strlen(str);
	for(i=0 ; i<len ; i++) {
		sum+=atoi(str);
		rotate(str);
	}
	printf("%lld", sum);
	return 0;
}