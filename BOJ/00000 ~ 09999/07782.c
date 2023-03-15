# include <stdio.h>

int main(void) {
	int n, b1, b2, lx, ly, hx, hy;
	scanf("%d%d%d", &n, &b1, &b2);
	while(n--) {
		scanf("%d%d%d%d", &lx, &ly, &hx, &hy);
		if(b1>=lx&&b1<=hx&&b2>=ly&&b2<=hy) {
			puts("Yes");
			return 0;
		}
	}
	puts("No");
	return 0;
}