# include <stdio.h>

int main(void) {
	int n, i, j, min=50, x, y;
	scanf("%d", &n);
	for(i=0 ; i<=50 ; i++)
		for(j=0 ; j<=34 ; j++)
			if(2*i+3*j==n&&i+j<min) {
				min=i+j;
				x=i;
				y=j;
			}
	printf("%d %d", x, y);
	return 0;
}