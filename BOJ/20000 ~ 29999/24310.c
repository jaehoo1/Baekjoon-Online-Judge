# include <stdio.h>

int swap(int *a, int *b) {
	int temp=*a;
	*a=*b;
	*b=temp;
}
int max(int a, int b) { return a>b?a:b; }
int min(int a, int b) { return a<b?a:b; }

int main(void) {
	int A, B, C, D;
	scanf("%d%d%d%d", &A, &B, &C, &D);
	if(A>B)swap(&A, &B);
	if(C>D)swap(&C, &D);
	if((C>=A&&C<=B)||(A>=C&&A<=D))
		printf("%d", max(B, D)-min(A, C)+1);
	else
		printf("%d", B-A+D-C+2);
	return 0;
}
