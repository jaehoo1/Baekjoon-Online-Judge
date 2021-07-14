# include <stdio.h>

int main(void) {
	int a, x, y, res;
	while(scanf("%d", &a)) {
		if(!a)
			return 0;
		res=1;
		while(a--) {
			scanf("%d%d", &x, &y);
			res*=x;
			res-=y;
		}
		printf("%d\n", res);
	}
	return 0;
}
