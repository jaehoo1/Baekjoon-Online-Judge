# include <stdio.h>

int main(void) {
	int N, i;
	scanf("%d", &N);
	N/=4;
	for(i=0 ; i<N ; i++)
		printf("long ");
	puts("int");
	return 0;
}