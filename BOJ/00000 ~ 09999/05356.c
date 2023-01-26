# include <stdio.h>

int main(void) {
	int T, num, i, j;
	char c;
	scanf("%d", &T);
	while(T--) {
		scanf("%d %c", &num, &c);
		getchar();
		for(i=0 ; i<num ; i++) {
			for(j=0 ; j<=i ; j++)
				printf("%c", c+i>'Z'?c+i-26:c+i);
			puts("");
		}
		puts("");
	}
	return 0;
}