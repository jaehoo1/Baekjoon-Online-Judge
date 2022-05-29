# include <stdio.h>

int main(void) {
	int sum=0, num, i;
	for(i=0 ; i<6 ; i++) {
		scanf("%d", &num);
		sum+=num*5;
	}
	printf("%d", sum);
	return 0;
}
