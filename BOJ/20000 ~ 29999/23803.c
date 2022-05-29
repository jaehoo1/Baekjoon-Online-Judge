# include <stdio.h>

int main(void) {
	int N, i, j, k;
	scanf("%d", &N);
	for(i=0 ; i<4 ; i++)
		for(j=0 ; j<N ; j++) {
			for(k=0 ; k<N ; k++)
				printf("@");
			puts("");
		}
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<5 ; j++)
			for(k=0 ; k<N ; k++)
				printf("@");
		puts("");
	}
	return 0;
}
