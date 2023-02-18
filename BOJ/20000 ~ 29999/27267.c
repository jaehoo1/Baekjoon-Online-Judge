# include <stdio.h>

int main(void) {
	int a, b, c, d;
	scanf("%d%d%d%d", &a, &b, &c, &d);
	if(a*b>c*d)
		puts("M");
	else if(a*b<c*d)
		puts("P");
	else
		puts("E");
	return 0;
}