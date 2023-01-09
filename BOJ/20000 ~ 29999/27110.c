# include <stdio.h>

int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int N, A, i, sum=0;
	scanf("%d", &N);
	for(i=0 ; i<3 ; i++) {
		scanf("%d", &A);
		sum+=min(N, A);
	}
	printf("%d", sum);
	return 0;
}