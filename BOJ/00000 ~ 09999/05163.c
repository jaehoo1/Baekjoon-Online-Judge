# include <stdio.h>
# include <math.h>
# define PI 3.14159265358979323846

int main(void) {
	int K, b, x;
	double w, r, volume;
	scanf("%d", &K);
	for(x=1 ; x<=K ; x++) {
		volume=0;
		scanf("%d%lf", &b, &w);
		while(b--) {
			scanf("%lf", &r);
			volume+=(double)4/3*PI*pow(r, 3);
		}
		printf("Data Set %d:\n", x);
		if(volume>w*1000)
			puts("Yes");
		else
			puts("No");
		puts("");
	}
	return 0;
}
