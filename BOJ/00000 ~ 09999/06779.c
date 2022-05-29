# include <stdio.h>

int power(const int x, int n) {
	int temp=1;
	while(n--)
		temp*=x;
	return temp;
}

int main(void) {
	int h, M, i;
	scanf("%d%d", &h, &M);
	for(i=1 ; i<=M ; i++)
		if(-6*power(i, 4)+h*power(i, 3)+2*power(i, 2)+i<=0) {
			printf("The balloon first touches ground at hour: %d", i);
			return 0;
		}
	puts("The balloon does not touch ground in the given time.");
	return 0;
}
