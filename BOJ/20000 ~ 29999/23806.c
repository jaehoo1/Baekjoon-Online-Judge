# include <stdio.h>

int main(void) {
	int N, a, b, c;
	scanf("%d", &N);
	for(a=0 ; a<N ; a++) {
		for(b=0 ; b<N ; b++)
			printf("@");
		for(b=0 ; b<3*N ; b++)
			printf("@");
		for(b=0 ; b<N ; b++)
			printf("@");
		puts("");
	}
	for(a=0 ; a<3 ; a++)
		for(b=0 ; b<N ; b++) {
			for(c=0 ; c<N ; c++)
				printf("@");
			for(c=0 ; c<3*N ; c++)
				printf(" ");
			for(c=0 ; c<N ; c++)
				printf("@");
			puts("");
		}
	for(a=0 ; a<N ; a++) {
		for(b=0 ; b<N ; b++)
			printf("@");
		for(b=0 ; b<3*N ; b++)
			printf("@");
		for(b=0 ; b<N ; b++)
			printf("@");
		puts("");
	}
	return 0;
}