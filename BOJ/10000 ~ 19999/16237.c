# include <stdio.h>

int main(void) {
	int A, B, C, D, E, cou;
	scanf("%d%d%d%d%d", &A, &B, &C, &D, &E);
	cou=E;
	while(D--) {
		cou++;
		if(A)
			A--;
	}
	while(C--) {
		cou++;
		if(B)
			B--;
		else if(A>=2)
			A-=2;
		else if(A)
			A--;
	}
	while(B--) {
		cou++;
		if(B&&A) {
			B--;
			A--;
		} else if(A>=3)
			A-=3;
		else if(B)
			B--;
		else if(A>=2)
			A-=2;
		else if(A)
			A--;
	}
	cou+=A/5;
	A%=5;
	if(A%5)
		cou++;
	printf("%d", cou);
	return 0;
}
