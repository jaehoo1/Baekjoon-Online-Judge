# include <stdio.h>
# define	min(a, b)	a<b?a:b

int main(void) {
	int N, M, left[61], right[61], i, pair;
	char L;
	while(~scanf("%d", &N)) {
		pair=0;
		for(i=30 ; i<=60 ; i++) {
			left[i]=0;
			right[i]=0;
		}
		while(N--) {
			scanf("%d %c", &M, &L);
			if(L=='D')
				right[M]++;
			else if(L=='E')
				left[M]++;
		}
		for(i=30 ; i<=60 ; i++)
			pair+=min(left[i], right[i]);
		printf("%d\n", pair);
	}
	return 0;
}