# include <stdio.h>
# include <math.h>

int main(void) {
	int N, i, x, y, x2, y2, sum=0;
	scanf("%d%d%d", &N, &x, &y);
	for(i=1 ; i<N ; i++) {
		scanf("%d%d", &x2, &y2);
		sum+=abs(x2-x)+abs(y2-y);
		x=x2;
		y=y2;
	}
	printf("%d", sum);
	return 0;
}
