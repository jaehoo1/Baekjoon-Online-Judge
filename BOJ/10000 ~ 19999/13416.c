# include <stdio.h>

int main(void) {
	int T, N, A, max, res, i;
	scanf("%d", &T);
	while(T--) {
		res=0;
		scanf("%d", &N);
		while(N--) {
			max=0;
			for(i=0 ; i<3 ; i++) {
				scanf("%d", &A);
				if(A>max)
					max=A;
			}
			res+=max;
		}
		printf("%d\n", res);
	}
	return 0;
}