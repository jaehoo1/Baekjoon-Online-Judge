# include <stdio.h>
# include <math.h>

int main(void) {
	double X1, Y1, R1, X2, Y2, R2, dist;
	scanf("%lf%lf%lf%lf%lf%lf", &X1, &Y1, &R1, &X2, &Y2, &R2);
	dist=sqrt((X1-X2)*(X1-X2)+(Y1-Y2)*(Y1-Y2));
	if(dist<R1+R2)
		puts("YES");
	else
		puts("NO");
	return 0;
}
