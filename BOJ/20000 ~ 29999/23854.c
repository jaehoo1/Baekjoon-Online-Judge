# include <stdio.h>

int main(void) {
	int a, b, awin, bwin;
	scanf("%d%d", &a, &b);
	awin=a/3;
	a%=3;
	bwin=b/3;
	b%=3;
	if(a!=b) {
		puts("-1");
		return 0;
	}
	printf("%d %d %d", awin, a, bwin);
	return 0;
}
