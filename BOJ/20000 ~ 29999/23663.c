# include <stdio.h>

int main(void) {
	int T, n, m, x, i;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &n, &m);
		for(i=0 ; i<n+m ; i++)
			scanf("%d", &x);
		puts(n<=m?"Yes":"No");
	}
	return 0;
}
