# include <stdio.h>

int main(void) {
	int n, X, Y;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &X, &Y);
		puts(X<Y?"NO BRAINS":"MMM BRAINS");
	}
	return 0;
}
