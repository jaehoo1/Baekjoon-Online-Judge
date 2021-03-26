# include <stdio.h>

int main(void) {
	int N;
	scanf("%d", &N);
	if(N%2)puts("Either");
	else if((N/2)%2)puts("Odd");
	else	puts("Even");
	return 0;
}
