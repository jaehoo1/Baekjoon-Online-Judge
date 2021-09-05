# include <stdio.h>

char arr[]="QWERTYUIOPASDFGHJKLZXCVBNM";
char right(char c) {
	int i=0;
	while(arr[i]!=c)i++;
	return arr[i+1];
}

int main(void) {
	int i;
	char str[10001];
	gets(str);
	for(i=0 ; str[i] ; i++)
		printf("%c", str[i]>='A'&&str[i]<='Z'?right(str[i]):str[i]);
	return 0;
}
