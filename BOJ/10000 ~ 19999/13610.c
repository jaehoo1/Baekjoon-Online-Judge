# include <stdio.h>

int main(void) {
	int x, y, res=1;
	scanf("%d%d", &x, &y);
	while((y-x)*res<y)
		res++;
	printf("%d", res);
	return 0;
}
