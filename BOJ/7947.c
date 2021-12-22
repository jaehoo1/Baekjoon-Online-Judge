# include <stdio.h>
# include <math.h>

int main(void) {
	int T, r, g, b, i;
	double R, G, B;
	scanf("%d", &T);
	while(T--) {
		R=G=B=0;
		for(i=0 ; i<10 ; i++) {
			scanf("%d%d%d", &r, &g, &b);
			R+=r;
			G+=g;
			B+=b;
		}
		printf("%.0lf %.0lf %.0lf\n", round(R/10), round(G/10), round(B/10));
	}
	return 0;
}
