# include <stdio.h>

int main(void) {
	int t, s, h, i, j;
	scanf("%d%d%d", &t, &s, &h);
	for(i=0 ; i<t ; i++) {
		printf("*");
		for(j=0 ; j<s ; j++)
			printf(" ");
		printf("*");
		for(j=0 ; j<s ; j++)
			printf(" ");
		puts("*");
	}
	for(i=0 ; i<2*s+3 ; i++)
		printf("*");
	puts("");
	for(i=0 ; i<h ; i++) {
		for(j=0 ; j<s+1 ; j++)
			printf(" ");
		puts("*");
	}
	return 0;
}