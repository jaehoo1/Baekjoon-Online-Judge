# include <stdio.h>

int main(void) {
	int x, k, a, K=0, A, i;
	scanf("%d%d%d", &x, &k, &a);
	A=x;
	for(i=0 ; K<=A ; i++)
		if(i%2)
			A-=a;
		else
			K+=k;
	printf("%d", i%2);
	return 0;
}