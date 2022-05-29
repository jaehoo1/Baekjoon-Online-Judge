# include <stdio.h>

int main(void) {
	int N, M, i, sum, num;
	while(scanf("%d%d", &N, &M)) {
		if(!N&&!M)break;
		M/=N;
		sum=0;
		for(i=0 ; i<N ; i++) {
			scanf("%d", &num);
			sum+=num<M?num:M;
		}
		printf("%d\n", sum);
	}
	return 0;
}
