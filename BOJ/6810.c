# include <stdio.h>

int main(void) {
	int sum=91, a, b, c;
	scanf("%d%d%d", &a, &b, &c);
	sum+=a+b*3+c;
	printf("The 1-3-sum is %d", sum);
	return 0;
}
