# include <stdio.h>

int main(void) {
	int N, i, dp[1000]={1}, temp=2;
	for(i=1 ; i<1000 ; i++) {
		dp[i]=dp[i-1]+temp;
		temp+=2;
	}
	while(scanf("%d", &N)) {
		if(!N)break;
		printf("%d => %d\n", N, dp[N-1]);
	}
	return 0;
}
