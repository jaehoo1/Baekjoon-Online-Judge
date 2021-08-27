# include <stdio.h>

int main(void) {
	int t, N, A, B;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &N);
		A=N/100;	B=N%100;
		if((A*A+B*B)%7==1)
			puts("YES");
		else
			puts("NO");
	}
	return 0;
}
