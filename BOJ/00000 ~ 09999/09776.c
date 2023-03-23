# include <stdio.h>
# define	PI	3.14159

int main(void) {
	char figure;
	int n;
	double r, h, V, max=0;
	scanf("%d", &n);
	getchar();
	while(n--) {
		scanf("%c %lf", &figure, &r);
		if(figure=='C') {
			scanf("%lf", &h);
			V=PI*r*r*h/3;
		} else if(figure=='L') {
			scanf("%lf", &h);
			V=PI*r*r*h;
		} else if(figure=='S')
			V=(double)4/3*PI*r*r*r;
		getchar();
		if(V>max)
			max=V;
	}
	printf("%.3lf", max);
	return 0;
}