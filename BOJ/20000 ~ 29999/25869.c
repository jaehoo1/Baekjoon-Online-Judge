# include <stdio.h>

int main(void) {
	int w, h, d, res;
	scanf("%d%d%d", &w, &h, &d);
	res=(w-2*d)*(h-2*d);
	if(w-2*d<0||h-2*d<0) {
		puts("0");
		return 0;
	}
	printf("%d", res);
	return 0;
}