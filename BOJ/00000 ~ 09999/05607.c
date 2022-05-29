# include <stdio.h>

int main(void) {
	int n, a, b, A=0, B=0;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &a, &b);
		if(a>b)
			A+=a+b;
		else if(a<b)
			B+=a+b;
		else {
			A+=a;
			B+=b;
		}
	}
	printf("%d %d", A, B);
	return 0;
}
