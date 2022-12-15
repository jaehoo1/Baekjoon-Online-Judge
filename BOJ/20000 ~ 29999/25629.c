# include <stdio.h>

int main(void) {
	int N, a, i, odd=0, even=0;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &a);
		a%2?odd++:even++;
	}
	printf("%d", odd==even||odd==even+1);
	return 0;
}