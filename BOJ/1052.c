# include <stdio.h>

int main(void) {
	int bin[25]={1, }, i, N, K, orgN, bottle;
	for(i=1 ; i<=24 ; i++)
		bin[i]=bin[i-1]*2;
	scanf("%d%d", &N, &K);
	orgN=N;
	while(1) {
		bottle=0;
		for(i=0 ; i<=24 ; i++)
			if(N&bin[i])
				bottle++;
		if(bottle<=K)
			break;
		N+=N&-N;
	}
	printf("%d", N-orgN);
	return 0;
}
