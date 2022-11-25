# include <stdio.h>

int main(void) {
	int N, a, d, g, score, max=0;
	scanf("%d", &N);
	while(N--) {
		scanf("%d%d%d", &a, &d, &g);
		score=a*(d+g);
		if(a==(d+g))
			score*=2;
		if(score>max)
			max=score;
	}
	printf("%d", max);
	return 0;
}