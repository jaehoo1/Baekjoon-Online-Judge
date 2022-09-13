# include <stdio.h>

int main(void) {
	int T, C, coin[4]={25, 10, 5, 1}, i;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &C);
		for(i=0 ; i<4 ; i++) {
			printf("%d ", C/coin[i]);
			C%=coin[i];
		}
		puts("");
	}
	return 0;
}