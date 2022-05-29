# include <stdio.h>

int main(void) {
	int N, M, X, i, j, flag, cou=0;
	scanf("%d%d", &N, &M);
	for(i=0 ; i<N ; i++) {
		flag=1;
		for(j=0 ; j<M ; j++) {
			scanf("%d", &X);
			if(!X)
				flag=0;
		}
		if(flag)
			cou++;
	}
	printf("%d", cou);
	return 0;
}
