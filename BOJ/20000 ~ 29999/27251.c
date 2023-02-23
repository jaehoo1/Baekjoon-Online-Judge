# include <stdio.h>
# define	pow(x)	x*x

int main(void) {
	int n, i, j;
	scanf("%d", &n);
	for(i=1 ; i<=n ; i++) {
		if(pow(i)>100) {
			for(j=0 ; j<100 ; j++)
				printf("*");
			printf("...");
		} else
			for(j=0 ; j<pow(i) ; j++)
				printf("*");
		puts("");
	}
	return 0;
}