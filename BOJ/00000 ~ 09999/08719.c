# include <stdio.h>

int main(void) {
	int t, x, w, cou;
	scanf("%d", &t);
	while(t--) {
		cou=0;
		scanf("%d%d", &x, &w);
		while(x<w) {
			x*=2;
			cou++;
		}
		printf("%d\n", cou);
	}
	return 0;
}
