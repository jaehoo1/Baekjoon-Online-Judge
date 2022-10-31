# include <stdio.h>

int main(void) {
	int N, X, T[100], i;
	scanf("%d%d", &N, &X);
	for(i=0 ; i<N ; i++)
		scanf("%d", &T[i]);
	for(i=0 ; ; i++, X++) {
		if(i>=N)
			i=0;
		if(T[i]<X)
			break;
	}
	printf("%d", i+1);
	return 0;
}