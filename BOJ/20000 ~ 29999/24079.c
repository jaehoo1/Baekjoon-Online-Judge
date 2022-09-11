# include <stdio.h>

int main(void) {
	int X, Y, Z;
	scanf("%d%d%d", &X, &Y, &Z);
	puts(X+Y<=Z?"1":"0");
	return 0;
}