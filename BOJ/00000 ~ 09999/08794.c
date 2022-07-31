# include <stdio.h>

int main(void) {
	int Z, N, M, L, cou, i, day;
	scanf("%d", &Z);
	while(Z--) {
		cou=0;
		scanf("%d%d%d", &N, &M, &L);
		day=L;
		for(i=0 ; i<N ; i++) {
			if(day==1)
				cou++;
			day++;
			if(day>M)
				day=1;
		}
		printf("%d\n", cou);
	}
	return 0;
}