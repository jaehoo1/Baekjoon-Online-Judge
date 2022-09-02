# include <stdio.h>

int main(void) {
	int A[46]={1}, B[46]={0}, K, i;
	scanf("%d", &K);
	for(i=1 ; i<=K ; i++) {
		B[i]=B[i-1]+A[i-1];
		A[i]=B[i-1];
	}
	printf("%d %d", A[K], B[K]);
	return 0;
}