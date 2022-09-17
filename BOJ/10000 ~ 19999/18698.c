# include <stdio.h>

int main(void) {
	int T, i;
	char str[101];
	scanf("%d", &T);
	while(T--) {
		scanf("%s", str);
		for(i=0 ; str[i]&&str[i]!='D' ; i++);
		printf("%d\n", i);
	}
	return 0;
}