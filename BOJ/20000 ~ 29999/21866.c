# include <stdio.h>

int main(void) {
	int num, i, hack=0, sum=0;
	for(i=0 ; i<9 ; i++) {
		scanf("%d", &num);
		if(num>(i/2+1)*100)
			hack=1;
		sum+=num;
	}
	if(hack)puts("hacker");
	else if(sum>=100)puts("draw");
	else	puts("none");
	return 0;
}
