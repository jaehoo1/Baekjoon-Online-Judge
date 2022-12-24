# include <stdio.h>

int main(void) {
	char str[1000001];
	int i;
	scanf("%s", str);
	for(i=1 ; str[i]==str[0] ; i++);
	printf("%d", i);
	return 0;
}