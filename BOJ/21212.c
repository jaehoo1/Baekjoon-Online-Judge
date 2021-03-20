# include <stdio.h>

int main(void) {
	int N, i, A, B, temp, min=10000;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d%d", &A, &B);
		temp=B/A;
		if(temp<min)
			min=temp;
	}
	printf("%d", min);
	return 0;
}
