# include <stdio.h>

int main(void) {
	int z, a, b;
	scanf("%d", &z);
	while(z--) {
		scanf("%d%d", &a, &b);
		if(b%a)puts("NIE");
		else	puts("TAK");
	}
	return 0;
}
