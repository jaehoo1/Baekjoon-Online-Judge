# include <stdio.h>

typedef struct { int h, m, s; }time;

int main(void) {
	time a={0, }, b={0, };
	scanf("%d:%d", &a.h, &a.m);
	b.m=a.h;
	b.s=a.m;
	a.m-=b.m;
	a.s-=b.s;
	if(a.s<0) {
		a.s+=60;
		a.m--;
	}
	if(a.m<0) {
		a.m+=60;
		a.h--;
	}
	printf("%02d:%02d:%02d", a.h, a.m, a.s);
	return 0;
}