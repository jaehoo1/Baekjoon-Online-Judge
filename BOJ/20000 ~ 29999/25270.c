# include <stdio.h>
# include <math.h>

int main(void) {
	int N, i, res, min=10000;
	scanf("%d", &N);
	for(i=99 ; i<=10000 ; i+=100)
		if(abs(N-i)<=min) {
			min=abs(N-i);
			res=i;
		}
	printf("%d", res);
	return 0;
}