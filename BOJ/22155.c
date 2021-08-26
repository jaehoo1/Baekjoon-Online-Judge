# include <stdio.h>

int main(void) {
	int n, i, f;
	scanf("%d", &n);
	while(n--) {
		scanf("%d%d", &i, &f);
		if((i<=1&&f<=2)||(i<=2&&f<=1))
			puts("Yes");
		else
			puts("No");
	}
	return 0;
}
