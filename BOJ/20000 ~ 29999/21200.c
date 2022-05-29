# include <stdio.h>

int main(void) {
	int N, P, S, m, card, keep;
	scanf("%d%d%d", &N, &P, &S);
	while(S--) {
		keep=0;
		scanf("%d", &m);
		while(m--) {
			scanf("%d", &card);
			if(card==P)
				keep=1;
		}
		puts(keep?"KEEP":"REMOVE");
	}
	return 0;
}
