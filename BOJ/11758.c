# include <stdio.h>

int main(void) {
	int x1, y1, x2, y2, x3, y3, a, b;
	scanf("%d%d%d%d%d%d", &x1, &y1, &x2, &y2, &x3, &y3);
	a=x1*y2+x2*y3+x3*y1;
	b=x2*y1+x3*y2+x1*y3;
	if(a-b>0)puts("1");
	else if(a-b<0)puts("-1");
	else	puts("0");
	return 0;
}
