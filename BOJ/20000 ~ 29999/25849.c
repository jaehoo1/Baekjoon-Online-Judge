# include <stdio.h>

int main(void) {
	int N, unit[6]={1, 5, 10, 20, 50, 100}, num, max=0, res, i;
	for(i=0 ; i<6 ; i++) {
		scanf("%d", &num);
		if(num*unit[i]>=max) {
			max=num*unit[i];
			res=unit[i];
		}
	}
	printf("%d", res);
	return 0;
}