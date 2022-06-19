# include <stdio.h>

int main(void) {
	int n, m, k, i;
	while(scanf("%d%d%d", &n, &m, &k)) {
		if(!n&&!m&&!k)
			break;
		if(n-k>n/2) {
			for(i=0 ; m+i<=n/2 ; i++);
			printf("%d\n", i);
		} else
			puts("-1");
	}
	return 0;
}