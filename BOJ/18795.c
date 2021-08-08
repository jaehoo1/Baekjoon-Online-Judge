# include <stdio.h>

int main(void) {
	int N, M, num;
	long long sum=0;
	scanf("%d%d", &N, &M);
	while(N--) {
		scanf("%d", &num);
		sum+=num;
	}
	while(M--) {
		scanf("%d", &num);
		sum+=num;
	}
	printf("%lld", sum);
	return 0;
}
