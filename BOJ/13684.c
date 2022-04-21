# include <stdio.h>

int main(void) {
	int K, N, M, X, Y;
	while(scanf("%d", &K)) {
		if(!K)
			break;
		scanf("%d%d", &N, &M);
		while(K--) {
			scanf("%d%d", &X, &Y);
			if(X==N||Y==M)
				puts("divisa");
			else if(X>N&&Y>M)
				puts("NE");
			else if(X<N&&Y>M)
				puts("NO");
			else if(X>N&&Y<M)
				puts("SE");
			else if(X<N&&Y<M)
				puts("SO");
		}
	}
	return 0;
}
