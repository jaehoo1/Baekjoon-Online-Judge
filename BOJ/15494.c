# include <stdio.h>

int main(void) {
	int N, X=100, K;
	scanf("%d", &N);
	while(X) {
		K=(N-X*364)/1092;
		if((N-X*364)%1092==0&&K>0) {
			printf("%d\n%d\n", X, K);
			break;
		}
		X--;
	}
	return 0;
}
