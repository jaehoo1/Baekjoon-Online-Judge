# include <stdio.h>

void swap(double *a, double *b) {
	double temp=*a;
	*a=*b;
	*b=temp;
}

int main(void) {
	double h, w;
	scanf("%lf%lf", &h, &w);
	if(w>h)
		swap(&w, &h);
	if(h>=3*w)
		printf("%.4lf", w);
	else if(h>=1.5*w)
		printf("%.4lf", h/3);
	else
		printf("%.4lf", w/2);
	return 0;
}
