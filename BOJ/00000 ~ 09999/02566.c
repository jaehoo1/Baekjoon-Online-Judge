# include <stdio.h>

int main(void) {
	int num, i, j, x, y, max=-1;
	for(i=0 ; i<9 ; i++)
		for(j=0 ; j<9 ; j++) {
			scanf("%d", &num);
			if(num>max) {
				x=i;
				y=j;
				max=num;
			}
		}
	printf("%d\n%d %d", max, x+1, y+1);
	return 0;
}