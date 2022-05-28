# include <stdio.h>

int main(void) {
	int N, i, a, b, star, gold, cnt=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		gold=1;
		scanf("%d%d", &a, &b);
		star=5*a-3*b;
		if(star<=40)
			gold=0;
		if(gold)
			cnt++;
	}
	printf("%d", cnt);
	if(cnt==N)
		puts("+");
	return 0;
}
