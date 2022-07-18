# include <stdio.h>

int main(void) {
	int n, x, y, a;
	scanf("%d%d%d", &n, &x, &y);
	while(n--) {
		scanf("%d", &a);
		printf("%d\n", (int)((double)a/x*y));
	}
	return 0;
}