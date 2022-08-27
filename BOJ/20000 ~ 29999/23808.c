# include <stdio.h>

int main(void) {
	int N, i, j, k;
	scanf("%d", &N);
	for(i=0 ; i<2 ; i++) {
		for(j=0 ; j<N ; j++) {
			for(k=0 ; k<N ; k++)
				printf("@");
			for(k=0 ; k<N*3 ; k++)
				printf(" ");
			for(k=0 ; k<N ; k++)
				printf("@");
			puts("");
		}
	}
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<N*5 ; j++)
			printf("@");
		puts("");
	}
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++)
			printf("@");
		for(j=0 ; j<N*3 ; j++)
			printf(" ");
		for(j=0 ; j<N ; j++)
			printf("@");
		puts("");
	}
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<N*5 ; j++)
			printf("@");
		puts("");
	}
	return 0;
}