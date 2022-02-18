# include <stdio.h>
# define	INT_MAX	2147483647

int main(void) {
	int N, B, H, W, p, a, i, min=INT_MAX;
	scanf("%d%d%d%d", &N, &B, &H, &W);
	while(H--) {
		scanf("%d", &p);
		for(i=0 ; i<W ; i++) {
			scanf("%d", &a);
			if(a>=N&&p*N<=B&&p*N<min)
				min=p*N;
		}
	}
	if(min==INT_MAX)
		puts("stay home");
	else
		printf("%d", min);
	return 0;
}
