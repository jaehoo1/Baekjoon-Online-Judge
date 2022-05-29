# include <stdio.h>

int main(void) {
	int x, s;
	scanf("%d%d", &x, &s);
	if(x<s*2)puts("TAK");
	else	puts("NIE");
	return 0;
}
