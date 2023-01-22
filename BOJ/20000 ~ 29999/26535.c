# include <stdio.h>
# include <math.h>

int main(void) {
	int N, i, j, len;
	scanf("%d", &N);
	for(i=1 ; (int)pow(i, 2)<N ; i++);
	len=i;
	for(i=0 ; i<len+2 ; i++)
		printf("x");
	puts("");
	for(i=0 ; i<len ; i++) {
		printf("x");
		for(j=0 ; j<len ; j++)
			printf(".");
		printf("x\n");
	}
	for(i=0 ; i<len+2 ; i++)
		printf("x");
	return 0;
}