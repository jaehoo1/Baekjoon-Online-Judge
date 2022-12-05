# include <stdio.h>

int main(void) {
	int N, M, T, i, j;
	long long S[1000], A[1000]={0, };
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++)
		scanf("%lld", &S[i]);
	for(i=0 ; i<N ; i++) {
		for(j=0 ; j<N ; j++) {
			scanf("%d", &T);
			S[i]-=T;
			S[j]+=T;
		}
		for(j=0 ; j<M ; j++) {
			scanf("%d", &T);
			S[i]-=T;
			A[j]+=T;
		}
	}
	for(i=0 ; i<N ; i++)
		printf("%lld ", S[i]);
	for(i=0 ; i<M ; i++)
		printf("%lld ", A[i]);
	return 0;
}