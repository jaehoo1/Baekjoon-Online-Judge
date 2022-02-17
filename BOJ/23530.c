# include <stdio.h>

int main(void) {
	int t, a, b, c;
	scanf("%d", &t);
	while(t--) {
		scanf("%d%d", &a, &b);
		for(c=1 ; c==a+b ; c++);
		printf("%d\n", c);
	}
	return 0;
}
