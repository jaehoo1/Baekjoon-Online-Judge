# include <stdio.h>

int main(void) {
	int X, Y, P1, P2;
	scanf("%d%d%d%d", &X, &Y, &P1, &P2);
	while(P1!=P2&&P1<=10000&&P2<=10000) {
		if(P1<P2)P1+=X;
		else	P2+=Y;
	}
	if(P1==P2)printf("%d", P1);
	else	puts("-1");
	return 0;
}
