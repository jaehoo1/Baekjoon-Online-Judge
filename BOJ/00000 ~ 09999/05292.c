# include <stdio.h>

int main(void) {
	int coin, i;
	scanf("%d", &coin);
	for(i=1 ; i<=coin ; i++)
		if(i%3==0&&i%5==0)
			puts("DeadMan");
		else if(i%3==0)
			puts("Dead");
		else if(i%5==0)
			puts("Man");
		else
			printf("%d ", i);
	return 0;
}