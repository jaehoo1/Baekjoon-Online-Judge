# include <stdio.h>

int main(void) {
	int N, i, start=1, end=2, sum=1, cou=0;
	scanf("%d", &N);
	while(start<=N) {
		if(sum==N)
			cou++;
		if(sum>=N)
			sum-=start++;
		else
			sum+=end++;
	}
	printf("%d", cou);
	return 0;
}
