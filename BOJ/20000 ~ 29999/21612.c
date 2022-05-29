# include <stdio.h>

int main(void) {
	int P, B;
	scanf("%d", &B);
	P=5*B-400;
	printf("%d\n", P);
	if(P<100)puts("1");
	else if(P>100)puts("-1");
	else	puts("0");
	return 0;
}
