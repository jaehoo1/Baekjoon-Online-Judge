# include <stdio.h>

int main(void) {
	int x, y;
	while(scanf("%d%d", &x, &y)) {
		if(!x&&!y)
			break;
		if(x+y==13)
			puts("Never speak again.");
		else if(x>y)
			puts("To the convention.");
		else if(x<y)
			puts("Left beehind.");
		else
			puts("Undecided.");
	}
	return 0;
}
