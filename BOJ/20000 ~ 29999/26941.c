# include <stdio.h>

int main(void) {
	int	N, i, block, stair;
	scanf("%d", &N);
	for(i=1, stair=0, block=0 ; block<=N ; i+=2, stair++)
		block+=i*i;
	printf("%d", stair-1);
	return 0;
}