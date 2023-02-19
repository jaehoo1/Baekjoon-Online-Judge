# include <stdio.h>

int main(void) {
	int N, M, num, min=100, minidx, i;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &num);
		if(num<min) {
			min=num;
			minidx=i;
		}
	}
	printf("%d ", minidx+1);
	min=num;
	minidx=0;
	for(i=1 ; i<M ; i++) {
		scanf("%d", &num);
		if(num<min) {
			min=num;
			minidx=i;
		}
	}
	printf("%d", minidx+1);
	return 0;
}