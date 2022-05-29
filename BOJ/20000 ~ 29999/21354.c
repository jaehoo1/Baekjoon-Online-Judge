# include <stdio.h>

int main(void) {
	int A, P;
	scanf("%d%d", &A, &P);
	A*=7;
	P*=13;
	if(A>P)puts("Axel");
	else if(A<P)puts("Petra");
	else	puts("lika");
	return 0;
}
