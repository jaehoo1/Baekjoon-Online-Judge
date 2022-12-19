# include <stdio.h>
# include <string.h>

int main(void) {
	int n, len;
	char str[102];
	scanf("%d", &n);
	getchar();
	while(n--) {
		gets(str);
		len=strlen(str);
		if(str[len-1]!='.') {
			str[len]='.';
			str[len+1]=0;
		}
		puts(str);
	}
	return 0;
}