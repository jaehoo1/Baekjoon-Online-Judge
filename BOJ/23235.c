# include <stdio.h>

int main(void) {
	int T=1, N;
	while(scanf("%d", &N)) {
		if(!N)break;
		if(getchar()=='\n')
			printf("Case %d: Sorting... done!\n", T++);
	}
	return 0;
}
