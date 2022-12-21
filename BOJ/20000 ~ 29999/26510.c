# include <stdio.h>

int main(void) {
	int N, i, j;
	while(~scanf("%d", &N)) {
		for(i=0 ; i<N-1 ; i++) {
			for(j=0 ; j<i ; j++)
				printf(" ");
			printf("*");
			for(j=0 ; j<N-i-2 ; j++)
				printf(" ");
			printf(" ");
			for(j=0 ; j<N-i-2 ; j++)
				printf(" ");
			puts("*");
		}
		for(i=0 ; i<N-1 ; i++)
			printf(" ");
		puts("*");
	}
	return 0;
}