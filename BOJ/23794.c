# include <stdio.h>

int main(void) {
	int N, i, j;
	scanf("%d", &N);
	for(i=0 ; i<N+2 ; i++) {
		if(!i||i==N+1)
			for(j=0 ; j<N+2 ; j++)
				printf("@");
		else {
			printf("@");
			for(j=0 ; j<N ; j++)
				printf(" ");
			printf("@");
		}
		puts("");
	}
	return 0;
}
