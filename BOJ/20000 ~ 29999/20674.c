# include <stdio.h>

int main(void) {
	int n, p, min, sum=0;
	scanf("%d%d", &n, &p);
	n--;
	min=p;
	while(n--) {
		scanf("%d", &p);
		if(p<min)
			min=p;
		else
			sum+=p-min;
	}
	printf("%d", sum);
	return 0;
}