# include <stdio.h>

int N;

void area1(void) {
	int i, j;
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++)
			printf("@");
		for(j=0 ; j<3*N ; j++)
			printf(" ");
		for(j=0 ; j<N ; j++)
			printf("@");
		puts("");
	}
}
void area2(void) {
	int i, j;
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<5*N ; j++)
			printf("@");
		puts("");
	}
}

int main(void) {
	scanf("%d", &N);
	area1();
	area2();
	area1();
	area2();
	area1();
	return 0;
}
