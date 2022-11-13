# include <stdio.h>

int main(void) {
	int S, A, B, money=250;
	scanf("%d%d%d", &S, &A, &B);
	for( ; A<S ; A+=B)
		money+=100;
	printf("%d", money);
	return 0;
}