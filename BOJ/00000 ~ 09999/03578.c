# include <stdio.h>

int main(void) {
	int h, i;
	scanf("%d", &h);
	if(!h)
		puts("1");
	else if(h==1)
		puts("0");
	else {
		if(h%2) {
			printf("4");
			h--;
		}
		for(i=0 ; i<h ; i+=2)
			printf("8");
	}
	return 0;
}