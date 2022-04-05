# include <stdio.h>

int main(void) {
	int n, h=0, block=0;
	scanf("%d", &n);
	while(block<=n) {
		block+=h*h+(h+1)*(h+1);
		h++;
	}
	printf("%d", h-1);
	return 0;
}
