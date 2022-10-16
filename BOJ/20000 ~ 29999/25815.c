# include <stdio.h>

int main(void) {
	int y, m, Y=0, M=0;
	scanf("%d%d", &y, &m);
	if(y<1)
		M=15*m;
	else if(y<2) {
		Y=15;
		y--;
		M=9*m;
	} else {
		Y=24;
		y-=2;
		Y+=4*y;
		M+=4*m;
	}
	Y+=M/12;
	M%=12;
	printf("%d %d", Y, M);
	return 0;
}