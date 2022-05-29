# include <stdio.h>

int main(void) {
	int N, i, j, min=100, A, B;
	scanf("%d", &N);
	for(i=1 ; i<=100 ; i++)
		for(j=1 ; j<=100 ; j++)
			if(i*j>=N&&i+j<min) {
				min=i+j;
				A=i;
				B=j;
			}
	printf("%d %d", A, B);
	return 0;
}
