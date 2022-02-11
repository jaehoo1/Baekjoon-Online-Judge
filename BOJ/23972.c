# include <stdio.h>

int main(void) {
	long long K, N, X;
	scanf("%lld%lld", &K, &N);
	if(N==1)
		puts("-1");
	else {
		X=K*N/(N-1);
		if(K%(N-1)&&N%(N-1))
			X++;
		printf("%lld", X);
	}
	return 0;
}
