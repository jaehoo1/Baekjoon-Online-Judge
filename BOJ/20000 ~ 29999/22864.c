# include <stdio.h>

int main(void) {
	int A, B, C, M, T=24, work=0, tired=0;
	scanf("%d%d%d%d", &A, &B, &C, &M);
	while(T--) {
		if(tired+A<=M) {
			tired+=A;
			work+=B;
		} else {
			tired-=C;
			if(tired<0)
				tired=0;
		}
	}
	printf("%d", work);
	return 0;
}
