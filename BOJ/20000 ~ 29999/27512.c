# include <stdio.h>

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	printf("%d", (n*m)%2?n*m-1:n*m);
	return 0;
}