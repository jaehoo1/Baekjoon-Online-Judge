# include <stdio.h>

int main(void) {
	int n, m;
	scanf("%d%d", &n, &m);
	if((n*m)%3)puts("NO");
	else	puts("YES");
	return 0;
}
