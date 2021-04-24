# include <stdio.h>
# include <string.h>

void swap(char *a, char *b) {
	char temp=*a;
	*a=*b;
	*b=temp;
}
void reverse(char *str) {
	int i, len=strlen(str);
	for(i=0 ; i<len/2 ; i++)
		swap(&str[i], &str[len-1-i]);
}

int main(void) {
	int T;
	char str[71];
	scanf("%d", &T);
	getchar();
	while(T--) {
		gets(str);
		reverse(str);
		puts(str);
	}
	return 0;
}
