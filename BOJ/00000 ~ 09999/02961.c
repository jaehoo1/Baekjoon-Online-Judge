# include <stdio.h>
# include <math.h>

int sours[10], bitters[10], N, min=1000000000;

void recur(int depth, int sour, int bitter, int count) {
	if(count&&abs(sour-bitter)<min)
		min=abs(sour-bitter);
	if(depth==N)
		return;
	recur(depth+1, sour*sours[depth], bitter+bitters[depth], count+1);
	recur(depth+1, sour, bitter, count);
}

int main(void) {
	int i;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d%d", &sours[i], &bitters[i]);
	recur(0, 1, 0, 0);
	printf("%d", min);
	return 0;
}