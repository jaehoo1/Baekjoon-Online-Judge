# include <stdio.h>

int main(void) {
	int x, y, r;
	scanf("%d%d%d", &x, &y, &r);
	printf("%d %d\n", x+r, y+r);
	printf("%d %d\n", x+r, y-r);
	printf("%d %d\n", x-r, y-r);
	printf("%d %d\n", x-r, y+r);
	return 0;
}
