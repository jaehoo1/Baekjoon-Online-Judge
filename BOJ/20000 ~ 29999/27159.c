# include <stdio.h>

int main(void) {
	int N, x[33], i, j, score=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++)
		scanf("%d", &x[i]);
	for(i=0 ; i<N ; i++) {
		score+=x[i];
		for(j=i+1 ; j<N&&x[j-1]+1==x[j] ; j++);
		i=j-1;
	}
	printf("%d", score);
	return 0;
}