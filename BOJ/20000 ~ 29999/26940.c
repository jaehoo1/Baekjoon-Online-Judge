# include <stdio.h>

int main(void) {
	int N, num, pre=100, res=0, i;
	scanf("%d", &N);
	for(i=0 ; i<N ; i++) {
		scanf("%d", &num);
		if(num>pre)
			res++;
		pre=num;
	}
	printf("%d", res);
	return 0;
}