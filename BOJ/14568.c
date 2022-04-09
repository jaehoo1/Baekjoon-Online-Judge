# include <stdio.h>

int main(void) {
	int N, A, B, C, i, j, cou=0;
	scanf("%d", &N);
	for(i=1 ; i<=N ; i++) {
		A=i;
		if(A%2)
			continue;
		for(j=1 ; j<=N-A ; j++) {
			B=j;
			C=N-A-B;
			if(C<B+2||A<=0||B<=0||C<=0)
				continue;
			cou++;
		}
	}
	printf("%d", cou);
	return 0;
}
