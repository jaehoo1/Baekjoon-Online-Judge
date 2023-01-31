# include <stdio.h>

int main(void) {
	int T, S;
	scanf("%d%d", &T, &S);
	puts(T>=12&&T<=16&&!S?"320":"280");
	return 0;
}