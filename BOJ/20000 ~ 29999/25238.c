# include <stdio.h>

int main(void) {
	int a, b;
	scanf("%d%d", &a, &b);
	if((double)a*(100-b)/100>=100)
		puts("0");
	else
		puts("1");
	return 0;
}