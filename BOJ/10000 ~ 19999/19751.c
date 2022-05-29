# include <stdio.h>

int main(void) {
	double a, b, c, d, min, ma, mb, mc, md;
	scanf("%lf%lf%lf%lf", &a, &b, &c, &d);
	min=a/b+c/d;
	ma=a;	mb=b;	mc=c;	md=d;
	if(a/b+d/c<min) {
		min=a/b+d/c;
		ma=a;	mb=b;	mc=d;	md=c;
	}
	if(b/a+c/d<min) {
		min=b/a+c/d;
		ma=b;	mb=a;	mc=c;	md=d;
	}
	if(b/a+d/c<min) {
		min=b/a+d/c;
		ma=b;	mb=a;	mc=d;	md=c;
	}
	if(a/c+b/d<min) {
		min=a/c+b/d;
		ma=a;	mb=c;	mc=b;	md=d;
	}
	if(a/c+d/b<min) {
		min=a/c+d/b;
		ma=a;	mb=c;	mc=d;	md=b;
	}
	if(c/a+b/d<min) {
		min=c/a+b/d;
		ma=c;	mb=a;	mc=b;	md=d;
	}
	if(c/a+d/b<min) {
		min=c/a+d/b;
		ma=c;	mb=a;	mc=d;	md=b;
	}
	if(a/d+b/c<min) {
		min=a/d+b/c;
		ma=a;	mb=d;	mc=b;	md=c;
	}
	if(a/d+c/b<min) {
		min=a/d+c/b;
		ma=a;	mb=d;	mc=c;	md=b;
	}
	if(d/a+b/c<min) {
		min=d/a+b/c;
		ma=d;	mb=a;	mc=b;	md=c;
	}
	if(d/a+c/b<min) {
		min=d/a+c/b;
		ma=d;	mb=a;	mc=c;	md=b;
	}
	printf("%d %d %d %d", (int)ma, (int)mb, (int)mc, (int)md);
	return 0;
}
